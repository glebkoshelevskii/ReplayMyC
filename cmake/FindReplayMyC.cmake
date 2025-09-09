# FindReplayMyC.cmake
# 
# Find the ReplayMyC code generation tools
#
# This module defines:
#  REPLAYMYC_FOUND - True if ReplayMyC tools are found
#  REPLAYMYC_GENERATE_XML - Path to generate_xml.py
#  REPLAYMYC_GENERATE_C - Path to generate_c.py
#  REPLAYMYC_ROOT_DIR - Root directory of ReplayMyC
#
# And provides the function:
#  replaymyc_generate_tracing_code(
#    API_NAME <name>
#    HEADER_FILE <path>
#    OUTPUT_DIR <dir>
#  )

find_path(REPLAYMYC_ROOT_DIR
    NAMES generate_xml.py generate_c.py trace.h
    PATHS
        ${CMAKE_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/../..
        ${CMAKE_INSTALL_PREFIX}/tools
        /usr/local/tools
        /opt/replaymyc
    DOC "ReplayMyC root directory"
)

if(REPLAYMYC_ROOT_DIR)
    set(REPLAYMYC_GENERATE_XML "${REPLAYMYC_ROOT_DIR}/generate_xml.py")
    set(REPLAYMYC_GENERATE_C "${REPLAYMYC_ROOT_DIR}/generate_c.py")
    
    # Check if files exist
    if(EXISTS "${REPLAYMYC_GENERATE_XML}" AND EXISTS "${REPLAYMYC_GENERATE_C}")
        set(REPLAYMYC_FOUND TRUE)
    endif()
endif()

# Function to generate tracing code from C header
function(replaymyc_generate_tracing_code)
    set(options "")
    set(oneValueArgs API_NAME HEADER_FILE OUTPUT_DIR)
    set(multiValueArgs "")
    cmake_parse_arguments(ARGS "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})
    
    if(NOT ARGS_API_NAME)
        message(FATAL_ERROR "API_NAME is required")
    endif()
    
    if(NOT ARGS_HEADER_FILE)
        message(FATAL_ERROR "HEADER_FILE is required") 
    endif()
    
    if(NOT ARGS_OUTPUT_DIR)
        set(ARGS_OUTPUT_DIR ${CMAKE_CURRENT_BINARY_DIR})
    endif()
    
    if(NOT REPLAYMYC_FOUND)
        message(FATAL_ERROR "ReplayMyC tools not found")
    endif()
    
    # Get absolute paths
    get_filename_component(HEADER_ABS "${ARGS_HEADER_FILE}" ABSOLUTE)
    get_filename_component(OUTPUT_ABS "${ARGS_OUTPUT_DIR}" ABSOLUTE)
    
    # XML generation
    set(XML_FILE "${OUTPUT_ABS}/${ARGS_API_NAME}.xml")
    add_custom_command(
        OUTPUT "${XML_FILE}"
        COMMAND ${CMAKE_COMMAND} -E make_directory "${OUTPUT_ABS}"
        COMMAND python3 "${REPLAYMYC_GENERATE_XML}" "${HEADER_ABS}" -o "${XML_FILE}" -n "${ARGS_API_NAME}"
        DEPENDS "${HEADER_ABS}" "${REPLAYMYC_GENERATE_XML}"
        COMMENT "Generating ${ARGS_API_NAME}.xml from ${ARGS_HEADER_FILE}"
        VERBATIM
    )
    
    # C++ code generation
    set(GENERATED_FILES
        "${OUTPUT_ABS}/${ARGS_API_NAME}_serialization.h"
        "${OUTPUT_ABS}/${ARGS_API_NAME}_serialization.cpp"
        "${OUTPUT_ABS}/${ARGS_API_NAME}_deserialization.h"
        "${OUTPUT_ABS}/${ARGS_API_NAME}_deserialization.cpp"
        "${OUTPUT_ABS}/${ARGS_API_NAME}_init.cpp"
    )
    
    add_custom_command(
        OUTPUT ${GENERATED_FILES}
        COMMAND python3 "${REPLAYMYC_GENERATE_C}" "${XML_FILE}"
        DEPENDS "${XML_FILE}" "${REPLAYMYC_GENERATE_C}"
        WORKING_DIRECTORY "${OUTPUT_ABS}"
        COMMENT "Generating C++ tracing code for ${ARGS_API_NAME}"
        VERBATIM
    )
    
    # Create a target for the generated files
    add_custom_target(${ARGS_API_NAME}_tracing_code
        DEPENDS ${GENERATED_FILES}
    )
    
    # Set variables for parent scope
    set(${ARGS_API_NAME}_TRACING_SOURCES ${GENERATED_FILES} PARENT_SCOPE)
    set(${ARGS_API_NAME}_XML_FILE ${XML_FILE} PARENT_SCOPE)
endfunction()

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(ReplayMyC
    REQUIRED_VARS REPLAYMYC_ROOT_DIR REPLAYMYC_GENERATE_XML REPLAYMYC_GENERATE_C
)