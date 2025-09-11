#pragma once


#include <stdint.h>
#include <stdbool.h>

typedef enum {
    TMC_MODE_CAPTURE,
    TMC_MODE_REPLAY
} rmc_mode_t;

typedef struct {
    bool is_valid;
    const char* description;
} rmc_result_t;

typedef struct {
    rmc_mode_t mode;
    const char* filename;
} rmc_config_t;

rmc_result_t rmc_init(rmc_mode_t mode, const char* filename);
rmc_result_t rmc_deinit(void);
rmc_result_t rmc_start_tracing(void);
rmc_result_t rmc_end_tracing(void);
rmc_result_t rmc_replay_trace(void);
