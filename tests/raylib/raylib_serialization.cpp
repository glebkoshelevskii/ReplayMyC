#include "raylib_serialization.h"

void serialize_Vector2(const Vector2& s) {
    serialize_le(s.x);
    serialize_le(s.y);
}

void serialize_Vector3(const Vector3& s) {
    serialize_le(s.x);
    serialize_le(s.y);
    serialize_le(s.z);
}

void serialize_Vector4(const Vector4& s) {
    serialize_le(s.x);
    serialize_le(s.y);
    serialize_le(s.z);
    serialize_le(s.w);
}

void serialize_Matrix(const Matrix& s) {
    serialize_le(s.m0);
    serialize_le(s.m4);
    serialize_le(s.m8);
    serialize_le(s.m12);
    serialize_le(s.m1);
    serialize_le(s.m5);
    serialize_le(s.m9);
    serialize_le(s.m13);
    serialize_le(s.m2);
    serialize_le(s.m6);
    serialize_le(s.m10);
    serialize_le(s.m14);
    serialize_le(s.m3);
    serialize_le(s.m7);
    serialize_le(s.m11);
    serialize_le(s.m15);
}

void serialize_Color(const Color& s) {
    serialize_le(s.r);
    serialize_le(s.g);
    serialize_le(s.b);
    serialize_le(s.a);
}

void serialize_Rectangle(const Rectangle& s) {
    serialize_le(s.x);
    serialize_le(s.y);
    serialize_le(s.width);
    serialize_le(s.height);
}

void serialize_Image(const Image& s) {
    // Skipping data (type: void*) - not serializable
    serialize_le(s.width);
    serialize_le(s.height);
    serialize_le(s.mipmaps);
    serialize_le(s.format);
}

void serialize_Texture(const Texture& s) {
    serialize_le(s.id);
    serialize_le(s.width);
    serialize_le(s.height);
    serialize_le(s.mipmaps);
    serialize_le(s.format);
}

void serialize_RenderTexture(const RenderTexture& s) {
    serialize_le(s.id);
    serialize_Texture(s.texture);
    serialize_Texture(s.depth);
}

void serialize_NPatchInfo(const NPatchInfo& s) {
    serialize_Rectangle(s.source);
    serialize_le(s.left);
    serialize_le(s.top);
    serialize_le(s.right);
    serialize_le(s.bottom);
    serialize_le(s.layout);
}

void serialize_GlyphInfo(const GlyphInfo& s) {
    serialize_le(s.value);
    serialize_le(s.offsetX);
    serialize_le(s.offsetY);
    serialize_le(s.advanceX);
    serialize_Image(s.image);
}

void serialize_Font(const Font& s) {
    serialize_le(s.baseSize);
    serialize_le(s.glyphCount);
    serialize_le(s.glyphPadding);
    serialize_le(s.texture);
    serialize_le(1 /* TODO: Specify length for recs */);
    for(int i = 0; i < 1 /* TODO: Specify length for recs */; i++) { 
        serialize_Rectangle(s.recs[i]);
    }
    serialize_le(1 /* TODO: Specify length for glyphs */);
    for(int i = 0; i < 1 /* TODO: Specify length for glyphs */; i++) { 
        serialize_GlyphInfo(s.glyphs[i]);
    }
}

void serialize_Camera3D(const Camera3D& s) {
    serialize_Vector3(s.position);
    serialize_Vector3(s.target);
    serialize_Vector3(s.up);
    serialize_le(s.fovy);
    serialize_le(s.projection);
}

void serialize_Camera2D(const Camera2D& s) {
    serialize_Vector2(s.offset);
    serialize_Vector2(s.target);
    serialize_le(s.rotation);
    serialize_le(s.zoom);
}

void serialize_Mesh(const Mesh& s) {
    serialize_le(s.vertexCount);
    serialize_le(s.triangleCount);
    serialize_le(1 /* TODO: Specify length for vertices */);
    for(int i = 0; i < 1 /* TODO: Specify length for vertices */; i++) { 
        serialize_le(s.vertices[i]);
    }
    serialize_le(1 /* TODO: Specify length for texcoords */);
    for(int i = 0; i < 1 /* TODO: Specify length for texcoords */; i++) { 
        serialize_le(s.texcoords[i]);
    }
    serialize_le(1 /* TODO: Specify length for texcoords2 */);
    for(int i = 0; i < 1 /* TODO: Specify length for texcoords2 */; i++) { 
        serialize_le(s.texcoords2[i]);
    }
    serialize_le(1 /* TODO: Specify length for normals */);
    for(int i = 0; i < 1 /* TODO: Specify length for normals */; i++) { 
        serialize_le(s.normals[i]);
    }
    serialize_le(1 /* TODO: Specify length for tangents */);
    for(int i = 0; i < 1 /* TODO: Specify length for tangents */; i++) { 
        serialize_le(s.tangents[i]);
    }
    serialize_le(1 /* TODO: Specify length for colors */);
    for(int i = 0; i < 1 /* TODO: Specify length for colors */; i++) { 
        serialize_le(s.colors[i]);
    }
    serialize_le(1 /* TODO: Specify length for indices */);
    for(int i = 0; i < 1 /* TODO: Specify length for indices */; i++) { 
        serialize_le(s.indices[i]);
    }
    serialize_le(1 /* TODO: Specify length for animVertices */);
    for(int i = 0; i < 1 /* TODO: Specify length for animVertices */; i++) { 
        serialize_le(s.animVertices[i]);
    }
    serialize_le(1 /* TODO: Specify length for animNormals */);
    for(int i = 0; i < 1 /* TODO: Specify length for animNormals */; i++) { 
        serialize_le(s.animNormals[i]);
    }
    serialize_le(1 /* TODO: Specify length for boneIds */);
    for(int i = 0; i < 1 /* TODO: Specify length for boneIds */; i++) { 
        serialize_le(s.boneIds[i]);
    }
    serialize_le(1 /* TODO: Specify length for boneWeights */);
    for(int i = 0; i < 1 /* TODO: Specify length for boneWeights */; i++) { 
        serialize_le(s.boneWeights[i]);
    }
    serialize_le(1 /* TODO: Specify length for boneMatrices */);
    for(int i = 0; i < 1 /* TODO: Specify length for boneMatrices */; i++) { 
        serialize_Matrix(s.boneMatrices[i]);
    }
    serialize_le(s.boneCount);
    serialize_le(s.vaoId);
    serialize_le(1 /* TODO: Specify length for vboId */);
    for(int i = 0; i < 1 /* TODO: Specify length for vboId */; i++) { 
        serialize_le(s.vboId[i]);
    }
}

void serialize_Shader(const Shader& s) {
    serialize_le(s.id);
    serialize_le(1 /* TODO: Specify length for locs */);
    for(int i = 0; i < 1 /* TODO: Specify length for locs */; i++) { 
        serialize_le(s.locs[i]);
    }
}

void serialize_MaterialMap(const MaterialMap& s) {
    serialize_le(s.texture);
    serialize_Color(s.color);
    serialize_le(s.value);
}

void serialize_Material(const Material& s) {
    serialize_Shader(s.shader);
    serialize_le(1 /* TODO: Specify length for maps */);
    for(int i = 0; i < 1 /* TODO: Specify length for maps */; i++) { 
        serialize_MaterialMap(s.maps[i]);
    }
    for(int i = 0; i < 4; i++) { 
        serialize_le(s.params[i]);
    }
}

void serialize_Transform(const Transform& s) {
    serialize_Vector3(s.translation);
    serialize_le(s.rotation);
    serialize_Vector3(s.scale);
}

void serialize_BoneInfo(const BoneInfo& s) {
    for(int i = 0; i < 32; i++) { 
        serialize_le(s.name[i]);
    }
    serialize_le(s.parent);
}

void serialize_Model(const Model& s) {
    serialize_Matrix(s.transform);
    serialize_le(s.meshCount);
    serialize_le(s.materialCount);
    serialize_le(1 /* TODO: Specify length for meshes */);
    for(int i = 0; i < 1 /* TODO: Specify length for meshes */; i++) { 
        serialize_Mesh(s.meshes[i]);
    }
    serialize_le(1 /* TODO: Specify length for materials */);
    for(int i = 0; i < 1 /* TODO: Specify length for materials */; i++) { 
        serialize_Material(s.materials[i]);
    }
    serialize_le(1 /* TODO: Specify length for meshMaterial */);
    for(int i = 0; i < 1 /* TODO: Specify length for meshMaterial */; i++) { 
        serialize_le(s.meshMaterial[i]);
    }
    serialize_le(s.boneCount);
    serialize_le(1 /* TODO: Specify length for bones */);
    for(int i = 0; i < 1 /* TODO: Specify length for bones */; i++) { 
        serialize_BoneInfo(s.bones[i]);
    }
    serialize_le(1 /* TODO: Specify length for bindPose */);
    for(int i = 0; i < 1 /* TODO: Specify length for bindPose */; i++) { 
        serialize_Transform(s.bindPose[i]);
    }
}

void serialize_ModelAnimation(const ModelAnimation& s) {
    serialize_le(s.boneCount);
    serialize_le(s.frameCount);
    serialize_le(1 /* TODO: Specify length for bones */);
    for(int i = 0; i < 1 /* TODO: Specify length for bones */; i++) { 
        serialize_BoneInfo(s.bones[i]);
    }
    for(int i = 0; i < 32; i++) { 
        serialize_le(s.name[i]);
    }
}

void serialize_Ray(const Ray& s) {
    serialize_Vector3(s.position);
    serialize_Vector3(s.direction);
}

void serialize_RayCollision(const RayCollision& s) {
    serialize_le(s.hit);
    serialize_le(s.distance);
    serialize_Vector3(s.point);
    serialize_Vector3(s.normal);
}

void serialize_BoundingBox(const BoundingBox& s) {
    serialize_Vector3(s.min);
    serialize_Vector3(s.max);
}

void serialize_Wave(const Wave& s) {
    serialize_le(s.frameCount);
    serialize_le(s.sampleRate);
    serialize_le(s.sampleSize);
    serialize_le(s.channels);
    // Skipping data (type: void*) - not serializable
}

void serialize_AudioStream(const AudioStream& s) {
    // Skipping buffer (type: rAudioBuffer*) - not serializable
    // Skipping processor (type: rAudioProcessor*) - not serializable
    serialize_le(s.sampleRate);
    serialize_le(s.sampleSize);
    serialize_le(s.channels);
}

void serialize_Sound(const Sound& s) {
    serialize_AudioStream(s.stream);
    serialize_le(s.frameCount);
}

void serialize_Music(const Music& s) {
    serialize_AudioStream(s.stream);
    serialize_le(s.frameCount);
    serialize_le(s.looping);
    serialize_le(s.ctxType);
    // Skipping ctxData (type: void*) - not serializable
}

void serialize_VrDeviceInfo(const VrDeviceInfo& s) {
    serialize_le(s.hResolution);
    serialize_le(s.vResolution);
    serialize_le(s.hScreenSize);
    serialize_le(s.vScreenSize);
    serialize_le(s.eyeToScreenDistance);
    serialize_le(s.lensSeparationDistance);
    serialize_le(s.interpupillaryDistance);
    for(int i = 0; i < 4; i++) { 
        serialize_le(s.lensDistortionValues[i]);
    }
    for(int i = 0; i < 4; i++) { 
        serialize_le(s.chromaAbCorrection[i]);
    }
}

void serialize_VrStereoConfig(const VrStereoConfig& s) {
    for(int i = 0; i < 2; i++) { 
        serialize_Matrix(s.projection[i]);
    }
    for(int i = 0; i < 2; i++) { 
        serialize_Matrix(s.viewOffset[i]);
    }
    for(int i = 0; i < 2; i++) { 
        serialize_le(s.leftLensCenter[i]);
    }
    for(int i = 0; i < 2; i++) { 
        serialize_le(s.rightLensCenter[i]);
    }
    for(int i = 0; i < 2; i++) { 
        serialize_le(s.leftScreenCenter[i]);
    }
    for(int i = 0; i < 2; i++) { 
        serialize_le(s.rightScreenCenter[i]);
    }
    for(int i = 0; i < 2; i++) { 
        serialize_le(s.scale[i]);
    }
    for(int i = 0; i < 2; i++) { 
        serialize_le(s.scaleIn[i]);
    }
}

void serialize_FilePathList(const FilePathList& s) {
    serialize_le(s.capacity);
    serialize_le(s.count);
}

void serialize_AutomationEvent(const AutomationEvent& s) {
    serialize_le(s.frame);
    serialize_le(s.type);
    for(int i = 0; i < 4; i++) { 
        serialize_le(s.params[i]);
    }
}

void serialize_AutomationEventList(const AutomationEventList& s) {
    serialize_le(s.capacity);
    serialize_le(s.count);
    serialize_le(s.count);
    for(int i = 0; i < s.count; i++) { 
        serialize_AutomationEvent(s.events[i]);
    }
}

void serialize_InitWindow(int width, int height, const char* title) {
    rmc_start_function_trace(2, 0);
    serialize_le(width);
    serialize_le(height);
    int length_title = strlen(title) + 1;
    serialize_le(length_title);
    for(int i = 0; i < length_title; i++) {
        serialize_le(title[i]);
    }
    rmc_end_function_trace();
}

void serialize_CloseWindow() {
    rmc_start_function_trace(2, 1);
    rmc_end_function_trace();
}

void serialize_WindowShouldClose() {
    rmc_start_function_trace(2, 2);
    rmc_end_function_trace();
}

void serialize_IsWindowReady() {
    rmc_start_function_trace(2, 3);
    rmc_end_function_trace();
}

void serialize_IsWindowFullscreen() {
    rmc_start_function_trace(2, 4);
    rmc_end_function_trace();
}

void serialize_IsWindowHidden() {
    rmc_start_function_trace(2, 5);
    rmc_end_function_trace();
}

void serialize_IsWindowMinimized() {
    rmc_start_function_trace(2, 6);
    rmc_end_function_trace();
}

void serialize_IsWindowMaximized() {
    rmc_start_function_trace(2, 7);
    rmc_end_function_trace();
}

void serialize_IsWindowFocused() {
    rmc_start_function_trace(2, 8);
    rmc_end_function_trace();
}

void serialize_IsWindowResized() {
    rmc_start_function_trace(2, 9);
    rmc_end_function_trace();
}

void serialize_IsWindowState(unsigned int flag) {
    rmc_start_function_trace(2, 10);
    serialize_le(flag);
    rmc_end_function_trace();
}

void serialize_SetWindowState(unsigned int flags) {
    rmc_start_function_trace(2, 11);
    serialize_le(flags);
    rmc_end_function_trace();
}

void serialize_ClearWindowState(unsigned int flags) {
    rmc_start_function_trace(2, 12);
    serialize_le(flags);
    rmc_end_function_trace();
}

void serialize_ToggleFullscreen() {
    rmc_start_function_trace(2, 13);
    rmc_end_function_trace();
}

void serialize_ToggleBorderlessWindowed() {
    rmc_start_function_trace(2, 14);
    rmc_end_function_trace();
}

void serialize_MaximizeWindow() {
    rmc_start_function_trace(2, 15);
    rmc_end_function_trace();
}

void serialize_MinimizeWindow() {
    rmc_start_function_trace(2, 16);
    rmc_end_function_trace();
}

void serialize_RestoreWindow() {
    rmc_start_function_trace(2, 17);
    rmc_end_function_trace();
}

void serialize_SetWindowIcon(const Image& image) {
    rmc_start_function_trace(2, 18);
    serialize_Image(image);
    rmc_end_function_trace();
}

void serialize_SetWindowIcons(const Image* images, int count) {
    rmc_start_function_trace(2, 19);
    int length_images = count;
    serialize_le(length_images);
    for(int i = 0; i < length_images; i++) {
        serialize_Image(images[i]);
    }
    serialize_le(count);
    rmc_end_function_trace();
}

void serialize_SetWindowTitle(const char* title) {
    rmc_start_function_trace(2, 20);
    int length_title = strlen(title) + 1;
    serialize_le(length_title);
    for(int i = 0; i < length_title; i++) {
        serialize_le(title[i]);
    }
    rmc_end_function_trace();
}

void serialize_SetWindowPosition(int x, int y) {
    rmc_start_function_trace(2, 21);
    serialize_le(x);
    serialize_le(y);
    rmc_end_function_trace();
}

void serialize_SetWindowMonitor(int monitor) {
    rmc_start_function_trace(2, 22);
    serialize_le(monitor);
    rmc_end_function_trace();
}

void serialize_SetWindowMinSize(int width, int height) {
    rmc_start_function_trace(2, 23);
    serialize_le(width);
    serialize_le(height);
    rmc_end_function_trace();
}

void serialize_SetWindowMaxSize(int width, int height) {
    rmc_start_function_trace(2, 24);
    serialize_le(width);
    serialize_le(height);
    rmc_end_function_trace();
}

void serialize_SetWindowSize(int width, int height) {
    rmc_start_function_trace(2, 25);
    serialize_le(width);
    serialize_le(height);
    rmc_end_function_trace();
}

void serialize_SetWindowOpacity(float opacity) {
    rmc_start_function_trace(2, 26);
    serialize_le(opacity);
    rmc_end_function_trace();
}

void serialize_SetWindowFocused() {
    rmc_start_function_trace(2, 27);
    rmc_end_function_trace();
}

void serialize_GetScreenWidth() {
    rmc_start_function_trace(2, 28);
    rmc_end_function_trace();
}

void serialize_GetScreenHeight() {
    rmc_start_function_trace(2, 29);
    rmc_end_function_trace();
}

void serialize_GetRenderWidth() {
    rmc_start_function_trace(2, 30);
    rmc_end_function_trace();
}

void serialize_GetRenderHeight() {
    rmc_start_function_trace(2, 31);
    rmc_end_function_trace();
}

void serialize_GetMonitorCount() {
    rmc_start_function_trace(2, 32);
    rmc_end_function_trace();
}

void serialize_GetCurrentMonitor() {
    rmc_start_function_trace(2, 33);
    rmc_end_function_trace();
}

void serialize_GetMonitorPosition(int monitor) {
    rmc_start_function_trace(2, 34);
    serialize_le(monitor);
    rmc_end_function_trace();
}

void serialize_GetMonitorWidth(int monitor) {
    rmc_start_function_trace(2, 35);
    serialize_le(monitor);
    rmc_end_function_trace();
}

void serialize_GetMonitorHeight(int monitor) {
    rmc_start_function_trace(2, 36);
    serialize_le(monitor);
    rmc_end_function_trace();
}

void serialize_GetMonitorPhysicalWidth(int monitor) {
    rmc_start_function_trace(2, 37);
    serialize_le(monitor);
    rmc_end_function_trace();
}

void serialize_GetMonitorPhysicalHeight(int monitor) {
    rmc_start_function_trace(2, 38);
    serialize_le(monitor);
    rmc_end_function_trace();
}

void serialize_GetMonitorRefreshRate(int monitor) {
    rmc_start_function_trace(2, 39);
    serialize_le(monitor);
    rmc_end_function_trace();
}

void serialize_GetWindowPosition() {
    rmc_start_function_trace(2, 40);
    rmc_end_function_trace();
}

void serialize_GetWindowScaleDPI() {
    rmc_start_function_trace(2, 41);
    rmc_end_function_trace();
}

void serialize_SetClipboardText(const char* text) {
    rmc_start_function_trace(2, 42);
    int length_text = strlen(text) + 1;
    serialize_le(length_text);
    for(int i = 0; i < length_text; i++) {
        serialize_le(text[i]);
    }
    rmc_end_function_trace();
}

void serialize_GetClipboardImage() {
    rmc_start_function_trace(2, 43);
    rmc_end_function_trace();
}

void serialize_EnableEventWaiting() {
    rmc_start_function_trace(2, 44);
    rmc_end_function_trace();
}

void serialize_DisableEventWaiting() {
    rmc_start_function_trace(2, 45);
    rmc_end_function_trace();
}

void serialize_ShowCursor() {
    rmc_start_function_trace(2, 46);
    rmc_end_function_trace();
}

void serialize_HideCursor() {
    rmc_start_function_trace(2, 47);
    rmc_end_function_trace();
}

void serialize_IsCursorHidden() {
    rmc_start_function_trace(2, 48);
    rmc_end_function_trace();
}

void serialize_EnableCursor() {
    rmc_start_function_trace(2, 49);
    rmc_end_function_trace();
}

void serialize_DisableCursor() {
    rmc_start_function_trace(2, 50);
    rmc_end_function_trace();
}

void serialize_IsCursorOnScreen() {
    rmc_start_function_trace(2, 51);
    rmc_end_function_trace();
}

void serialize_ClearBackground(const Color& color) {
    rmc_start_function_trace(2, 52);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_BeginDrawing() {
    rmc_start_function_trace(2, 53);
    rmc_end_function_trace();
}

void serialize_EndDrawing() {
    rmc_start_function_trace(2, 54);
    rmc_end_function_trace();
}

void serialize_BeginMode2D(const Camera2D& camera) {
    rmc_start_function_trace(2, 55);
    serialize_Camera2D(camera);
    rmc_end_function_trace();
}

void serialize_EndMode2D() {
    rmc_start_function_trace(2, 56);
    rmc_end_function_trace();
}

void serialize_BeginMode3D(const Camera3D& camera) {
    rmc_start_function_trace(2, 57);
    serialize_Camera3D(camera);
    rmc_end_function_trace();
}

void serialize_EndMode3D() {
    rmc_start_function_trace(2, 58);
    rmc_end_function_trace();
}

void serialize_BeginTextureMode(RenderTexture2D target) {
    rmc_start_function_trace(2, 59);
    serialize_le(target);
    rmc_end_function_trace();
}

void serialize_EndTextureMode() {
    rmc_start_function_trace(2, 60);
    rmc_end_function_trace();
}

void serialize_BeginShaderMode(const Shader& shader) {
    rmc_start_function_trace(2, 61);
    serialize_Shader(shader);
    rmc_end_function_trace();
}

void serialize_EndShaderMode() {
    rmc_start_function_trace(2, 62);
    rmc_end_function_trace();
}

void serialize_BeginBlendMode(int mode) {
    rmc_start_function_trace(2, 63);
    serialize_le(mode);
    rmc_end_function_trace();
}

void serialize_EndBlendMode() {
    rmc_start_function_trace(2, 64);
    rmc_end_function_trace();
}

void serialize_BeginScissorMode(int x, int y, int width, int height) {
    rmc_start_function_trace(2, 65);
    serialize_le(x);
    serialize_le(y);
    serialize_le(width);
    serialize_le(height);
    rmc_end_function_trace();
}

void serialize_EndScissorMode() {
    rmc_start_function_trace(2, 66);
    rmc_end_function_trace();
}

void serialize_BeginVrStereoMode(const VrStereoConfig& config) {
    rmc_start_function_trace(2, 67);
    serialize_VrStereoConfig(config);
    rmc_end_function_trace();
}

void serialize_EndVrStereoMode() {
    rmc_start_function_trace(2, 68);
    rmc_end_function_trace();
}

void serialize_LoadVrStereoConfig(const VrDeviceInfo& device) {
    rmc_start_function_trace(2, 69);
    serialize_VrDeviceInfo(device);
    rmc_end_function_trace();
}

void serialize_UnloadVrStereoConfig(const VrStereoConfig& config) {
    rmc_start_function_trace(2, 70);
    serialize_VrStereoConfig(config);
    rmc_end_function_trace();
}

void serialize_LoadShader(const char* vsFileName, const char* fsFileName) {
    rmc_start_function_trace(2, 71);
    int length_vsFileName = strlen(vsFileName) + 1;
    serialize_le(length_vsFileName);
    for(int i = 0; i < length_vsFileName; i++) {
        serialize_le(vsFileName[i]);
    }
    int length_fsFileName = strlen(fsFileName) + 1;
    serialize_le(length_fsFileName);
    for(int i = 0; i < length_fsFileName; i++) {
        serialize_le(fsFileName[i]);
    }
    rmc_end_function_trace();
}

void serialize_LoadShaderFromMemory(const char* vsCode, const char* fsCode) {
    rmc_start_function_trace(2, 72);
    int length_vsCode = strlen(vsCode) + 1;
    serialize_le(length_vsCode);
    for(int i = 0; i < length_vsCode; i++) {
        serialize_le(vsCode[i]);
    }
    int length_fsCode = strlen(fsCode) + 1;
    serialize_le(length_fsCode);
    for(int i = 0; i < length_fsCode; i++) {
        serialize_le(fsCode[i]);
    }
    rmc_end_function_trace();
}

void serialize_IsShaderValid(const Shader& shader) {
    rmc_start_function_trace(2, 73);
    serialize_Shader(shader);
    rmc_end_function_trace();
}

void serialize_GetShaderLocation(const Shader& shader, const char* uniformName) {
    rmc_start_function_trace(2, 74);
    serialize_Shader(shader);
    int length_uniformName = strlen(uniformName) + 1;
    serialize_le(length_uniformName);
    for(int i = 0; i < length_uniformName; i++) {
        serialize_le(uniformName[i]);
    }
    rmc_end_function_trace();
}

void serialize_GetShaderLocationAttrib(const Shader& shader, const char* attribName) {
    rmc_start_function_trace(2, 75);
    serialize_Shader(shader);
    int length_attribName = strlen(attribName) + 1;
    serialize_le(length_attribName);
    for(int i = 0; i < length_attribName; i++) {
        serialize_le(attribName[i]);
    }
    rmc_end_function_trace();
}

void serialize_SetShaderValue(const Shader& shader, int locIndex, const void* value, int uniformType) {
    rmc_start_function_trace(2, 76);
    serialize_Shader(shader);
    serialize_le(locIndex);
    // Skipping value (type: const void*) - not serializable
    serialize_le(uniformType);
    rmc_end_function_trace();
}

void serialize_SetShaderValueV(const Shader& shader, int locIndex, const void* value, int uniformType, int count) {
    rmc_start_function_trace(2, 77);
    serialize_Shader(shader);
    serialize_le(locIndex);
    // Skipping value (type: const void*) - not serializable
    serialize_le(uniformType);
    serialize_le(count);
    rmc_end_function_trace();
}

void serialize_SetShaderValueMatrix(const Shader& shader, int locIndex, const Matrix& mat) {
    rmc_start_function_trace(2, 78);
    serialize_Shader(shader);
    serialize_le(locIndex);
    serialize_Matrix(mat);
    rmc_end_function_trace();
}

void serialize_SetShaderValueTexture(const Shader& shader, int locIndex, Texture2D texture) {
    rmc_start_function_trace(2, 79);
    serialize_Shader(shader);
    serialize_le(locIndex);
    serialize_le(texture);
    rmc_end_function_trace();
}

void serialize_UnloadShader(const Shader& shader) {
    rmc_start_function_trace(2, 80);
    serialize_Shader(shader);
    rmc_end_function_trace();
}

void serialize_GetScreenToWorldRay(const Vector2& position, Camera camera) {
    rmc_start_function_trace(2, 81);
    serialize_Vector2(position);
    serialize_le(camera);
    rmc_end_function_trace();
}

void serialize_GetScreenToWorldRayEx(const Vector2& position, Camera camera, int width, int height) {
    rmc_start_function_trace(2, 82);
    serialize_Vector2(position);
    serialize_le(camera);
    serialize_le(width);
    serialize_le(height);
    rmc_end_function_trace();
}

void serialize_GetWorldToScreen(const Vector3& position, Camera camera) {
    rmc_start_function_trace(2, 83);
    serialize_Vector3(position);
    serialize_le(camera);
    rmc_end_function_trace();
}

void serialize_GetWorldToScreenEx(const Vector3& position, Camera camera, int width, int height) {
    rmc_start_function_trace(2, 84);
    serialize_Vector3(position);
    serialize_le(camera);
    serialize_le(width);
    serialize_le(height);
    rmc_end_function_trace();
}

void serialize_GetWorldToScreen2D(const Vector2& position, const Camera2D& camera) {
    rmc_start_function_trace(2, 85);
    serialize_Vector2(position);
    serialize_Camera2D(camera);
    rmc_end_function_trace();
}

void serialize_GetScreenToWorld2D(const Vector2& position, const Camera2D& camera) {
    rmc_start_function_trace(2, 86);
    serialize_Vector2(position);
    serialize_Camera2D(camera);
    rmc_end_function_trace();
}

void serialize_GetCameraMatrix(Camera camera) {
    rmc_start_function_trace(2, 87);
    serialize_le(camera);
    rmc_end_function_trace();
}

void serialize_GetCameraMatrix2D(const Camera2D& camera) {
    rmc_start_function_trace(2, 88);
    serialize_Camera2D(camera);
    rmc_end_function_trace();
}

void serialize_SetTargetFPS(int fps) {
    rmc_start_function_trace(2, 89);
    serialize_le(fps);
    rmc_end_function_trace();
}

void serialize_GetFrameTime() {
    rmc_start_function_trace(2, 90);
    rmc_end_function_trace();
}

void serialize_GetTime() {
    rmc_start_function_trace(2, 91);
    rmc_end_function_trace();
}

void serialize_GetFPS() {
    rmc_start_function_trace(2, 92);
    rmc_end_function_trace();
}

void serialize_SwapScreenBuffer() {
    rmc_start_function_trace(2, 93);
    rmc_end_function_trace();
}

void serialize_PollInputEvents() {
    rmc_start_function_trace(2, 94);
    rmc_end_function_trace();
}

void serialize_WaitTime(double seconds) {
    rmc_start_function_trace(2, 95);
    serialize_le(seconds);
    rmc_end_function_trace();
}

void serialize_SetRandomSeed(unsigned int seed) {
    rmc_start_function_trace(2, 96);
    serialize_le(seed);
    rmc_end_function_trace();
}

void serialize_GetRandomValue(int min, int max) {
    rmc_start_function_trace(2, 97);
    serialize_le(min);
    serialize_le(max);
    rmc_end_function_trace();
}

void serialize_UnloadRandomSequence(const int* sequence) {
    rmc_start_function_trace(2, 98);
    int length_sequence = 1 /* TODO: Specify length for sequence */;
    serialize_le(length_sequence);
    for(int i = 0; i < length_sequence; i++) {
        serialize_le(sequence[i]);
    }
    rmc_end_function_trace();
}

void serialize_TakeScreenshot(const char* fileName) {
    rmc_start_function_trace(2, 99);
    int length_fileName = strlen(fileName) + 1;
    serialize_le(length_fileName);
    for(int i = 0; i < length_fileName; i++) {
        serialize_le(fileName[i]);
    }
    rmc_end_function_trace();
}

void serialize_SetConfigFlags(unsigned int flags) {
    rmc_start_function_trace(2, 100);
    serialize_le(flags);
    rmc_end_function_trace();
}

void serialize_OpenURL(const char* url) {
    rmc_start_function_trace(2, 101);
    int length_url = strlen(url) + 1;
    serialize_le(length_url);
    for(int i = 0; i < length_url; i++) {
        serialize_le(url[i]);
    }
    rmc_end_function_trace();
}

void serialize_TraceLog(int logLevel, const char* text) {
    rmc_start_function_trace(2, 102);
    serialize_le(logLevel);
    int length_text = strlen(text) + 1;
    serialize_le(length_text);
    for(int i = 0; i < length_text; i++) {
        serialize_le(text[i]);
    }
    rmc_end_function_trace();
}

void serialize_SetTraceLogLevel(int logLevel) {
    rmc_start_function_trace(2, 103);
    serialize_le(logLevel);
    rmc_end_function_trace();
}

void serialize_MemFree(const void* ptr) {
    rmc_start_function_trace(2, 104);
    // Skipping ptr (type: void*) - not serializable
    rmc_end_function_trace();
}

void serialize_SetTraceLogCallback(TraceLogCallback callback) {
    rmc_start_function_trace(2, 105);
    serialize_le(callback);
    rmc_end_function_trace();
}

void serialize_SetLoadFileDataCallback(LoadFileDataCallback callback) {
    rmc_start_function_trace(2, 106);
    serialize_le(callback);
    rmc_end_function_trace();
}

void serialize_SetSaveFileDataCallback(SaveFileDataCallback callback) {
    rmc_start_function_trace(2, 107);
    serialize_le(callback);
    rmc_end_function_trace();
}

void serialize_SetLoadFileTextCallback(LoadFileTextCallback callback) {
    rmc_start_function_trace(2, 108);
    serialize_le(callback);
    rmc_end_function_trace();
}

void serialize_SetSaveFileTextCallback(SaveFileTextCallback callback) {
    rmc_start_function_trace(2, 109);
    serialize_le(callback);
    rmc_end_function_trace();
}

void serialize_UnloadFileData(const unsigned char* data) {
    rmc_start_function_trace(2, 110);
    int length_data = 1 /* TODO: Specify length for data */;
    serialize_le(length_data);
    for(int i = 0; i < length_data; i++) {
        serialize_le(data[i]);
    }
    rmc_end_function_trace();
}

void serialize_SaveFileData(const char* fileName, const void* data, int dataSize) {
    rmc_start_function_trace(2, 111);
    int length_fileName = strlen(fileName) + 1;
    serialize_le(length_fileName);
    for(int i = 0; i < length_fileName; i++) {
        serialize_le(fileName[i]);
    }
    // Skipping data (type: void*) - not serializable
    serialize_le(dataSize);
    rmc_end_function_trace();
}

void serialize_ExportDataAsCode(const unsigned char* data, int dataSize, const char* fileName) {
    rmc_start_function_trace(2, 112);
    int length_data = 1 /* TODO: Specify length for data */;
    serialize_le(length_data);
    for(int i = 0; i < length_data; i++) {
        serialize_le(data[i]);
    }
    serialize_le(dataSize);
    int length_fileName = strlen(fileName) + 1;
    serialize_le(length_fileName);
    for(int i = 0; i < length_fileName; i++) {
        serialize_le(fileName[i]);
    }
    rmc_end_function_trace();
}

void serialize_UnloadFileText(const char* text) {
    rmc_start_function_trace(2, 113);
    int length_text = strlen(text) + 1;
    serialize_le(length_text);
    for(int i = 0; i < length_text; i++) {
        serialize_le(text[i]);
    }
    rmc_end_function_trace();
}

void serialize_SaveFileText(const char* fileName, const char* text) {
    rmc_start_function_trace(2, 114);
    int length_fileName = strlen(fileName) + 1;
    serialize_le(length_fileName);
    for(int i = 0; i < length_fileName; i++) {
        serialize_le(fileName[i]);
    }
    int length_text = strlen(text) + 1;
    serialize_le(length_text);
    for(int i = 0; i < length_text; i++) {
        serialize_le(text[i]);
    }
    rmc_end_function_trace();
}

void serialize_FileExists(const char* fileName) {
    rmc_start_function_trace(2, 115);
    int length_fileName = strlen(fileName) + 1;
    serialize_le(length_fileName);
    for(int i = 0; i < length_fileName; i++) {
        serialize_le(fileName[i]);
    }
    rmc_end_function_trace();
}

void serialize_DirectoryExists(const char* dirPath) {
    rmc_start_function_trace(2, 116);
    int length_dirPath = strlen(dirPath) + 1;
    serialize_le(length_dirPath);
    for(int i = 0; i < length_dirPath; i++) {
        serialize_le(dirPath[i]);
    }
    rmc_end_function_trace();
}

void serialize_IsFileExtension(const char* fileName, const char* ext) {
    rmc_start_function_trace(2, 117);
    int length_fileName = strlen(fileName) + 1;
    serialize_le(length_fileName);
    for(int i = 0; i < length_fileName; i++) {
        serialize_le(fileName[i]);
    }
    int length_ext = strlen(ext) + 1;
    serialize_le(length_ext);
    for(int i = 0; i < length_ext; i++) {
        serialize_le(ext[i]);
    }
    rmc_end_function_trace();
}

void serialize_GetFileLength(const char* fileName) {
    rmc_start_function_trace(2, 118);
    int length_fileName = strlen(fileName) + 1;
    serialize_le(length_fileName);
    for(int i = 0; i < length_fileName; i++) {
        serialize_le(fileName[i]);
    }
    rmc_end_function_trace();
}

void serialize_MakeDirectory(const char* dirPath) {
    rmc_start_function_trace(2, 119);
    int length_dirPath = strlen(dirPath) + 1;
    serialize_le(length_dirPath);
    for(int i = 0; i < length_dirPath; i++) {
        serialize_le(dirPath[i]);
    }
    rmc_end_function_trace();
}

void serialize_ChangeDirectory(const char* dir) {
    rmc_start_function_trace(2, 120);
    int length_dir = strlen(dir) + 1;
    serialize_le(length_dir);
    for(int i = 0; i < length_dir; i++) {
        serialize_le(dir[i]);
    }
    rmc_end_function_trace();
}

void serialize_IsPathFile(const char* path) {
    rmc_start_function_trace(2, 121);
    int length_path = strlen(path) + 1;
    serialize_le(length_path);
    for(int i = 0; i < length_path; i++) {
        serialize_le(path[i]);
    }
    rmc_end_function_trace();
}

void serialize_IsFileNameValid(const char* fileName) {
    rmc_start_function_trace(2, 122);
    int length_fileName = strlen(fileName) + 1;
    serialize_le(length_fileName);
    for(int i = 0; i < length_fileName; i++) {
        serialize_le(fileName[i]);
    }
    rmc_end_function_trace();
}

void serialize_LoadDirectoryFiles(const char* dirPath) {
    rmc_start_function_trace(2, 123);
    int length_dirPath = strlen(dirPath) + 1;
    serialize_le(length_dirPath);
    for(int i = 0; i < length_dirPath; i++) {
        serialize_le(dirPath[i]);
    }
    rmc_end_function_trace();
}

void serialize_LoadDirectoryFilesEx(const char* basePath, const char* filter, bool scanSubdirs) {
    rmc_start_function_trace(2, 124);
    int length_basePath = strlen(basePath) + 1;
    serialize_le(length_basePath);
    for(int i = 0; i < length_basePath; i++) {
        serialize_le(basePath[i]);
    }
    int length_filter = strlen(filter) + 1;
    serialize_le(length_filter);
    for(int i = 0; i < length_filter; i++) {
        serialize_le(filter[i]);
    }
    serialize_le(scanSubdirs);
    rmc_end_function_trace();
}

void serialize_UnloadDirectoryFiles(const FilePathList& files) {
    rmc_start_function_trace(2, 125);
    serialize_FilePathList(files);
    rmc_end_function_trace();
}

void serialize_IsFileDropped() {
    rmc_start_function_trace(2, 126);
    rmc_end_function_trace();
}

void serialize_LoadDroppedFiles() {
    rmc_start_function_trace(2, 127);
    rmc_end_function_trace();
}

void serialize_UnloadDroppedFiles(const FilePathList& files) {
    rmc_start_function_trace(2, 128);
    serialize_FilePathList(files);
    rmc_end_function_trace();
}

void serialize_GetFileModTime(const char* fileName) {
    rmc_start_function_trace(2, 129);
    int length_fileName = strlen(fileName) + 1;
    serialize_le(length_fileName);
    for(int i = 0; i < length_fileName; i++) {
        serialize_le(fileName[i]);
    }
    rmc_end_function_trace();
}

void serialize_ComputeCRC32(const unsigned char* data, int dataSize) {
    rmc_start_function_trace(2, 130);
    int length_data = 1 /* TODO: Specify length for data */;
    serialize_le(length_data);
    for(int i = 0; i < length_data; i++) {
        serialize_le(data[i]);
    }
    serialize_le(dataSize);
    rmc_end_function_trace();
}

void serialize_LoadAutomationEventList(const char* fileName) {
    rmc_start_function_trace(2, 131);
    int length_fileName = strlen(fileName) + 1;
    serialize_le(length_fileName);
    for(int i = 0; i < length_fileName; i++) {
        serialize_le(fileName[i]);
    }
    rmc_end_function_trace();
}

void serialize_UnloadAutomationEventList(const AutomationEventList& list) {
    rmc_start_function_trace(2, 132);
    serialize_AutomationEventList(list);
    rmc_end_function_trace();
}

void serialize_ExportAutomationEventList(const AutomationEventList& list, const char* fileName) {
    rmc_start_function_trace(2, 133);
    serialize_AutomationEventList(list);
    int length_fileName = strlen(fileName) + 1;
    serialize_le(length_fileName);
    for(int i = 0; i < length_fileName; i++) {
        serialize_le(fileName[i]);
    }
    rmc_end_function_trace();
}

void serialize_SetAutomationEventList(const AutomationEventList* list) {
    rmc_start_function_trace(2, 134);
    int length_list = 1 /* TODO: Specify length for list */;
    serialize_le(length_list);
    for(int i = 0; i < length_list; i++) {
        serialize_AutomationEventList(list[i]);
    }
    rmc_end_function_trace();
}

void serialize_SetAutomationEventBaseFrame(int frame) {
    rmc_start_function_trace(2, 135);
    serialize_le(frame);
    rmc_end_function_trace();
}

void serialize_StartAutomationEventRecording() {
    rmc_start_function_trace(2, 136);
    rmc_end_function_trace();
}

void serialize_StopAutomationEventRecording() {
    rmc_start_function_trace(2, 137);
    rmc_end_function_trace();
}

void serialize_PlayAutomationEvent(const AutomationEvent& event) {
    rmc_start_function_trace(2, 138);
    serialize_AutomationEvent(event);
    rmc_end_function_trace();
}

void serialize_IsKeyPressed(int key) {
    rmc_start_function_trace(2, 139);
    serialize_le(key);
    rmc_end_function_trace();
}

void serialize_IsKeyPressedRepeat(int key) {
    rmc_start_function_trace(2, 140);
    serialize_le(key);
    rmc_end_function_trace();
}

void serialize_IsKeyDown(int key) {
    rmc_start_function_trace(2, 141);
    serialize_le(key);
    rmc_end_function_trace();
}

void serialize_IsKeyReleased(int key) {
    rmc_start_function_trace(2, 142);
    serialize_le(key);
    rmc_end_function_trace();
}

void serialize_IsKeyUp(int key) {
    rmc_start_function_trace(2, 143);
    serialize_le(key);
    rmc_end_function_trace();
}

void serialize_GetKeyPressed() {
    rmc_start_function_trace(2, 144);
    rmc_end_function_trace();
}

void serialize_GetCharPressed() {
    rmc_start_function_trace(2, 145);
    rmc_end_function_trace();
}

void serialize_SetExitKey(int key) {
    rmc_start_function_trace(2, 146);
    serialize_le(key);
    rmc_end_function_trace();
}

void serialize_IsGamepadAvailable(int gamepad) {
    rmc_start_function_trace(2, 147);
    serialize_le(gamepad);
    rmc_end_function_trace();
}

void serialize_IsGamepadButtonPressed(int gamepad, int button) {
    rmc_start_function_trace(2, 148);
    serialize_le(gamepad);
    serialize_le(button);
    rmc_end_function_trace();
}

void serialize_IsGamepadButtonDown(int gamepad, int button) {
    rmc_start_function_trace(2, 149);
    serialize_le(gamepad);
    serialize_le(button);
    rmc_end_function_trace();
}

void serialize_IsGamepadButtonReleased(int gamepad, int button) {
    rmc_start_function_trace(2, 150);
    serialize_le(gamepad);
    serialize_le(button);
    rmc_end_function_trace();
}

void serialize_IsGamepadButtonUp(int gamepad, int button) {
    rmc_start_function_trace(2, 151);
    serialize_le(gamepad);
    serialize_le(button);
    rmc_end_function_trace();
}

void serialize_GetGamepadButtonPressed() {
    rmc_start_function_trace(2, 152);
    rmc_end_function_trace();
}

void serialize_GetGamepadAxisCount(int gamepad) {
    rmc_start_function_trace(2, 153);
    serialize_le(gamepad);
    rmc_end_function_trace();
}

void serialize_GetGamepadAxisMovement(int gamepad, int axis) {
    rmc_start_function_trace(2, 154);
    serialize_le(gamepad);
    serialize_le(axis);
    rmc_end_function_trace();
}

void serialize_SetGamepadMappings(const char* mappings) {
    rmc_start_function_trace(2, 155);
    int length_mappings = strlen(mappings) + 1;
    serialize_le(length_mappings);
    for(int i = 0; i < length_mappings; i++) {
        serialize_le(mappings[i]);
    }
    rmc_end_function_trace();
}

void serialize_SetGamepadVibration(int gamepad, float leftMotor, float rightMotor, float duration) {
    rmc_start_function_trace(2, 156);
    serialize_le(gamepad);
    serialize_le(leftMotor);
    serialize_le(rightMotor);
    serialize_le(duration);
    rmc_end_function_trace();
}

void serialize_IsMouseButtonPressed(int button) {
    rmc_start_function_trace(2, 157);
    serialize_le(button);
    rmc_end_function_trace();
}

void serialize_IsMouseButtonDown(int button) {
    rmc_start_function_trace(2, 158);
    serialize_le(button);
    rmc_end_function_trace();
}

void serialize_IsMouseButtonReleased(int button) {
    rmc_start_function_trace(2, 159);
    serialize_le(button);
    rmc_end_function_trace();
}

void serialize_IsMouseButtonUp(int button) {
    rmc_start_function_trace(2, 160);
    serialize_le(button);
    rmc_end_function_trace();
}

void serialize_GetMouseX() {
    rmc_start_function_trace(2, 161);
    rmc_end_function_trace();
}

void serialize_GetMouseY() {
    rmc_start_function_trace(2, 162);
    rmc_end_function_trace();
}

void serialize_GetMousePosition() {
    rmc_start_function_trace(2, 163);
    rmc_end_function_trace();
}

void serialize_GetMouseDelta() {
    rmc_start_function_trace(2, 164);
    rmc_end_function_trace();
}

void serialize_SetMousePosition(int x, int y) {
    rmc_start_function_trace(2, 165);
    serialize_le(x);
    serialize_le(y);
    rmc_end_function_trace();
}

void serialize_SetMouseOffset(int offsetX, int offsetY) {
    rmc_start_function_trace(2, 166);
    serialize_le(offsetX);
    serialize_le(offsetY);
    rmc_end_function_trace();
}

void serialize_SetMouseScale(float scaleX, float scaleY) {
    rmc_start_function_trace(2, 167);
    serialize_le(scaleX);
    serialize_le(scaleY);
    rmc_end_function_trace();
}

void serialize_GetMouseWheelMove() {
    rmc_start_function_trace(2, 168);
    rmc_end_function_trace();
}

void serialize_GetMouseWheelMoveV() {
    rmc_start_function_trace(2, 169);
    rmc_end_function_trace();
}

void serialize_SetMouseCursor(int cursor) {
    rmc_start_function_trace(2, 170);
    serialize_le(cursor);
    rmc_end_function_trace();
}

void serialize_GetTouchX() {
    rmc_start_function_trace(2, 171);
    rmc_end_function_trace();
}

void serialize_GetTouchY() {
    rmc_start_function_trace(2, 172);
    rmc_end_function_trace();
}

void serialize_GetTouchPosition(int index) {
    rmc_start_function_trace(2, 173);
    serialize_le(index);
    rmc_end_function_trace();
}

void serialize_GetTouchPointId(int index) {
    rmc_start_function_trace(2, 174);
    serialize_le(index);
    rmc_end_function_trace();
}

void serialize_GetTouchPointCount() {
    rmc_start_function_trace(2, 175);
    rmc_end_function_trace();
}

void serialize_SetGesturesEnabled(unsigned int flags) {
    rmc_start_function_trace(2, 176);
    serialize_le(flags);
    rmc_end_function_trace();
}

void serialize_IsGestureDetected(unsigned int gesture) {
    rmc_start_function_trace(2, 177);
    serialize_le(gesture);
    rmc_end_function_trace();
}

void serialize_GetGestureDetected() {
    rmc_start_function_trace(2, 178);
    rmc_end_function_trace();
}

void serialize_GetGestureHoldDuration() {
    rmc_start_function_trace(2, 179);
    rmc_end_function_trace();
}

void serialize_GetGestureDragVector() {
    rmc_start_function_trace(2, 180);
    rmc_end_function_trace();
}

void serialize_GetGestureDragAngle() {
    rmc_start_function_trace(2, 181);
    rmc_end_function_trace();
}

void serialize_GetGesturePinchVector() {
    rmc_start_function_trace(2, 182);
    rmc_end_function_trace();
}

void serialize_GetGesturePinchAngle() {
    rmc_start_function_trace(2, 183);
    rmc_end_function_trace();
}

void serialize_UpdateCamera(const Camera* camera, int mode) {
    rmc_start_function_trace(2, 184);
    int length_camera = 1 /* TODO: Specify length for camera */;
    serialize_le(length_camera);
    for(int i = 0; i < length_camera; i++) {
        serialize_le(camera[i]);
    }
    serialize_le(mode);
    rmc_end_function_trace();
}

void serialize_UpdateCameraPro(const Camera* camera, const Vector3& movement, const Vector3& rotation, float zoom) {
    rmc_start_function_trace(2, 185);
    int length_camera = 1 /* TODO: Specify length for camera */;
    serialize_le(length_camera);
    for(int i = 0; i < length_camera; i++) {
        serialize_le(camera[i]);
    }
    serialize_Vector3(movement);
    serialize_Vector3(rotation);
    serialize_le(zoom);
    rmc_end_function_trace();
}

void serialize_SetShapesTexture(Texture2D texture, const Rectangle& source) {
    rmc_start_function_trace(2, 186);
    serialize_le(texture);
    serialize_Rectangle(source);
    rmc_end_function_trace();
}

void serialize_GetShapesTexture() {
    rmc_start_function_trace(2, 187);
    rmc_end_function_trace();
}

void serialize_GetShapesTextureRectangle() {
    rmc_start_function_trace(2, 188);
    rmc_end_function_trace();
}

void serialize_DrawPixel(int posX, int posY, const Color& color) {
    rmc_start_function_trace(2, 189);
    serialize_le(posX);
    serialize_le(posY);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawPixelV(const Vector2& position, const Color& color) {
    rmc_start_function_trace(2, 190);
    serialize_Vector2(position);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawLine(int startPosX, int startPosY, int endPosX, int endPosY, const Color& color) {
    rmc_start_function_trace(2, 191);
    serialize_le(startPosX);
    serialize_le(startPosY);
    serialize_le(endPosX);
    serialize_le(endPosY);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawLineV(const Vector2& startPos, const Vector2& endPos, const Color& color) {
    rmc_start_function_trace(2, 192);
    serialize_Vector2(startPos);
    serialize_Vector2(endPos);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawLineEx(const Vector2& startPos, const Vector2& endPos, float thick, const Color& color) {
    rmc_start_function_trace(2, 193);
    serialize_Vector2(startPos);
    serialize_Vector2(endPos);
    serialize_le(thick);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawLineStrip(const Vector2* points, int pointCount, const Color& color) {
    rmc_start_function_trace(2, 194);
    int length_points = 1 /* TODO: Specify length for points */;
    serialize_le(length_points);
    for(int i = 0; i < length_points; i++) {
        serialize_Vector2(points[i]);
    }
    serialize_le(pointCount);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawLineBezier(const Vector2& startPos, const Vector2& endPos, float thick, const Color& color) {
    rmc_start_function_trace(2, 195);
    serialize_Vector2(startPos);
    serialize_Vector2(endPos);
    serialize_le(thick);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawCircle(int centerX, int centerY, float radius, const Color& color) {
    rmc_start_function_trace(2, 196);
    serialize_le(centerX);
    serialize_le(centerY);
    serialize_le(radius);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawCircleSector(const Vector2& center, float radius, float startAngle, float endAngle, int segments, const Color& color) {
    rmc_start_function_trace(2, 197);
    serialize_Vector2(center);
    serialize_le(radius);
    serialize_le(startAngle);
    serialize_le(endAngle);
    serialize_le(segments);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawCircleSectorLines(const Vector2& center, float radius, float startAngle, float endAngle, int segments, const Color& color) {
    rmc_start_function_trace(2, 198);
    serialize_Vector2(center);
    serialize_le(radius);
    serialize_le(startAngle);
    serialize_le(endAngle);
    serialize_le(segments);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawCircleGradient(int centerX, int centerY, float radius, const Color& inner, const Color& outer) {
    rmc_start_function_trace(2, 199);
    serialize_le(centerX);
    serialize_le(centerY);
    serialize_le(radius);
    serialize_Color(inner);
    serialize_Color(outer);
    rmc_end_function_trace();
}

void serialize_DrawCircleV(const Vector2& center, float radius, const Color& color) {
    rmc_start_function_trace(2, 200);
    serialize_Vector2(center);
    serialize_le(radius);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawCircleLines(int centerX, int centerY, float radius, const Color& color) {
    rmc_start_function_trace(2, 201);
    serialize_le(centerX);
    serialize_le(centerY);
    serialize_le(radius);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawCircleLinesV(const Vector2& center, float radius, const Color& color) {
    rmc_start_function_trace(2, 202);
    serialize_Vector2(center);
    serialize_le(radius);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawEllipse(int centerX, int centerY, float radiusH, float radiusV, const Color& color) {
    rmc_start_function_trace(2, 203);
    serialize_le(centerX);
    serialize_le(centerY);
    serialize_le(radiusH);
    serialize_le(radiusV);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawEllipseV(const Vector2& center, float radiusH, float radiusV, const Color& color) {
    rmc_start_function_trace(2, 204);
    serialize_Vector2(center);
    serialize_le(radiusH);
    serialize_le(radiusV);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawEllipseLines(int centerX, int centerY, float radiusH, float radiusV, const Color& color) {
    rmc_start_function_trace(2, 205);
    serialize_le(centerX);
    serialize_le(centerY);
    serialize_le(radiusH);
    serialize_le(radiusV);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawEllipseLinesV(const Vector2& center, float radiusH, float radiusV, const Color& color) {
    rmc_start_function_trace(2, 206);
    serialize_Vector2(center);
    serialize_le(radiusH);
    serialize_le(radiusV);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawRing(const Vector2& center, float innerRadius, float outerRadius, float startAngle, float endAngle, int segments, const Color& color) {
    rmc_start_function_trace(2, 207);
    serialize_Vector2(center);
    serialize_le(innerRadius);
    serialize_le(outerRadius);
    serialize_le(startAngle);
    serialize_le(endAngle);
    serialize_le(segments);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawRingLines(const Vector2& center, float innerRadius, float outerRadius, float startAngle, float endAngle, int segments, const Color& color) {
    rmc_start_function_trace(2, 208);
    serialize_Vector2(center);
    serialize_le(innerRadius);
    serialize_le(outerRadius);
    serialize_le(startAngle);
    serialize_le(endAngle);
    serialize_le(segments);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawRectangle(int posX, int posY, int width, int height, const Color& color) {
    rmc_start_function_trace(2, 209);
    serialize_le(posX);
    serialize_le(posY);
    serialize_le(width);
    serialize_le(height);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawRectangleV(const Vector2& position, const Vector2& size, const Color& color) {
    rmc_start_function_trace(2, 210);
    serialize_Vector2(position);
    serialize_Vector2(size);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawRectangleRec(const Rectangle& rec, const Color& color) {
    rmc_start_function_trace(2, 211);
    serialize_Rectangle(rec);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawRectanglePro(const Rectangle& rec, const Vector2& origin, float rotation, const Color& color) {
    rmc_start_function_trace(2, 212);
    serialize_Rectangle(rec);
    serialize_Vector2(origin);
    serialize_le(rotation);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawRectangleGradientV(int posX, int posY, int width, int height, const Color& top, const Color& bottom) {
    rmc_start_function_trace(2, 213);
    serialize_le(posX);
    serialize_le(posY);
    serialize_le(width);
    serialize_le(height);
    serialize_Color(top);
    serialize_Color(bottom);
    rmc_end_function_trace();
}

void serialize_DrawRectangleGradientH(int posX, int posY, int width, int height, const Color& left, const Color& right) {
    rmc_start_function_trace(2, 214);
    serialize_le(posX);
    serialize_le(posY);
    serialize_le(width);
    serialize_le(height);
    serialize_Color(left);
    serialize_Color(right);
    rmc_end_function_trace();
}

void serialize_DrawRectangleGradientEx(const Rectangle& rec, const Color& topLeft, const Color& bottomLeft, const Color& bottomRight, const Color& topRight) {
    rmc_start_function_trace(2, 215);
    serialize_Rectangle(rec);
    serialize_Color(topLeft);
    serialize_Color(bottomLeft);
    serialize_Color(bottomRight);
    serialize_Color(topRight);
    rmc_end_function_trace();
}

void serialize_DrawRectangleLines(int posX, int posY, int width, int height, const Color& color) {
    rmc_start_function_trace(2, 216);
    serialize_le(posX);
    serialize_le(posY);
    serialize_le(width);
    serialize_le(height);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawRectangleLinesEx(const Rectangle& rec, float lineThick, const Color& color) {
    rmc_start_function_trace(2, 217);
    serialize_Rectangle(rec);
    serialize_le(lineThick);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawRectangleRounded(const Rectangle& rec, float roundness, int segments, const Color& color) {
    rmc_start_function_trace(2, 218);
    serialize_Rectangle(rec);
    serialize_le(roundness);
    serialize_le(segments);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawRectangleRoundedLines(const Rectangle& rec, float roundness, int segments, const Color& color) {
    rmc_start_function_trace(2, 219);
    serialize_Rectangle(rec);
    serialize_le(roundness);
    serialize_le(segments);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawRectangleRoundedLinesEx(const Rectangle& rec, float roundness, int segments, float lineThick, const Color& color) {
    rmc_start_function_trace(2, 220);
    serialize_Rectangle(rec);
    serialize_le(roundness);
    serialize_le(segments);
    serialize_le(lineThick);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawTriangle(const Vector2& v1, const Vector2& v2, const Vector2& v3, const Color& color) {
    rmc_start_function_trace(2, 221);
    serialize_Vector2(v1);
    serialize_Vector2(v2);
    serialize_Vector2(v3);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawTriangleLines(const Vector2& v1, const Vector2& v2, const Vector2& v3, const Color& color) {
    rmc_start_function_trace(2, 222);
    serialize_Vector2(v1);
    serialize_Vector2(v2);
    serialize_Vector2(v3);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawTriangleFan(const Vector2* points, int pointCount, const Color& color) {
    rmc_start_function_trace(2, 223);
    int length_points = 1 /* TODO: Specify length for points */;
    serialize_le(length_points);
    for(int i = 0; i < length_points; i++) {
        serialize_Vector2(points[i]);
    }
    serialize_le(pointCount);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawTriangleStrip(const Vector2* points, int pointCount, const Color& color) {
    rmc_start_function_trace(2, 224);
    int length_points = 1 /* TODO: Specify length for points */;
    serialize_le(length_points);
    for(int i = 0; i < length_points; i++) {
        serialize_Vector2(points[i]);
    }
    serialize_le(pointCount);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawPoly(const Vector2& center, int sides, float radius, float rotation, const Color& color) {
    rmc_start_function_trace(2, 225);
    serialize_Vector2(center);
    serialize_le(sides);
    serialize_le(radius);
    serialize_le(rotation);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawPolyLines(const Vector2& center, int sides, float radius, float rotation, const Color& color) {
    rmc_start_function_trace(2, 226);
    serialize_Vector2(center);
    serialize_le(sides);
    serialize_le(radius);
    serialize_le(rotation);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawPolyLinesEx(const Vector2& center, int sides, float radius, float rotation, float lineThick, const Color& color) {
    rmc_start_function_trace(2, 227);
    serialize_Vector2(center);
    serialize_le(sides);
    serialize_le(radius);
    serialize_le(rotation);
    serialize_le(lineThick);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawSplineLinear(const Vector2* points, int pointCount, float thick, const Color& color) {
    rmc_start_function_trace(2, 228);
    int length_points = 1 /* TODO: Specify length for points */;
    serialize_le(length_points);
    for(int i = 0; i < length_points; i++) {
        serialize_Vector2(points[i]);
    }
    serialize_le(pointCount);
    serialize_le(thick);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawSplineBasis(const Vector2* points, int pointCount, float thick, const Color& color) {
    rmc_start_function_trace(2, 229);
    int length_points = 1 /* TODO: Specify length for points */;
    serialize_le(length_points);
    for(int i = 0; i < length_points; i++) {
        serialize_Vector2(points[i]);
    }
    serialize_le(pointCount);
    serialize_le(thick);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawSplineCatmullRom(const Vector2* points, int pointCount, float thick, const Color& color) {
    rmc_start_function_trace(2, 230);
    int length_points = 1 /* TODO: Specify length for points */;
    serialize_le(length_points);
    for(int i = 0; i < length_points; i++) {
        serialize_Vector2(points[i]);
    }
    serialize_le(pointCount);
    serialize_le(thick);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawSplineBezierQuadratic(const Vector2* points, int pointCount, float thick, const Color& color) {
    rmc_start_function_trace(2, 231);
    int length_points = 1 /* TODO: Specify length for points */;
    serialize_le(length_points);
    for(int i = 0; i < length_points; i++) {
        serialize_Vector2(points[i]);
    }
    serialize_le(pointCount);
    serialize_le(thick);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawSplineBezierCubic(const Vector2* points, int pointCount, float thick, const Color& color) {
    rmc_start_function_trace(2, 232);
    int length_points = 1 /* TODO: Specify length for points */;
    serialize_le(length_points);
    for(int i = 0; i < length_points; i++) {
        serialize_Vector2(points[i]);
    }
    serialize_le(pointCount);
    serialize_le(thick);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawSplineSegmentLinear(const Vector2& p1, const Vector2& p2, float thick, const Color& color) {
    rmc_start_function_trace(2, 233);
    serialize_Vector2(p1);
    serialize_Vector2(p2);
    serialize_le(thick);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawSplineSegmentBasis(const Vector2& p1, const Vector2& p2, const Vector2& p3, const Vector2& p4, float thick, const Color& color) {
    rmc_start_function_trace(2, 234);
    serialize_Vector2(p1);
    serialize_Vector2(p2);
    serialize_Vector2(p3);
    serialize_Vector2(p4);
    serialize_le(thick);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawSplineSegmentCatmullRom(const Vector2& p1, const Vector2& p2, const Vector2& p3, const Vector2& p4, float thick, const Color& color) {
    rmc_start_function_trace(2, 235);
    serialize_Vector2(p1);
    serialize_Vector2(p2);
    serialize_Vector2(p3);
    serialize_Vector2(p4);
    serialize_le(thick);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawSplineSegmentBezierQuadratic(const Vector2& p1, const Vector2& c2, const Vector2& p3, float thick, const Color& color) {
    rmc_start_function_trace(2, 236);
    serialize_Vector2(p1);
    serialize_Vector2(c2);
    serialize_Vector2(p3);
    serialize_le(thick);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawSplineSegmentBezierCubic(const Vector2& p1, const Vector2& c2, const Vector2& c3, const Vector2& p4, float thick, const Color& color) {
    rmc_start_function_trace(2, 237);
    serialize_Vector2(p1);
    serialize_Vector2(c2);
    serialize_Vector2(c3);
    serialize_Vector2(p4);
    serialize_le(thick);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_GetSplinePointLinear(const Vector2& startPos, const Vector2& endPos, float t) {
    rmc_start_function_trace(2, 238);
    serialize_Vector2(startPos);
    serialize_Vector2(endPos);
    serialize_le(t);
    rmc_end_function_trace();
}

void serialize_GetSplinePointBasis(const Vector2& p1, const Vector2& p2, const Vector2& p3, const Vector2& p4, float t) {
    rmc_start_function_trace(2, 239);
    serialize_Vector2(p1);
    serialize_Vector2(p2);
    serialize_Vector2(p3);
    serialize_Vector2(p4);
    serialize_le(t);
    rmc_end_function_trace();
}

void serialize_GetSplinePointCatmullRom(const Vector2& p1, const Vector2& p2, const Vector2& p3, const Vector2& p4, float t) {
    rmc_start_function_trace(2, 240);
    serialize_Vector2(p1);
    serialize_Vector2(p2);
    serialize_Vector2(p3);
    serialize_Vector2(p4);
    serialize_le(t);
    rmc_end_function_trace();
}

void serialize_GetSplinePointBezierQuad(const Vector2& p1, const Vector2& c2, const Vector2& p3, float t) {
    rmc_start_function_trace(2, 241);
    serialize_Vector2(p1);
    serialize_Vector2(c2);
    serialize_Vector2(p3);
    serialize_le(t);
    rmc_end_function_trace();
}

void serialize_GetSplinePointBezierCubic(const Vector2& p1, const Vector2& c2, const Vector2& c3, const Vector2& p4, float t) {
    rmc_start_function_trace(2, 242);
    serialize_Vector2(p1);
    serialize_Vector2(c2);
    serialize_Vector2(c3);
    serialize_Vector2(p4);
    serialize_le(t);
    rmc_end_function_trace();
}

void serialize_CheckCollisionRecs(const Rectangle& rec1, const Rectangle& rec2) {
    rmc_start_function_trace(2, 243);
    serialize_Rectangle(rec1);
    serialize_Rectangle(rec2);
    rmc_end_function_trace();
}

void serialize_CheckCollisionCircles(const Vector2& center1, float radius1, const Vector2& center2, float radius2) {
    rmc_start_function_trace(2, 244);
    serialize_Vector2(center1);
    serialize_le(radius1);
    serialize_Vector2(center2);
    serialize_le(radius2);
    rmc_end_function_trace();
}

void serialize_CheckCollisionCircleRec(const Vector2& center, float radius, const Rectangle& rec) {
    rmc_start_function_trace(2, 245);
    serialize_Vector2(center);
    serialize_le(radius);
    serialize_Rectangle(rec);
    rmc_end_function_trace();
}

void serialize_CheckCollisionCircleLine(const Vector2& center, float radius, const Vector2& p1, const Vector2& p2) {
    rmc_start_function_trace(2, 246);
    serialize_Vector2(center);
    serialize_le(radius);
    serialize_Vector2(p1);
    serialize_Vector2(p2);
    rmc_end_function_trace();
}

void serialize_CheckCollisionPointRec(const Vector2& point, const Rectangle& rec) {
    rmc_start_function_trace(2, 247);
    serialize_Vector2(point);
    serialize_Rectangle(rec);
    rmc_end_function_trace();
}

void serialize_CheckCollisionPointCircle(const Vector2& point, const Vector2& center, float radius) {
    rmc_start_function_trace(2, 248);
    serialize_Vector2(point);
    serialize_Vector2(center);
    serialize_le(radius);
    rmc_end_function_trace();
}

void serialize_CheckCollisionPointTriangle(const Vector2& point, const Vector2& p1, const Vector2& p2, const Vector2& p3) {
    rmc_start_function_trace(2, 249);
    serialize_Vector2(point);
    serialize_Vector2(p1);
    serialize_Vector2(p2);
    serialize_Vector2(p3);
    rmc_end_function_trace();
}

void serialize_CheckCollisionPointLine(const Vector2& point, const Vector2& p1, const Vector2& p2, int threshold) {
    rmc_start_function_trace(2, 250);
    serialize_Vector2(point);
    serialize_Vector2(p1);
    serialize_Vector2(p2);
    serialize_le(threshold);
    rmc_end_function_trace();
}

void serialize_CheckCollisionPointPoly(const Vector2& point, const Vector2* points, int pointCount) {
    rmc_start_function_trace(2, 251);
    serialize_Vector2(point);
    int length_points = 1 /* TODO: Specify length for points */;
    serialize_le(length_points);
    for(int i = 0; i < length_points; i++) {
        serialize_Vector2(points[i]);
    }
    serialize_le(pointCount);
    rmc_end_function_trace();
}

void serialize_CheckCollisionLines(const Vector2& startPos1, const Vector2& endPos1, const Vector2& startPos2, const Vector2& endPos2, const Vector2* collisionPoint) {
    rmc_start_function_trace(2, 252);
    serialize_Vector2(startPos1);
    serialize_Vector2(endPos1);
    serialize_Vector2(startPos2);
    serialize_Vector2(endPos2);
    int length_collisionPoint = 1 /* TODO: Specify length for collisionPoint */;
    serialize_le(length_collisionPoint);
    for(int i = 0; i < length_collisionPoint; i++) {
        serialize_Vector2(collisionPoint[i]);
    }
    rmc_end_function_trace();
}

void serialize_GetCollisionRec(const Rectangle& rec1, const Rectangle& rec2) {
    rmc_start_function_trace(2, 253);
    serialize_Rectangle(rec1);
    serialize_Rectangle(rec2);
    rmc_end_function_trace();
}

void serialize_LoadImage(const char* fileName) {
    rmc_start_function_trace(2, 254);
    int length_fileName = strlen(fileName) + 1;
    serialize_le(length_fileName);
    for(int i = 0; i < length_fileName; i++) {
        serialize_le(fileName[i]);
    }
    rmc_end_function_trace();
}

void serialize_LoadImageRaw(const char* fileName, int width, int height, int format, int headerSize) {
    rmc_start_function_trace(2, 255);
    int length_fileName = strlen(fileName) + 1;
    serialize_le(length_fileName);
    for(int i = 0; i < length_fileName; i++) {
        serialize_le(fileName[i]);
    }
    serialize_le(width);
    serialize_le(height);
    serialize_le(format);
    serialize_le(headerSize);
    rmc_end_function_trace();
}

void serialize_LoadImageAnim(const char* fileName, const int* frames) {
    rmc_start_function_trace(2, 256);
    int length_fileName = strlen(fileName) + 1;
    serialize_le(length_fileName);
    for(int i = 0; i < length_fileName; i++) {
        serialize_le(fileName[i]);
    }
    int length_frames = 1 /* TODO: Specify length for frames */;
    serialize_le(length_frames);
    for(int i = 0; i < length_frames; i++) {
        serialize_le(frames[i]);
    }
    rmc_end_function_trace();
}

void serialize_LoadImageAnimFromMemory(const char* fileType, const unsigned char* fileData, int dataSize, const int* frames) {
    rmc_start_function_trace(2, 257);
    int length_fileType = strlen(fileType) + 1;
    serialize_le(length_fileType);
    for(int i = 0; i < length_fileType; i++) {
        serialize_le(fileType[i]);
    }
    int length_fileData = 1 /* TODO: Specify length for fileData */;
    serialize_le(length_fileData);
    for(int i = 0; i < length_fileData; i++) {
        serialize_le(fileData[i]);
    }
    serialize_le(dataSize);
    int length_frames = 1 /* TODO: Specify length for frames */;
    serialize_le(length_frames);
    for(int i = 0; i < length_frames; i++) {
        serialize_le(frames[i]);
    }
    rmc_end_function_trace();
}

void serialize_LoadImageFromMemory(const char* fileType, const unsigned char* fileData, int dataSize) {
    rmc_start_function_trace(2, 258);
    int length_fileType = strlen(fileType) + 1;
    serialize_le(length_fileType);
    for(int i = 0; i < length_fileType; i++) {
        serialize_le(fileType[i]);
    }
    int length_fileData = 1 /* TODO: Specify length for fileData */;
    serialize_le(length_fileData);
    for(int i = 0; i < length_fileData; i++) {
        serialize_le(fileData[i]);
    }
    serialize_le(dataSize);
    rmc_end_function_trace();
}

void serialize_LoadImageFromTexture(Texture2D texture) {
    rmc_start_function_trace(2, 259);
    serialize_le(texture);
    rmc_end_function_trace();
}

void serialize_LoadImageFromScreen() {
    rmc_start_function_trace(2, 260);
    rmc_end_function_trace();
}

void serialize_IsImageValid(const Image& image) {
    rmc_start_function_trace(2, 261);
    serialize_Image(image);
    rmc_end_function_trace();
}

void serialize_UnloadImage(const Image& image) {
    rmc_start_function_trace(2, 262);
    serialize_Image(image);
    rmc_end_function_trace();
}

void serialize_ExportImage(const Image& image, const char* fileName) {
    rmc_start_function_trace(2, 263);
    serialize_Image(image);
    int length_fileName = strlen(fileName) + 1;
    serialize_le(length_fileName);
    for(int i = 0; i < length_fileName; i++) {
        serialize_le(fileName[i]);
    }
    rmc_end_function_trace();
}

void serialize_ExportImageAsCode(const Image& image, const char* fileName) {
    rmc_start_function_trace(2, 264);
    serialize_Image(image);
    int length_fileName = strlen(fileName) + 1;
    serialize_le(length_fileName);
    for(int i = 0; i < length_fileName; i++) {
        serialize_le(fileName[i]);
    }
    rmc_end_function_trace();
}

void serialize_GenImageColor(int width, int height, const Color& color) {
    rmc_start_function_trace(2, 265);
    serialize_le(width);
    serialize_le(height);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_GenImageGradientLinear(int width, int height, int direction, const Color& start, const Color& end) {
    rmc_start_function_trace(2, 266);
    serialize_le(width);
    serialize_le(height);
    serialize_le(direction);
    serialize_Color(start);
    serialize_Color(end);
    rmc_end_function_trace();
}

void serialize_GenImageGradientRadial(int width, int height, float density, const Color& inner, const Color& outer) {
    rmc_start_function_trace(2, 267);
    serialize_le(width);
    serialize_le(height);
    serialize_le(density);
    serialize_Color(inner);
    serialize_Color(outer);
    rmc_end_function_trace();
}

void serialize_GenImageGradientSquare(int width, int height, float density, const Color& inner, const Color& outer) {
    rmc_start_function_trace(2, 268);
    serialize_le(width);
    serialize_le(height);
    serialize_le(density);
    serialize_Color(inner);
    serialize_Color(outer);
    rmc_end_function_trace();
}

void serialize_GenImageChecked(int width, int height, int checksX, int checksY, const Color& col1, const Color& col2) {
    rmc_start_function_trace(2, 269);
    serialize_le(width);
    serialize_le(height);
    serialize_le(checksX);
    serialize_le(checksY);
    serialize_Color(col1);
    serialize_Color(col2);
    rmc_end_function_trace();
}

void serialize_GenImageWhiteNoise(int width, int height, float factor) {
    rmc_start_function_trace(2, 270);
    serialize_le(width);
    serialize_le(height);
    serialize_le(factor);
    rmc_end_function_trace();
}

void serialize_GenImagePerlinNoise(int width, int height, int offsetX, int offsetY, float scale) {
    rmc_start_function_trace(2, 271);
    serialize_le(width);
    serialize_le(height);
    serialize_le(offsetX);
    serialize_le(offsetY);
    serialize_le(scale);
    rmc_end_function_trace();
}

void serialize_GenImageCellular(int width, int height, int tileSize) {
    rmc_start_function_trace(2, 272);
    serialize_le(width);
    serialize_le(height);
    serialize_le(tileSize);
    rmc_end_function_trace();
}

void serialize_GenImageText(int width, int height, const char* text) {
    rmc_start_function_trace(2, 273);
    serialize_le(width);
    serialize_le(height);
    int length_text = strlen(text) + 1;
    serialize_le(length_text);
    for(int i = 0; i < length_text; i++) {
        serialize_le(text[i]);
    }
    rmc_end_function_trace();
}

void serialize_ImageCopy(const Image& image) {
    rmc_start_function_trace(2, 274);
    serialize_Image(image);
    rmc_end_function_trace();
}

void serialize_ImageFromImage(const Image& image, const Rectangle& rec) {
    rmc_start_function_trace(2, 275);
    serialize_Image(image);
    serialize_Rectangle(rec);
    rmc_end_function_trace();
}

void serialize_ImageFromChannel(const Image& image, int selectedChannel) {
    rmc_start_function_trace(2, 276);
    serialize_Image(image);
    serialize_le(selectedChannel);
    rmc_end_function_trace();
}

void serialize_ImageText(const char* text, int fontSize, const Color& color) {
    rmc_start_function_trace(2, 277);
    int length_text = strlen(text) + 1;
    serialize_le(length_text);
    for(int i = 0; i < length_text; i++) {
        serialize_le(text[i]);
    }
    serialize_le(fontSize);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_ImageTextEx(const Font& font, const char* text, float fontSize, float spacing, const Color& tint) {
    rmc_start_function_trace(2, 278);
    serialize_Font(font);
    int length_text = strlen(text) + 1;
    serialize_le(length_text);
    for(int i = 0; i < length_text; i++) {
        serialize_le(text[i]);
    }
    serialize_le(fontSize);
    serialize_le(spacing);
    serialize_Color(tint);
    rmc_end_function_trace();
}

void serialize_ImageFormat(const Image* image, int newFormat) {
    rmc_start_function_trace(2, 279);
    int length_image = 1 /* TODO: Specify length for image */;
    serialize_le(length_image);
    for(int i = 0; i < length_image; i++) {
        serialize_Image(image[i]);
    }
    serialize_le(newFormat);
    rmc_end_function_trace();
}

void serialize_ImageToPOT(const Image* image, const Color& fill) {
    rmc_start_function_trace(2, 280);
    int length_image = 1 /* TODO: Specify length for image */;
    serialize_le(length_image);
    for(int i = 0; i < length_image; i++) {
        serialize_Image(image[i]);
    }
    serialize_Color(fill);
    rmc_end_function_trace();
}

void serialize_ImageCrop(const Image* image, const Rectangle& crop) {
    rmc_start_function_trace(2, 281);
    int length_image = 1 /* TODO: Specify length for image */;
    serialize_le(length_image);
    for(int i = 0; i < length_image; i++) {
        serialize_Image(image[i]);
    }
    serialize_Rectangle(crop);
    rmc_end_function_trace();
}

void serialize_ImageAlphaCrop(const Image* image, float threshold) {
    rmc_start_function_trace(2, 282);
    int length_image = 1 /* TODO: Specify length for image */;
    serialize_le(length_image);
    for(int i = 0; i < length_image; i++) {
        serialize_Image(image[i]);
    }
    serialize_le(threshold);
    rmc_end_function_trace();
}

void serialize_ImageAlphaClear(const Image* image, const Color& color, float threshold) {
    rmc_start_function_trace(2, 283);
    int length_image = 1 /* TODO: Specify length for image */;
    serialize_le(length_image);
    for(int i = 0; i < length_image; i++) {
        serialize_Image(image[i]);
    }
    serialize_Color(color);
    serialize_le(threshold);
    rmc_end_function_trace();
}

void serialize_ImageAlphaMask(const Image* image, const Image& alphaMask) {
    rmc_start_function_trace(2, 284);
    int length_image = 1 /* TODO: Specify length for image */;
    serialize_le(length_image);
    for(int i = 0; i < length_image; i++) {
        serialize_Image(image[i]);
    }
    serialize_Image(alphaMask);
    rmc_end_function_trace();
}

void serialize_ImageAlphaPremultiply(const Image* image) {
    rmc_start_function_trace(2, 285);
    int length_image = 1 /* TODO: Specify length for image */;
    serialize_le(length_image);
    for(int i = 0; i < length_image; i++) {
        serialize_Image(image[i]);
    }
    rmc_end_function_trace();
}

void serialize_ImageBlurGaussian(const Image* image, int blurSize) {
    rmc_start_function_trace(2, 286);
    int length_image = 1 /* TODO: Specify length for image */;
    serialize_le(length_image);
    for(int i = 0; i < length_image; i++) {
        serialize_Image(image[i]);
    }
    serialize_le(blurSize);
    rmc_end_function_trace();
}

void serialize_ImageKernelConvolution(const Image* image, const float* kernel, int kernelSize) {
    rmc_start_function_trace(2, 287);
    int length_image = 1 /* TODO: Specify length for image */;
    serialize_le(length_image);
    for(int i = 0; i < length_image; i++) {
        serialize_Image(image[i]);
    }
    int length_kernel = 1 /* TODO: Specify length for kernel */;
    serialize_le(length_kernel);
    for(int i = 0; i < length_kernel; i++) {
        serialize_le(kernel[i]);
    }
    serialize_le(kernelSize);
    rmc_end_function_trace();
}

void serialize_ImageResize(const Image* image, int newWidth, int newHeight) {
    rmc_start_function_trace(2, 288);
    int length_image = 1 /* TODO: Specify length for image */;
    serialize_le(length_image);
    for(int i = 0; i < length_image; i++) {
        serialize_Image(image[i]);
    }
    serialize_le(newWidth);
    serialize_le(newHeight);
    rmc_end_function_trace();
}

void serialize_ImageResizeNN(const Image* image, int newWidth, int newHeight) {
    rmc_start_function_trace(2, 289);
    int length_image = 1 /* TODO: Specify length for image */;
    serialize_le(length_image);
    for(int i = 0; i < length_image; i++) {
        serialize_Image(image[i]);
    }
    serialize_le(newWidth);
    serialize_le(newHeight);
    rmc_end_function_trace();
}

void serialize_ImageResizeCanvas(const Image* image, int newWidth, int newHeight, int offsetX, int offsetY, const Color& fill) {
    rmc_start_function_trace(2, 290);
    int length_image = 1 /* TODO: Specify length for image */;
    serialize_le(length_image);
    for(int i = 0; i < length_image; i++) {
        serialize_Image(image[i]);
    }
    serialize_le(newWidth);
    serialize_le(newHeight);
    serialize_le(offsetX);
    serialize_le(offsetY);
    serialize_Color(fill);
    rmc_end_function_trace();
}

void serialize_ImageMipmaps(const Image* image) {
    rmc_start_function_trace(2, 291);
    int length_image = 1 /* TODO: Specify length for image */;
    serialize_le(length_image);
    for(int i = 0; i < length_image; i++) {
        serialize_Image(image[i]);
    }
    rmc_end_function_trace();
}

void serialize_ImageDither(const Image* image, int rBpp, int gBpp, int bBpp, int aBpp) {
    rmc_start_function_trace(2, 292);
    int length_image = 1 /* TODO: Specify length for image */;
    serialize_le(length_image);
    for(int i = 0; i < length_image; i++) {
        serialize_Image(image[i]);
    }
    serialize_le(rBpp);
    serialize_le(gBpp);
    serialize_le(bBpp);
    serialize_le(aBpp);
    rmc_end_function_trace();
}

void serialize_ImageFlipVertical(const Image* image) {
    rmc_start_function_trace(2, 293);
    int length_image = 1 /* TODO: Specify length for image */;
    serialize_le(length_image);
    for(int i = 0; i < length_image; i++) {
        serialize_Image(image[i]);
    }
    rmc_end_function_trace();
}

void serialize_ImageFlipHorizontal(const Image* image) {
    rmc_start_function_trace(2, 294);
    int length_image = 1 /* TODO: Specify length for image */;
    serialize_le(length_image);
    for(int i = 0; i < length_image; i++) {
        serialize_Image(image[i]);
    }
    rmc_end_function_trace();
}

void serialize_ImageRotate(const Image* image, int degrees) {
    rmc_start_function_trace(2, 295);
    int length_image = 1 /* TODO: Specify length for image */;
    serialize_le(length_image);
    for(int i = 0; i < length_image; i++) {
        serialize_Image(image[i]);
    }
    serialize_le(degrees);
    rmc_end_function_trace();
}

void serialize_ImageRotateCW(const Image* image) {
    rmc_start_function_trace(2, 296);
    int length_image = 1 /* TODO: Specify length for image */;
    serialize_le(length_image);
    for(int i = 0; i < length_image; i++) {
        serialize_Image(image[i]);
    }
    rmc_end_function_trace();
}

void serialize_ImageRotateCCW(const Image* image) {
    rmc_start_function_trace(2, 297);
    int length_image = 1 /* TODO: Specify length for image */;
    serialize_le(length_image);
    for(int i = 0; i < length_image; i++) {
        serialize_Image(image[i]);
    }
    rmc_end_function_trace();
}

void serialize_ImageColorTint(const Image* image, const Color& color) {
    rmc_start_function_trace(2, 298);
    int length_image = 1 /* TODO: Specify length for image */;
    serialize_le(length_image);
    for(int i = 0; i < length_image; i++) {
        serialize_Image(image[i]);
    }
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_ImageColorInvert(const Image* image) {
    rmc_start_function_trace(2, 299);
    int length_image = 1 /* TODO: Specify length for image */;
    serialize_le(length_image);
    for(int i = 0; i < length_image; i++) {
        serialize_Image(image[i]);
    }
    rmc_end_function_trace();
}

void serialize_ImageColorGrayscale(const Image* image) {
    rmc_start_function_trace(2, 300);
    int length_image = 1 /* TODO: Specify length for image */;
    serialize_le(length_image);
    for(int i = 0; i < length_image; i++) {
        serialize_Image(image[i]);
    }
    rmc_end_function_trace();
}

void serialize_ImageColorContrast(const Image* image, float contrast) {
    rmc_start_function_trace(2, 301);
    int length_image = 1 /* TODO: Specify length for image */;
    serialize_le(length_image);
    for(int i = 0; i < length_image; i++) {
        serialize_Image(image[i]);
    }
    serialize_le(contrast);
    rmc_end_function_trace();
}

void serialize_ImageColorBrightness(const Image* image, int brightness) {
    rmc_start_function_trace(2, 302);
    int length_image = 1 /* TODO: Specify length for image */;
    serialize_le(length_image);
    for(int i = 0; i < length_image; i++) {
        serialize_Image(image[i]);
    }
    serialize_le(brightness);
    rmc_end_function_trace();
}

void serialize_ImageColorReplace(const Image* image, const Color& color, const Color& replace) {
    rmc_start_function_trace(2, 303);
    int length_image = 1 /* TODO: Specify length for image */;
    serialize_le(length_image);
    for(int i = 0; i < length_image; i++) {
        serialize_Image(image[i]);
    }
    serialize_Color(color);
    serialize_Color(replace);
    rmc_end_function_trace();
}

void serialize_UnloadImageColors(const Color* colors) {
    rmc_start_function_trace(2, 304);
    int length_colors = 1 /* TODO: Specify length for colors */;
    serialize_le(length_colors);
    for(int i = 0; i < length_colors; i++) {
        serialize_Color(colors[i]);
    }
    rmc_end_function_trace();
}

void serialize_UnloadImagePalette(const Color* colors) {
    rmc_start_function_trace(2, 305);
    int length_colors = 1 /* TODO: Specify length for colors */;
    serialize_le(length_colors);
    for(int i = 0; i < length_colors; i++) {
        serialize_Color(colors[i]);
    }
    rmc_end_function_trace();
}

void serialize_GetImageAlphaBorder(const Image& image, float threshold) {
    rmc_start_function_trace(2, 306);
    serialize_Image(image);
    serialize_le(threshold);
    rmc_end_function_trace();
}

void serialize_GetImageColor(const Image& image, int x, int y) {
    rmc_start_function_trace(2, 307);
    serialize_Image(image);
    serialize_le(x);
    serialize_le(y);
    rmc_end_function_trace();
}

void serialize_ImageClearBackground(const Image* dst, const Color& color) {
    rmc_start_function_trace(2, 308);
    int length_dst = 1 /* TODO: Specify length for dst */;
    serialize_le(length_dst);
    for(int i = 0; i < length_dst; i++) {
        serialize_Image(dst[i]);
    }
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_ImageDrawPixel(const Image* dst, int posX, int posY, const Color& color) {
    rmc_start_function_trace(2, 309);
    int length_dst = 1 /* TODO: Specify length for dst */;
    serialize_le(length_dst);
    for(int i = 0; i < length_dst; i++) {
        serialize_Image(dst[i]);
    }
    serialize_le(posX);
    serialize_le(posY);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_ImageDrawPixelV(const Image* dst, const Vector2& position, const Color& color) {
    rmc_start_function_trace(2, 310);
    int length_dst = 1 /* TODO: Specify length for dst */;
    serialize_le(length_dst);
    for(int i = 0; i < length_dst; i++) {
        serialize_Image(dst[i]);
    }
    serialize_Vector2(position);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_ImageDrawLine(const Image* dst, int startPosX, int startPosY, int endPosX, int endPosY, const Color& color) {
    rmc_start_function_trace(2, 311);
    int length_dst = 1 /* TODO: Specify length for dst */;
    serialize_le(length_dst);
    for(int i = 0; i < length_dst; i++) {
        serialize_Image(dst[i]);
    }
    serialize_le(startPosX);
    serialize_le(startPosY);
    serialize_le(endPosX);
    serialize_le(endPosY);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_ImageDrawLineV(const Image* dst, const Vector2& start, const Vector2& end, const Color& color) {
    rmc_start_function_trace(2, 312);
    int length_dst = 1 /* TODO: Specify length for dst */;
    serialize_le(length_dst);
    for(int i = 0; i < length_dst; i++) {
        serialize_Image(dst[i]);
    }
    serialize_Vector2(start);
    serialize_Vector2(end);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_ImageDrawLineEx(const Image* dst, const Vector2& start, const Vector2& end, int thick, const Color& color) {
    rmc_start_function_trace(2, 313);
    int length_dst = 1 /* TODO: Specify length for dst */;
    serialize_le(length_dst);
    for(int i = 0; i < length_dst; i++) {
        serialize_Image(dst[i]);
    }
    serialize_Vector2(start);
    serialize_Vector2(end);
    serialize_le(thick);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_ImageDrawCircle(const Image* dst, int centerX, int centerY, int radius, const Color& color) {
    rmc_start_function_trace(2, 314);
    int length_dst = 1 /* TODO: Specify length for dst */;
    serialize_le(length_dst);
    for(int i = 0; i < length_dst; i++) {
        serialize_Image(dst[i]);
    }
    serialize_le(centerX);
    serialize_le(centerY);
    serialize_le(radius);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_ImageDrawCircleV(const Image* dst, const Vector2& center, int radius, const Color& color) {
    rmc_start_function_trace(2, 315);
    int length_dst = 1 /* TODO: Specify length for dst */;
    serialize_le(length_dst);
    for(int i = 0; i < length_dst; i++) {
        serialize_Image(dst[i]);
    }
    serialize_Vector2(center);
    serialize_le(radius);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_ImageDrawCircleLines(const Image* dst, int centerX, int centerY, int radius, const Color& color) {
    rmc_start_function_trace(2, 316);
    int length_dst = 1 /* TODO: Specify length for dst */;
    serialize_le(length_dst);
    for(int i = 0; i < length_dst; i++) {
        serialize_Image(dst[i]);
    }
    serialize_le(centerX);
    serialize_le(centerY);
    serialize_le(radius);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_ImageDrawCircleLinesV(const Image* dst, const Vector2& center, int radius, const Color& color) {
    rmc_start_function_trace(2, 317);
    int length_dst = 1 /* TODO: Specify length for dst */;
    serialize_le(length_dst);
    for(int i = 0; i < length_dst; i++) {
        serialize_Image(dst[i]);
    }
    serialize_Vector2(center);
    serialize_le(radius);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_ImageDrawRectangle(const Image* dst, int posX, int posY, int width, int height, const Color& color) {
    rmc_start_function_trace(2, 318);
    int length_dst = 1 /* TODO: Specify length for dst */;
    serialize_le(length_dst);
    for(int i = 0; i < length_dst; i++) {
        serialize_Image(dst[i]);
    }
    serialize_le(posX);
    serialize_le(posY);
    serialize_le(width);
    serialize_le(height);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_ImageDrawRectangleV(const Image* dst, const Vector2& position, const Vector2& size, const Color& color) {
    rmc_start_function_trace(2, 319);
    serialize_Image(*dst);
    serialize_Vector2(position);
    serialize_Vector2(size);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_ImageDrawRectangleRec(const Image* dst, const Rectangle& rec, const Color& color) {
    rmc_start_function_trace(2, 320);
    int length_dst = 1 /* TODO: Specify length for dst */;
    serialize_le(length_dst);
    for(int i = 0; i < length_dst; i++) {
        serialize_Image(dst[i]);
    }
    serialize_Rectangle(rec);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_ImageDrawRectangleLines(const Image* dst, const Rectangle& rec, int thick, const Color& color) {
    rmc_start_function_trace(2, 321);
    int length_dst = 1 /* TODO: Specify length for dst */;
    serialize_le(length_dst);
    for(int i = 0; i < length_dst; i++) {
        serialize_Image(dst[i]);
    }
    serialize_Rectangle(rec);
    serialize_le(thick);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_ImageDrawTriangle(const Image* dst, const Vector2& v1, const Vector2& v2, const Vector2& v3, const Color& color) {
    rmc_start_function_trace(2, 322);
    int length_dst = 1 /* TODO: Specify length for dst */;
    serialize_le(length_dst);
    for(int i = 0; i < length_dst; i++) {
        serialize_Image(dst[i]);
    }
    serialize_Vector2(v1);
    serialize_Vector2(v2);
    serialize_Vector2(v3);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_ImageDrawTriangleEx(const Image* dst, const Vector2& v1, const Vector2& v2, const Vector2& v3, const Color& c1, const Color& c2, const Color& c3) {
    rmc_start_function_trace(2, 323);
    int length_dst = 1 /* TODO: Specify length for dst */;
    serialize_le(length_dst);
    for(int i = 0; i < length_dst; i++) {
        serialize_Image(dst[i]);
    }
    serialize_Vector2(v1);
    serialize_Vector2(v2);
    serialize_Vector2(v3);
    serialize_Color(c1);
    serialize_Color(c2);
    serialize_Color(c3);
    rmc_end_function_trace();
}

void serialize_ImageDrawTriangleLines(const Image* dst, const Vector2& v1, const Vector2& v2, const Vector2& v3, const Color& color) {
    rmc_start_function_trace(2, 324);
    int length_dst = 1 /* TODO: Specify length for dst */;
    serialize_le(length_dst);
    for(int i = 0; i < length_dst; i++) {
        serialize_Image(dst[i]);
    }
    serialize_Vector2(v1);
    serialize_Vector2(v2);
    serialize_Vector2(v3);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_ImageDrawTriangleFan(const Image* dst, const Vector2* points, int pointCount, const Color& color) {
    rmc_start_function_trace(2, 325);
    int length_dst = 1 /* TODO: Specify length for dst */;
    serialize_le(length_dst);
    for(int i = 0; i < length_dst; i++) {
        serialize_Image(dst[i]);
    }
    int length_points = 1 /* TODO: Specify length for points */;
    serialize_le(length_points);
    for(int i = 0; i < length_points; i++) {
        serialize_Vector2(points[i]);
    }
    serialize_le(pointCount);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_ImageDrawTriangleStrip(const Image* dst, const Vector2* points, int pointCount, const Color& color) {
    rmc_start_function_trace(2, 326);
    int length_dst = 1 /* TODO: Specify length for dst */;
    serialize_le(length_dst);
    for(int i = 0; i < length_dst; i++) {
        serialize_Image(dst[i]);
    }
    int length_points = 1 /* TODO: Specify length for points */;
    serialize_le(length_points);
    for(int i = 0; i < length_points; i++) {
        serialize_Vector2(points[i]);
    }
    serialize_le(pointCount);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_ImageDraw(const Image* dst, const Image& src, const Rectangle& srcRec, const Rectangle& dstRec, const Color& tint) {
    rmc_start_function_trace(2, 327);
    int length_dst = 1 /* TODO: Specify length for dst */;
    serialize_le(length_dst);
    for(int i = 0; i < length_dst; i++) {
        serialize_Image(dst[i]);
    }
    serialize_Image(src);
    serialize_Rectangle(srcRec);
    serialize_Rectangle(dstRec);
    serialize_Color(tint);
    rmc_end_function_trace();
}

void serialize_ImageDrawText(const Image* dst, const char* text, int posX, int posY, int fontSize, const Color& color) {
    rmc_start_function_trace(2, 328);
    int length_dst = 1 /* TODO: Specify length for dst */;
    serialize_le(length_dst);
    for(int i = 0; i < length_dst; i++) {
        serialize_Image(dst[i]);
    }
    int length_text = strlen(text) + 1;
    serialize_le(length_text);
    for(int i = 0; i < length_text; i++) {
        serialize_le(text[i]);
    }
    serialize_le(posX);
    serialize_le(posY);
    serialize_le(fontSize);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_ImageDrawTextEx(const Image* dst, const Font& font, const char* text, const Vector2& position, float fontSize, float spacing, const Color& tint) {
    rmc_start_function_trace(2, 329);
    int length_dst = 1 /* TODO: Specify length for dst */;
    serialize_le(length_dst);
    for(int i = 0; i < length_dst; i++) {
        serialize_Image(dst[i]);
    }
    serialize_Font(font);
    int length_text = strlen(text) + 1;
    serialize_le(length_text);
    for(int i = 0; i < length_text; i++) {
        serialize_le(text[i]);
    }
    serialize_Vector2(position);
    serialize_le(fontSize);
    serialize_le(spacing);
    serialize_Color(tint);
    rmc_end_function_trace();
}

void serialize_LoadTexture(const char* fileName) {
    rmc_start_function_trace(2, 330);
    int length_fileName = strlen(fileName) + 1;
    serialize_le(length_fileName);
    for(int i = 0; i < length_fileName; i++) {
        serialize_le(fileName[i]);
    }
    rmc_end_function_trace();
}

void serialize_LoadTextureFromImage(const Image& image) {
    rmc_start_function_trace(2, 331);
    serialize_Image(image);
    rmc_end_function_trace();
}

void serialize_LoadTextureCubemap(const Image& image, int layout) {
    rmc_start_function_trace(2, 332);
    serialize_Image(image);
    serialize_le(layout);
    rmc_end_function_trace();
}

void serialize_LoadRenderTexture(int width, int height) {
    rmc_start_function_trace(2, 333);
    serialize_le(width);
    serialize_le(height);
    rmc_end_function_trace();
}

void serialize_IsTextureValid(Texture2D texture) {
    rmc_start_function_trace(2, 334);
    serialize_le(texture);
    rmc_end_function_trace();
}

void serialize_UnloadTexture(Texture2D texture) {
    rmc_start_function_trace(2, 335);
    serialize_le(texture);
    rmc_end_function_trace();
}

void serialize_IsRenderTextureValid(RenderTexture2D target) {
    rmc_start_function_trace(2, 336);
    serialize_le(target);
    rmc_end_function_trace();
}

void serialize_UnloadRenderTexture(RenderTexture2D target) {
    rmc_start_function_trace(2, 337);
    serialize_le(target);
    rmc_end_function_trace();
}

void serialize_UpdateTexture(Texture2D texture, const void* pixels) {
    rmc_start_function_trace(2, 338);
    serialize_le(texture);
    // Skipping pixels (type: const void*) - not serializable
    rmc_end_function_trace();
}

void serialize_UpdateTextureRec(Texture2D texture, const Rectangle& rec, const void* pixels) {
    rmc_start_function_trace(2, 339);
    serialize_le(texture);
    serialize_Rectangle(rec);
    // Skipping pixels (type: const void*) - not serializable
    rmc_end_function_trace();
}

void serialize_GenTextureMipmaps(const Texture2D* texture) {
    rmc_start_function_trace(2, 340);
    int length_texture = 1 /* TODO: Specify length for texture */;
    serialize_le(length_texture);
    for(int i = 0; i < length_texture; i++) {
        serialize_le(texture[i]);
    }
    rmc_end_function_trace();
}

void serialize_SetTextureFilter(Texture2D texture, int filter) {
    rmc_start_function_trace(2, 341);
    serialize_le(texture);
    serialize_le(filter);
    rmc_end_function_trace();
}

void serialize_SetTextureWrap(Texture2D texture, int wrap) {
    rmc_start_function_trace(2, 342);
    serialize_le(texture);
    serialize_le(wrap);
    rmc_end_function_trace();
}

void serialize_DrawTexture(Texture2D texture, int posX, int posY, const Color& tint) {
    rmc_start_function_trace(2, 343);
    serialize_le(texture);
    serialize_le(posX);
    serialize_le(posY);
    serialize_Color(tint);
    rmc_end_function_trace();
}

void serialize_DrawTextureV(Texture2D texture, const Vector2& position, const Color& tint) {
    rmc_start_function_trace(2, 344);
    serialize_le(texture);
    serialize_Vector2(position);
    serialize_Color(tint);
    rmc_end_function_trace();
}

void serialize_DrawTextureEx(Texture2D texture, const Vector2& position, float rotation, float scale, const Color& tint) {
    rmc_start_function_trace(2, 345);
    serialize_le(texture);
    serialize_Vector2(position);
    serialize_le(rotation);
    serialize_le(scale);
    serialize_Color(tint);
    rmc_end_function_trace();
}

void serialize_DrawTextureRec(Texture2D texture, const Rectangle& source, const Vector2& position, const Color& tint) {
    rmc_start_function_trace(2, 346);
    serialize_le(texture);
    serialize_Rectangle(source);
    serialize_Vector2(position);
    serialize_Color(tint);
    rmc_end_function_trace();
}

void serialize_DrawTexturePro(Texture2D texture, const Rectangle& source, const Rectangle& dest, const Vector2& origin, float rotation, const Color& tint) {
    rmc_start_function_trace(2, 347);
    serialize_le(texture);
    serialize_Rectangle(source);
    serialize_Rectangle(dest);
    serialize_Vector2(origin);
    serialize_le(rotation);
    serialize_Color(tint);
    rmc_end_function_trace();
}

void serialize_DrawTextureNPatch(Texture2D texture, const NPatchInfo& nPatchInfo, const Rectangle& dest, const Vector2& origin, float rotation, const Color& tint) {
    rmc_start_function_trace(2, 348);
    serialize_le(texture);
    serialize_NPatchInfo(nPatchInfo);
    serialize_Rectangle(dest);
    serialize_Vector2(origin);
    serialize_le(rotation);
    serialize_Color(tint);
    rmc_end_function_trace();
}

void serialize_ColorIsEqual(const Color& col1, const Color& col2) {
    rmc_start_function_trace(2, 349);
    serialize_Color(col1);
    serialize_Color(col2);
    rmc_end_function_trace();
}

void serialize_Fade(const Color& color, float alpha) {
    rmc_start_function_trace(2, 350);
    serialize_Color(color);
    serialize_le(alpha);
    rmc_end_function_trace();
}

void serialize_ColorToInt(const Color& color) {
    rmc_start_function_trace(2, 351);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_ColorNormalize(const Color& color) {
    rmc_start_function_trace(2, 352);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_ColorFromNormalized(const Vector4& normalized) {
    rmc_start_function_trace(2, 353);
    serialize_Vector4(normalized);
    rmc_end_function_trace();
}

void serialize_ColorToHSV(const Color& color) {
    rmc_start_function_trace(2, 354);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_ColorFromHSV(float hue, float saturation, float value) {
    rmc_start_function_trace(2, 355);
    serialize_le(hue);
    serialize_le(saturation);
    serialize_le(value);
    rmc_end_function_trace();
}

void serialize_ColorTint(const Color& color, const Color& tint) {
    rmc_start_function_trace(2, 356);
    serialize_Color(color);
    serialize_Color(tint);
    rmc_end_function_trace();
}

void serialize_ColorBrightness(const Color& color, float factor) {
    rmc_start_function_trace(2, 357);
    serialize_Color(color);
    serialize_le(factor);
    rmc_end_function_trace();
}

void serialize_ColorContrast(const Color& color, float contrast) {
    rmc_start_function_trace(2, 358);
    serialize_Color(color);
    serialize_le(contrast);
    rmc_end_function_trace();
}

void serialize_ColorAlpha(const Color& color, float alpha) {
    rmc_start_function_trace(2, 359);
    serialize_Color(color);
    serialize_le(alpha);
    rmc_end_function_trace();
}

void serialize_ColorAlphaBlend(const Color& dst, const Color& src, const Color& tint) {
    rmc_start_function_trace(2, 360);
    serialize_Color(dst);
    serialize_Color(src);
    serialize_Color(tint);
    rmc_end_function_trace();
}

void serialize_ColorLerp(const Color& color1, const Color& color2, float factor) {
    rmc_start_function_trace(2, 361);
    serialize_Color(color1);
    serialize_Color(color2);
    serialize_le(factor);
    rmc_end_function_trace();
}

void serialize_GetColor(unsigned int hexValue) {
    rmc_start_function_trace(2, 362);
    serialize_le(hexValue);
    rmc_end_function_trace();
}

void serialize_GetPixelColor(const void* srcPtr, int format) {
    rmc_start_function_trace(2, 363);
    // Skipping srcPtr (type: void*) - not serializable
    serialize_le(format);
    rmc_end_function_trace();
}

void serialize_SetPixelColor(const void* dstPtr, const Color& color, int format) {
    rmc_start_function_trace(2, 364);
    // Skipping dstPtr (type: void*) - not serializable
    serialize_Color(color);
    serialize_le(format);
    rmc_end_function_trace();
}

void serialize_GetPixelDataSize(int width, int height, int format) {
    rmc_start_function_trace(2, 365);
    serialize_le(width);
    serialize_le(height);
    serialize_le(format);
    rmc_end_function_trace();
}

void serialize_GetFontDefault() {
    rmc_start_function_trace(2, 366);
    rmc_end_function_trace();
}

void serialize_LoadFont(const char* fileName) {
    rmc_start_function_trace(2, 367);
    int length_fileName = strlen(fileName) + 1;
    serialize_le(length_fileName);
    for(int i = 0; i < length_fileName; i++) {
        serialize_le(fileName[i]);
    }
    rmc_end_function_trace();
}

void serialize_LoadFontEx(const char* fileName, int fontSize, const int* codepoints, int codepointCount) {
    rmc_start_function_trace(2, 368);
    int length_fileName = strlen(fileName) + 1;
    serialize_le(length_fileName);
    for(int i = 0; i < length_fileName; i++) {
        serialize_le(fileName[i]);
    }
    serialize_le(fontSize);
    int length_codepoints = 1 /* TODO: Specify length for codepoints */;
    serialize_le(length_codepoints);
    for(int i = 0; i < length_codepoints; i++) {
        serialize_le(codepoints[i]);
    }
    serialize_le(codepointCount);
    rmc_end_function_trace();
}

void serialize_LoadFontFromImage(const Image& image, const Color& key, int firstChar) {
    rmc_start_function_trace(2, 369);
    serialize_Image(image);
    serialize_Color(key);
    serialize_le(firstChar);
    rmc_end_function_trace();
}

void serialize_LoadFontFromMemory(const char* fileType, const unsigned char* fileData, int dataSize, int fontSize, const int* codepoints, int codepointCount) {
    rmc_start_function_trace(2, 370);
    int length_fileType = strlen(fileType) + 1;
    serialize_le(length_fileType);
    for(int i = 0; i < length_fileType; i++) {
        serialize_le(fileType[i]);
    }
    int length_fileData = 1 /* TODO: Specify length for fileData */;
    serialize_le(length_fileData);
    for(int i = 0; i < length_fileData; i++) {
        serialize_le(fileData[i]);
    }
    serialize_le(dataSize);
    serialize_le(fontSize);
    int length_codepoints = 1 /* TODO: Specify length for codepoints */;
    serialize_le(length_codepoints);
    for(int i = 0; i < length_codepoints; i++) {
        serialize_le(codepoints[i]);
    }
    serialize_le(codepointCount);
    rmc_end_function_trace();
}

void serialize_IsFontValid(const Font& font) {
    rmc_start_function_trace(2, 371);
    serialize_Font(font);
    rmc_end_function_trace();
}

void serialize_UnloadFontData(const GlyphInfo* glyphs, int glyphCount) {
    rmc_start_function_trace(2, 372);
    int length_glyphs = 1 /* TODO: Specify length for glyphs */;
    serialize_le(length_glyphs);
    for(int i = 0; i < length_glyphs; i++) {
        serialize_GlyphInfo(glyphs[i]);
    }
    serialize_le(glyphCount);
    rmc_end_function_trace();
}

void serialize_UnloadFont(const Font& font) {
    rmc_start_function_trace(2, 373);
    serialize_Font(font);
    rmc_end_function_trace();
}

void serialize_ExportFontAsCode(const Font& font, const char* fileName) {
    rmc_start_function_trace(2, 374);
    serialize_Font(font);
    int length_fileName = strlen(fileName) + 1;
    serialize_le(length_fileName);
    for(int i = 0; i < length_fileName; i++) {
        serialize_le(fileName[i]);
    }
    rmc_end_function_trace();
}

void serialize_DrawFPS(int posX, int posY) {
    rmc_start_function_trace(2, 375);
    serialize_le(posX);
    serialize_le(posY);
    rmc_end_function_trace();
}

void serialize_DrawText(const char* text, int posX, int posY, int fontSize, const Color& color) {
    rmc_start_function_trace(2, 376);
    int length_text = strlen(text) + 1;
    serialize_le(length_text);
    for(int i = 0; i < length_text; i++) {
        serialize_le(text[i]);
    }
    serialize_le(posX);
    serialize_le(posY);
    serialize_le(fontSize);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawTextEx(const Font& font, const char* text, const Vector2& position, float fontSize, float spacing, const Color& tint) {
    rmc_start_function_trace(2, 377);
    serialize_Font(font);
    int length_text = strlen(text) + 1;
    serialize_le(length_text);
    for(int i = 0; i < length_text; i++) {
        serialize_le(text[i]);
    }
    serialize_Vector2(position);
    serialize_le(fontSize);
    serialize_le(spacing);
    serialize_Color(tint);
    rmc_end_function_trace();
}

void serialize_DrawTextPro(const Font& font, const char* text, const Vector2& position, const Vector2& origin, float rotation, float fontSize, float spacing, const Color& tint) {
    rmc_start_function_trace(2, 378);
    serialize_Font(font);
    int length_text = strlen(text) + 1;
    serialize_le(length_text);
    for(int i = 0; i < length_text; i++) {
        serialize_le(text[i]);
    }
    serialize_Vector2(position);
    serialize_Vector2(origin);
    serialize_le(rotation);
    serialize_le(fontSize);
    serialize_le(spacing);
    serialize_Color(tint);
    rmc_end_function_trace();
}

void serialize_DrawTextCodepoint(const Font& font, int codepoint, const Vector2& position, float fontSize, const Color& tint) {
    rmc_start_function_trace(2, 379);
    serialize_Font(font);
    serialize_le(codepoint);
    serialize_Vector2(position);
    serialize_le(fontSize);
    serialize_Color(tint);
    rmc_end_function_trace();
}

void serialize_DrawTextCodepoints(const Font& font, const int* codepoints, int codepointCount, const Vector2& position, float fontSize, float spacing, const Color& tint) {
    rmc_start_function_trace(2, 380);
    serialize_Font(font);
    int length_codepoints = 1 /* TODO: Specify length for codepoints */;
    serialize_le(length_codepoints);
    for(int i = 0; i < length_codepoints; i++) {
        serialize_le(codepoints[i]);
    }
    serialize_le(codepointCount);
    serialize_Vector2(position);
    serialize_le(fontSize);
    serialize_le(spacing);
    serialize_Color(tint);
    rmc_end_function_trace();
}

void serialize_SetTextLineSpacing(int spacing) {
    rmc_start_function_trace(2, 381);
    serialize_le(spacing);
    rmc_end_function_trace();
}

void serialize_MeasureText(const char* text, int fontSize) {
    rmc_start_function_trace(2, 382);
    int length_text = strlen(text) + 1;
    serialize_le(length_text);
    for(int i = 0; i < length_text; i++) {
        serialize_le(text[i]);
    }
    serialize_le(fontSize);
    rmc_end_function_trace();
}

void serialize_MeasureTextEx(const Font& font, const char* text, float fontSize, float spacing) {
    rmc_start_function_trace(2, 383);
    serialize_Font(font);
    int length_text = strlen(text) + 1;
    serialize_le(length_text);
    for(int i = 0; i < length_text; i++) {
        serialize_le(text[i]);
    }
    serialize_le(fontSize);
    serialize_le(spacing);
    rmc_end_function_trace();
}

void serialize_GetGlyphIndex(const Font& font, int codepoint) {
    rmc_start_function_trace(2, 384);
    serialize_Font(font);
    serialize_le(codepoint);
    rmc_end_function_trace();
}

void serialize_GetGlyphInfo(const Font& font, int codepoint) {
    rmc_start_function_trace(2, 385);
    serialize_Font(font);
    serialize_le(codepoint);
    rmc_end_function_trace();
}

void serialize_GetGlyphAtlasRec(const Font& font, int codepoint) {
    rmc_start_function_trace(2, 386);
    serialize_Font(font);
    serialize_le(codepoint);
    rmc_end_function_trace();
}

void serialize_UnloadUTF8(const char* text) {
    rmc_start_function_trace(2, 387);
    int length_text = strlen(text) + 1;
    serialize_le(length_text);
    for(int i = 0; i < length_text; i++) {
        serialize_le(text[i]);
    }
    rmc_end_function_trace();
}

void serialize_UnloadCodepoints(const int* codepoints) {
    rmc_start_function_trace(2, 388);
    int length_codepoints = 1 /* TODO: Specify length for codepoints */;
    serialize_le(length_codepoints);
    for(int i = 0; i < length_codepoints; i++) {
        serialize_le(codepoints[i]);
    }
    rmc_end_function_trace();
}

void serialize_GetCodepointCount(const char* text) {
    rmc_start_function_trace(2, 389);
    int length_text = strlen(text) + 1;
    serialize_le(length_text);
    for(int i = 0; i < length_text; i++) {
        serialize_le(text[i]);
    }
    rmc_end_function_trace();
}

void serialize_GetCodepoint(const char* text, const int* codepointSize) {
    rmc_start_function_trace(2, 390);
    int length_text = strlen(text) + 1;
    serialize_le(length_text);
    for(int i = 0; i < length_text; i++) {
        serialize_le(text[i]);
    }
    int length_codepointSize = 1 /* TODO: Specify length for codepointSize */;
    serialize_le(length_codepointSize);
    for(int i = 0; i < length_codepointSize; i++) {
        serialize_le(codepointSize[i]);
    }
    rmc_end_function_trace();
}

void serialize_GetCodepointNext(const char* text, const int* codepointSize) {
    rmc_start_function_trace(2, 391);
    int length_text = strlen(text) + 1;
    serialize_le(length_text);
    for(int i = 0; i < length_text; i++) {
        serialize_le(text[i]);
    }
    int length_codepointSize = 1 /* TODO: Specify length for codepointSize */;
    serialize_le(length_codepointSize);
    for(int i = 0; i < length_codepointSize; i++) {
        serialize_le(codepointSize[i]);
    }
    rmc_end_function_trace();
}

void serialize_GetCodepointPrevious(const char* text, const int* codepointSize) {
    rmc_start_function_trace(2, 392);
    int length_text = strlen(text) + 1;
    serialize_le(length_text);
    for(int i = 0; i < length_text; i++) {
        serialize_le(text[i]);
    }
    int length_codepointSize = 1 /* TODO: Specify length for codepointSize */;
    serialize_le(length_codepointSize);
    for(int i = 0; i < length_codepointSize; i++) {
        serialize_le(codepointSize[i]);
    }
    rmc_end_function_trace();
}

void serialize_TextCopy(const char* dst, const char* src) {
    rmc_start_function_trace(2, 393);
    int length_dst = strlen(dst) + 1;
    serialize_le(length_dst);
    for(int i = 0; i < length_dst; i++) {
        serialize_le(dst[i]);
    }
    int length_src = strlen(src) + 1;
    serialize_le(length_src);
    for(int i = 0; i < length_src; i++) {
        serialize_le(src[i]);
    }
    rmc_end_function_trace();
}

void serialize_TextIsEqual(const char* text1, const char* text2) {
    rmc_start_function_trace(2, 394);
    int length_text1 = strlen(text1) + 1;
    serialize_le(length_text1);
    for(int i = 0; i < length_text1; i++) {
        serialize_le(text1[i]);
    }
    int length_text2 = strlen(text2) + 1;
    serialize_le(length_text2);
    for(int i = 0; i < length_text2; i++) {
        serialize_le(text2[i]);
    }
    rmc_end_function_trace();
}

void serialize_TextLength(const char* text) {
    rmc_start_function_trace(2, 395);
    int length_text = strlen(text) + 1;
    serialize_le(length_text);
    for(int i = 0; i < length_text; i++) {
        serialize_le(text[i]);
    }
    rmc_end_function_trace();
}

void serialize_TextAppend(const char* text, const char* append, const int* position) {
    rmc_start_function_trace(2, 396);
    int length_text = strlen(text) + 1;
    serialize_le(length_text);
    for(int i = 0; i < length_text; i++) {
        serialize_le(text[i]);
    }
    int length_append = strlen(append) + 1;
    serialize_le(length_append);
    for(int i = 0; i < length_append; i++) {
        serialize_le(append[i]);
    }
    int length_position = 1 /* TODO: Specify length for position */;
    serialize_le(length_position);
    for(int i = 0; i < length_position; i++) {
        serialize_le(position[i]);
    }
    rmc_end_function_trace();
}

void serialize_TextFindIndex(const char* text, const char* find) {
    rmc_start_function_trace(2, 397);
    int length_text = strlen(text) + 1;
    serialize_le(length_text);
    for(int i = 0; i < length_text; i++) {
        serialize_le(text[i]);
    }
    int length_find = strlen(find) + 1;
    serialize_le(length_find);
    for(int i = 0; i < length_find; i++) {
        serialize_le(find[i]);
    }
    rmc_end_function_trace();
}

void serialize_TextToInteger(const char* text) {
    rmc_start_function_trace(2, 398);
    int length_text = strlen(text) + 1;
    serialize_le(length_text);
    for(int i = 0; i < length_text; i++) {
        serialize_le(text[i]);
    }
    rmc_end_function_trace();
}

void serialize_TextToFloat(const char* text) {
    rmc_start_function_trace(2, 399);
    int length_text = strlen(text) + 1;
    serialize_le(length_text);
    for(int i = 0; i < length_text; i++) {
        serialize_le(text[i]);
    }
    rmc_end_function_trace();
}

void serialize_DrawLine3D(const Vector3& startPos, const Vector3& endPos, const Color& color) {
    rmc_start_function_trace(2, 400);
    serialize_Vector3(startPos);
    serialize_Vector3(endPos);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawPoint3D(const Vector3& position, const Color& color) {
    rmc_start_function_trace(2, 401);
    serialize_Vector3(position);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawCircle3D(const Vector3& center, float radius, const Vector3& rotationAxis, float rotationAngle, const Color& color) {
    rmc_start_function_trace(2, 402);
    serialize_Vector3(center);
    serialize_le(radius);
    serialize_Vector3(rotationAxis);
    serialize_le(rotationAngle);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawTriangle3D(const Vector3& v1, const Vector3& v2, const Vector3& v3, const Color& color) {
    rmc_start_function_trace(2, 403);
    serialize_Vector3(v1);
    serialize_Vector3(v2);
    serialize_Vector3(v3);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawTriangleStrip3D(const Vector3* points, int pointCount, const Color& color) {
    rmc_start_function_trace(2, 404);
    int length_points = 1 /* TODO: Specify length for points */;
    serialize_le(length_points);
    for(int i = 0; i < length_points; i++) {
        serialize_Vector3(points[i]);
    }
    serialize_le(pointCount);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawCube(const Vector3& position, float width, float height, float length, const Color& color) {
    rmc_start_function_trace(2, 405);
    serialize_Vector3(position);
    serialize_le(width);
    serialize_le(height);
    serialize_le(length);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawCubeV(const Vector3& position, const Vector3& size, const Color& color) {
    rmc_start_function_trace(2, 406);
    serialize_Vector3(position);
    serialize_Vector3(size);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawCubeWires(const Vector3& position, float width, float height, float length, const Color& color) {
    rmc_start_function_trace(2, 407);
    serialize_Vector3(position);
    serialize_le(width);
    serialize_le(height);
    serialize_le(length);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawCubeWiresV(const Vector3& position, const Vector3& size, const Color& color) {
    rmc_start_function_trace(2, 408);
    serialize_Vector3(position);
    serialize_Vector3(size);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawSphere(const Vector3& centerPos, float radius, const Color& color) {
    rmc_start_function_trace(2, 409);
    serialize_Vector3(centerPos);
    serialize_le(radius);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawSphereEx(const Vector3& centerPos, float radius, int rings, int slices, const Color& color) {
    rmc_start_function_trace(2, 410);
    serialize_Vector3(centerPos);
    serialize_le(radius);
    serialize_le(rings);
    serialize_le(slices);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawSphereWires(const Vector3& centerPos, float radius, int rings, int slices, const Color& color) {
    rmc_start_function_trace(2, 411);
    serialize_Vector3(centerPos);
    serialize_le(radius);
    serialize_le(rings);
    serialize_le(slices);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawCylinder(const Vector3& position, float radiusTop, float radiusBottom, float height, int slices, const Color& color) {
    rmc_start_function_trace(2, 412);
    serialize_Vector3(position);
    serialize_le(radiusTop);
    serialize_le(radiusBottom);
    serialize_le(height);
    serialize_le(slices);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawCylinderEx(const Vector3& startPos, const Vector3& endPos, float startRadius, float endRadius, int sides, const Color& color) {
    rmc_start_function_trace(2, 413);
    serialize_Vector3(startPos);
    serialize_Vector3(endPos);
    serialize_le(startRadius);
    serialize_le(endRadius);
    serialize_le(sides);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawCylinderWires(const Vector3& position, float radiusTop, float radiusBottom, float height, int slices, const Color& color) {
    rmc_start_function_trace(2, 414);
    serialize_Vector3(position);
    serialize_le(radiusTop);
    serialize_le(radiusBottom);
    serialize_le(height);
    serialize_le(slices);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawCylinderWiresEx(const Vector3& startPos, const Vector3& endPos, float startRadius, float endRadius, int sides, const Color& color) {
    rmc_start_function_trace(2, 415);
    serialize_Vector3(startPos);
    serialize_Vector3(endPos);
    serialize_le(startRadius);
    serialize_le(endRadius);
    serialize_le(sides);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawCapsule(const Vector3& startPos, const Vector3& endPos, float radius, int slices, int rings, const Color& color) {
    rmc_start_function_trace(2, 416);
    serialize_Vector3(startPos);
    serialize_Vector3(endPos);
    serialize_le(radius);
    serialize_le(slices);
    serialize_le(rings);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawCapsuleWires(const Vector3& startPos, const Vector3& endPos, float radius, int slices, int rings, const Color& color) {
    rmc_start_function_trace(2, 417);
    serialize_Vector3(startPos);
    serialize_Vector3(endPos);
    serialize_le(radius);
    serialize_le(slices);
    serialize_le(rings);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawPlane(const Vector3& centerPos, const Vector2& size, const Color& color) {
    rmc_start_function_trace(2, 418);
    serialize_Vector3(centerPos);
    serialize_Vector2(size);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawRay(const Ray& ray, const Color& color) {
    rmc_start_function_trace(2, 419);
    serialize_Ray(ray);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawGrid(int slices, float spacing) {
    rmc_start_function_trace(2, 420);
    serialize_le(slices);
    serialize_le(spacing);
    rmc_end_function_trace();
}

void serialize_LoadModel(const char* fileName) {
    rmc_start_function_trace(2, 421);
    int length_fileName = strlen(fileName) + 1;
    serialize_le(length_fileName);
    for(int i = 0; i < length_fileName; i++) {
        serialize_le(fileName[i]);
    }
    rmc_end_function_trace();
}

void serialize_LoadModelFromMesh(const Mesh& mesh) {
    rmc_start_function_trace(2, 422);
    serialize_Mesh(mesh);
    rmc_end_function_trace();
}

void serialize_IsModelValid(const Model& model) {
    rmc_start_function_trace(2, 423);
    serialize_Model(model);
    rmc_end_function_trace();
}

void serialize_UnloadModel(const Model& model) {
    rmc_start_function_trace(2, 424);
    serialize_Model(model);
    rmc_end_function_trace();
}

void serialize_GetModelBoundingBox(const Model& model) {
    rmc_start_function_trace(2, 425);
    serialize_Model(model);
    rmc_end_function_trace();
}

void serialize_DrawModel(const Model& model, const Vector3& position, float scale, const Color& tint) {
    rmc_start_function_trace(2, 426);
    serialize_Model(model);
    serialize_Vector3(position);
    serialize_le(scale);
    serialize_Color(tint);
    rmc_end_function_trace();
}

void serialize_DrawModelEx(const Model& model, const Vector3& position, const Vector3& rotationAxis, float rotationAngle, const Vector3& scale, const Color& tint) {
    rmc_start_function_trace(2, 427);
    serialize_Model(model);
    serialize_Vector3(position);
    serialize_Vector3(rotationAxis);
    serialize_le(rotationAngle);
    serialize_Vector3(scale);
    serialize_Color(tint);
    rmc_end_function_trace();
}

void serialize_DrawModelWires(const Model& model, const Vector3& position, float scale, const Color& tint) {
    rmc_start_function_trace(2, 428);
    serialize_Model(model);
    serialize_Vector3(position);
    serialize_le(scale);
    serialize_Color(tint);
    rmc_end_function_trace();
}

void serialize_DrawModelWiresEx(const Model& model, const Vector3& position, const Vector3& rotationAxis, float rotationAngle, const Vector3& scale, const Color& tint) {
    rmc_start_function_trace(2, 429);
    serialize_Model(model);
    serialize_Vector3(position);
    serialize_Vector3(rotationAxis);
    serialize_le(rotationAngle);
    serialize_Vector3(scale);
    serialize_Color(tint);
    rmc_end_function_trace();
}

void serialize_DrawModelPoints(const Model& model, const Vector3& position, float scale, const Color& tint) {
    rmc_start_function_trace(2, 430);
    serialize_Model(model);
    serialize_Vector3(position);
    serialize_le(scale);
    serialize_Color(tint);
    rmc_end_function_trace();
}

void serialize_DrawModelPointsEx(const Model& model, const Vector3& position, const Vector3& rotationAxis, float rotationAngle, const Vector3& scale, const Color& tint) {
    rmc_start_function_trace(2, 431);
    serialize_Model(model);
    serialize_Vector3(position);
    serialize_Vector3(rotationAxis);
    serialize_le(rotationAngle);
    serialize_Vector3(scale);
    serialize_Color(tint);
    rmc_end_function_trace();
}

void serialize_DrawBoundingBox(const BoundingBox& box, const Color& color) {
    rmc_start_function_trace(2, 432);
    serialize_BoundingBox(box);
    serialize_Color(color);
    rmc_end_function_trace();
}

void serialize_DrawBillboard(Camera camera, Texture2D texture, const Vector3& position, float scale, const Color& tint) {
    rmc_start_function_trace(2, 433);
    serialize_le(camera);
    serialize_le(texture);
    serialize_Vector3(position);
    serialize_le(scale);
    serialize_Color(tint);
    rmc_end_function_trace();
}

void serialize_DrawBillboardRec(Camera camera, Texture2D texture, const Rectangle& source, const Vector3& position, const Vector2& size, const Color& tint) {
    rmc_start_function_trace(2, 434);
    serialize_le(camera);
    serialize_le(texture);
    serialize_Rectangle(source);
    serialize_Vector3(position);
    serialize_Vector2(size);
    serialize_Color(tint);
    rmc_end_function_trace();
}

void serialize_DrawBillboardPro(Camera camera, Texture2D texture, const Rectangle& source, const Vector3& position, const Vector3& up, const Vector2& size, const Vector2& origin, float rotation, const Color& tint) {
    rmc_start_function_trace(2, 435);
    serialize_le(camera);
    serialize_le(texture);
    serialize_Rectangle(source);
    serialize_Vector3(position);
    serialize_Vector3(up);
    serialize_Vector2(size);
    serialize_Vector2(origin);
    serialize_le(rotation);
    serialize_Color(tint);
    rmc_end_function_trace();
}

void serialize_UploadMesh(const Mesh* mesh, bool dynamic) {
    rmc_start_function_trace(2, 436);
    int length_mesh = 1 /* TODO: Specify length for mesh */;
    serialize_le(length_mesh);
    for(int i = 0; i < length_mesh; i++) {
        serialize_Mesh(mesh[i]);
    }
    serialize_le(dynamic);
    rmc_end_function_trace();
}

void serialize_UpdateMeshBuffer(const Mesh& mesh, int index, const void* data, int dataSize, int offset) {
    rmc_start_function_trace(2, 437);
    serialize_Mesh(mesh);
    serialize_le(index);
    // Skipping data (type: const void*) - not serializable
    serialize_le(dataSize);
    serialize_le(offset);
    rmc_end_function_trace();
}

void serialize_UnloadMesh(const Mesh& mesh) {
    rmc_start_function_trace(2, 438);
    serialize_Mesh(mesh);
    rmc_end_function_trace();
}

void serialize_DrawMesh(const Mesh& mesh, const Material& material, const Matrix& transform) {
    rmc_start_function_trace(2, 439);
    serialize_Mesh(mesh);
    serialize_Material(material);
    serialize_Matrix(transform);
    rmc_end_function_trace();
}

void serialize_DrawMeshInstanced(const Mesh& mesh, const Material& material, const Matrix* transforms, int instances) {
    rmc_start_function_trace(2, 440);
    serialize_Mesh(mesh);
    serialize_Material(material);
    int length_transforms = 1 /* TODO: Specify length for transforms */;
    serialize_le(length_transforms);
    for(int i = 0; i < length_transforms; i++) {
        serialize_Matrix(transforms[i]);
    }
    serialize_le(instances);
    rmc_end_function_trace();
}

void serialize_GetMeshBoundingBox(const Mesh& mesh) {
    rmc_start_function_trace(2, 441);
    serialize_Mesh(mesh);
    rmc_end_function_trace();
}

void serialize_GenMeshTangents(const Mesh* mesh) {
    rmc_start_function_trace(2, 442);
    int length_mesh = 1 /* TODO: Specify length for mesh */;
    serialize_le(length_mesh);
    for(int i = 0; i < length_mesh; i++) {
        serialize_Mesh(mesh[i]);
    }
    rmc_end_function_trace();
}

void serialize_ExportMesh(const Mesh& mesh, const char* fileName) {
    rmc_start_function_trace(2, 443);
    serialize_Mesh(mesh);
    int length_fileName = strlen(fileName) + 1;
    serialize_le(length_fileName);
    for(int i = 0; i < length_fileName; i++) {
        serialize_le(fileName[i]);
    }
    rmc_end_function_trace();
}

void serialize_ExportMeshAsCode(const Mesh& mesh, const char* fileName) {
    rmc_start_function_trace(2, 444);
    serialize_Mesh(mesh);
    int length_fileName = strlen(fileName) + 1;
    serialize_le(length_fileName);
    for(int i = 0; i < length_fileName; i++) {
        serialize_le(fileName[i]);
    }
    rmc_end_function_trace();
}

void serialize_GenMeshPoly(int sides, float radius) {
    rmc_start_function_trace(2, 445);
    serialize_le(sides);
    serialize_le(radius);
    rmc_end_function_trace();
}

void serialize_GenMeshPlane(float width, float length, int resX, int resZ) {
    rmc_start_function_trace(2, 446);
    serialize_le(width);
    serialize_le(length);
    serialize_le(resX);
    serialize_le(resZ);
    rmc_end_function_trace();
}

void serialize_GenMeshCube(float width, float height, float length) {
    rmc_start_function_trace(2, 447);
    serialize_le(width);
    serialize_le(height);
    serialize_le(length);
    rmc_end_function_trace();
}

void serialize_GenMeshSphere(float radius, int rings, int slices) {
    rmc_start_function_trace(2, 448);
    serialize_le(radius);
    serialize_le(rings);
    serialize_le(slices);
    rmc_end_function_trace();
}

void serialize_GenMeshHemiSphere(float radius, int rings, int slices) {
    rmc_start_function_trace(2, 449);
    serialize_le(radius);
    serialize_le(rings);
    serialize_le(slices);
    rmc_end_function_trace();
}

void serialize_GenMeshCylinder(float radius, float height, int slices) {
    rmc_start_function_trace(2, 450);
    serialize_le(radius);
    serialize_le(height);
    serialize_le(slices);
    rmc_end_function_trace();
}

void serialize_GenMeshCone(float radius, float height, int slices) {
    rmc_start_function_trace(2, 451);
    serialize_le(radius);
    serialize_le(height);
    serialize_le(slices);
    rmc_end_function_trace();
}

void serialize_GenMeshTorus(float radius, float size, int radSeg, int sides) {
    rmc_start_function_trace(2, 452);
    serialize_le(radius);
    serialize_le(size);
    serialize_le(radSeg);
    serialize_le(sides);
    rmc_end_function_trace();
}

void serialize_GenMeshKnot(float radius, float size, int radSeg, int sides) {
    rmc_start_function_trace(2, 453);
    serialize_le(radius);
    serialize_le(size);
    serialize_le(radSeg);
    serialize_le(sides);
    rmc_end_function_trace();
}

void serialize_GenMeshHeightmap(const Image& heightmap, const Vector3& size) {
    rmc_start_function_trace(2, 454);
    serialize_Image(heightmap);
    serialize_Vector3(size);
    rmc_end_function_trace();
}

void serialize_GenMeshCubicmap(const Image& cubicmap, const Vector3& cubeSize) {
    rmc_start_function_trace(2, 455);
    serialize_Image(cubicmap);
    serialize_Vector3(cubeSize);
    rmc_end_function_trace();
}

void serialize_LoadMaterialDefault() {
    rmc_start_function_trace(2, 456);
    rmc_end_function_trace();
}

void serialize_IsMaterialValid(const Material& material) {
    rmc_start_function_trace(2, 457);
    serialize_Material(material);
    rmc_end_function_trace();
}

void serialize_UnloadMaterial(const Material& material) {
    rmc_start_function_trace(2, 458);
    serialize_Material(material);
    rmc_end_function_trace();
}

void serialize_SetMaterialTexture(const Material* material, int mapType, Texture2D texture) {
    rmc_start_function_trace(2, 459);
    int length_material = 1 /* TODO: Specify length for material */;
    serialize_le(length_material);
    for(int i = 0; i < length_material; i++) {
        serialize_Material(material[i]);
    }
    serialize_le(mapType);
    serialize_le(texture);
    rmc_end_function_trace();
}

void serialize_SetModelMeshMaterial(const Model* model, int meshId, int materialId) {
    rmc_start_function_trace(2, 460);
    int length_model = 1 /* TODO: Specify length for model */;
    serialize_le(length_model);
    for(int i = 0; i < length_model; i++) {
        serialize_Model(model[i]);
    }
    serialize_le(meshId);
    serialize_le(materialId);
    rmc_end_function_trace();
}

void serialize_UpdateModelAnimation(const Model& model, const ModelAnimation& anim, int frame) {
    rmc_start_function_trace(2, 461);
    serialize_Model(model);
    serialize_ModelAnimation(anim);
    serialize_le(frame);
    rmc_end_function_trace();
}

void serialize_UpdateModelAnimationBones(const Model& model, const ModelAnimation& anim, int frame) {
    rmc_start_function_trace(2, 462);
    serialize_Model(model);
    serialize_ModelAnimation(anim);
    serialize_le(frame);
    rmc_end_function_trace();
}

void serialize_UnloadModelAnimation(const ModelAnimation& anim) {
    rmc_start_function_trace(2, 463);
    serialize_ModelAnimation(anim);
    rmc_end_function_trace();
}

void serialize_UnloadModelAnimations(const ModelAnimation* animations, int animCount) {
    rmc_start_function_trace(2, 464);
    int length_animations = 1 /* TODO: Specify length for animations */;
    serialize_le(length_animations);
    for(int i = 0; i < length_animations; i++) {
        serialize_ModelAnimation(animations[i]);
    }
    serialize_le(animCount);
    rmc_end_function_trace();
}

void serialize_IsModelAnimationValid(const Model& model, const ModelAnimation& anim) {
    rmc_start_function_trace(2, 465);
    serialize_Model(model);
    serialize_ModelAnimation(anim);
    rmc_end_function_trace();
}

void serialize_CheckCollisionSpheres(const Vector3& center1, float radius1, const Vector3& center2, float radius2) {
    rmc_start_function_trace(2, 466);
    serialize_Vector3(center1);
    serialize_le(radius1);
    serialize_Vector3(center2);
    serialize_le(radius2);
    rmc_end_function_trace();
}

void serialize_CheckCollisionBoxes(const BoundingBox& box1, const BoundingBox& box2) {
    rmc_start_function_trace(2, 467);
    serialize_BoundingBox(box1);
    serialize_BoundingBox(box2);
    rmc_end_function_trace();
}

void serialize_CheckCollisionBoxSphere(const BoundingBox& box, const Vector3& center, float radius) {
    rmc_start_function_trace(2, 468);
    serialize_BoundingBox(box);
    serialize_Vector3(center);
    serialize_le(radius);
    rmc_end_function_trace();
}

void serialize_GetRayCollisionSphere(const Ray& ray, const Vector3& center, float radius) {
    rmc_start_function_trace(2, 469);
    serialize_Ray(ray);
    serialize_Vector3(center);
    serialize_le(radius);
    rmc_end_function_trace();
}

void serialize_GetRayCollisionBox(const Ray& ray, const BoundingBox& box) {
    rmc_start_function_trace(2, 470);
    serialize_Ray(ray);
    serialize_BoundingBox(box);
    rmc_end_function_trace();
}

void serialize_GetRayCollisionMesh(const Ray& ray, const Mesh& mesh, const Matrix& transform) {
    rmc_start_function_trace(2, 471);
    serialize_Ray(ray);
    serialize_Mesh(mesh);
    serialize_Matrix(transform);
    rmc_end_function_trace();
}

void serialize_GetRayCollisionTriangle(const Ray& ray, const Vector3& p1, const Vector3& p2, const Vector3& p3) {
    rmc_start_function_trace(2, 472);
    serialize_Ray(ray);
    serialize_Vector3(p1);
    serialize_Vector3(p2);
    serialize_Vector3(p3);
    rmc_end_function_trace();
}

void serialize_GetRayCollisionQuad(const Ray& ray, const Vector3& p1, const Vector3& p2, const Vector3& p3, const Vector3& p4) {
    rmc_start_function_trace(2, 473);
    serialize_Ray(ray);
    serialize_Vector3(p1);
    serialize_Vector3(p2);
    serialize_Vector3(p3);
    serialize_Vector3(p4);
    rmc_end_function_trace();
}

void serialize_InitAudioDevice() {
    rmc_start_function_trace(2, 474);
    rmc_end_function_trace();
}

void serialize_CloseAudioDevice() {
    rmc_start_function_trace(2, 475);
    rmc_end_function_trace();
}

void serialize_IsAudioDeviceReady() {
    rmc_start_function_trace(2, 476);
    rmc_end_function_trace();
}

void serialize_SetMasterVolume(float volume) {
    rmc_start_function_trace(2, 477);
    serialize_le(volume);
    rmc_end_function_trace();
}

void serialize_GetMasterVolume() {
    rmc_start_function_trace(2, 478);
    rmc_end_function_trace();
}

void serialize_LoadWave(const char* fileName) {
    rmc_start_function_trace(2, 479);
    int length_fileName = strlen(fileName) + 1;
    serialize_le(length_fileName);
    for(int i = 0; i < length_fileName; i++) {
        serialize_le(fileName[i]);
    }
    rmc_end_function_trace();
}

void serialize_LoadWaveFromMemory(const char* fileType, const unsigned char* fileData, int dataSize) {
    rmc_start_function_trace(2, 480);
    int length_fileType = strlen(fileType) + 1;
    serialize_le(length_fileType);
    for(int i = 0; i < length_fileType; i++) {
        serialize_le(fileType[i]);
    }
    int length_fileData = 1 /* TODO: Specify length for fileData */;
    serialize_le(length_fileData);
    for(int i = 0; i < length_fileData; i++) {
        serialize_le(fileData[i]);
    }
    serialize_le(dataSize);
    rmc_end_function_trace();
}

void serialize_IsWaveValid(const Wave& wave) {
    rmc_start_function_trace(2, 481);
    serialize_Wave(wave);
    rmc_end_function_trace();
}

void serialize_LoadSound(const char* fileName) {
    rmc_start_function_trace(2, 482);
    int length_fileName = strlen(fileName) + 1;
    serialize_le(length_fileName);
    for(int i = 0; i < length_fileName; i++) {
        serialize_le(fileName[i]);
    }
    rmc_end_function_trace();
}

void serialize_LoadSoundFromWave(const Wave& wave) {
    rmc_start_function_trace(2, 483);
    serialize_Wave(wave);
    rmc_end_function_trace();
}

void serialize_LoadSoundAlias(const Sound& source) {
    rmc_start_function_trace(2, 484);
    serialize_Sound(source);
    rmc_end_function_trace();
}

void serialize_IsSoundValid(const Sound& sound) {
    rmc_start_function_trace(2, 485);
    serialize_Sound(sound);
    rmc_end_function_trace();
}

void serialize_UpdateSound(const Sound& sound, const void* data, int sampleCount) {
    rmc_start_function_trace(2, 486);
    serialize_Sound(sound);
    // Skipping data (type: const void*) - not serializable
    serialize_le(sampleCount);
    rmc_end_function_trace();
}

void serialize_UnloadWave(const Wave& wave) {
    rmc_start_function_trace(2, 487);
    serialize_Wave(wave);
    rmc_end_function_trace();
}

void serialize_UnloadSound(const Sound& sound) {
    rmc_start_function_trace(2, 488);
    serialize_Sound(sound);
    rmc_end_function_trace();
}

void serialize_UnloadSoundAlias(const Sound& alias) {
    rmc_start_function_trace(2, 489);
    serialize_Sound(alias);
    rmc_end_function_trace();
}

void serialize_ExportWave(const Wave& wave, const char* fileName) {
    rmc_start_function_trace(2, 490);
    serialize_Wave(wave);
    int length_fileName = strlen(fileName) + 1;
    serialize_le(length_fileName);
    for(int i = 0; i < length_fileName; i++) {
        serialize_le(fileName[i]);
    }
    rmc_end_function_trace();
}

void serialize_ExportWaveAsCode(const Wave& wave, const char* fileName) {
    rmc_start_function_trace(2, 491);
    serialize_Wave(wave);
    int length_fileName = strlen(fileName) + 1;
    serialize_le(length_fileName);
    for(int i = 0; i < length_fileName; i++) {
        serialize_le(fileName[i]);
    }
    rmc_end_function_trace();
}

void serialize_PlaySound(const Sound& sound) {
    rmc_start_function_trace(2, 492);
    serialize_Sound(sound);
    rmc_end_function_trace();
}

void serialize_StopSound(const Sound& sound) {
    rmc_start_function_trace(2, 493);
    serialize_Sound(sound);
    rmc_end_function_trace();
}

void serialize_PauseSound(const Sound& sound) {
    rmc_start_function_trace(2, 494);
    serialize_Sound(sound);
    rmc_end_function_trace();
}

void serialize_ResumeSound(const Sound& sound) {
    rmc_start_function_trace(2, 495);
    serialize_Sound(sound);
    rmc_end_function_trace();
}

void serialize_IsSoundPlaying(const Sound& sound) {
    rmc_start_function_trace(2, 496);
    serialize_Sound(sound);
    rmc_end_function_trace();
}

void serialize_SetSoundVolume(const Sound& sound, float volume) {
    rmc_start_function_trace(2, 497);
    serialize_Sound(sound);
    serialize_le(volume);
    rmc_end_function_trace();
}

void serialize_SetSoundPitch(const Sound& sound, float pitch) {
    rmc_start_function_trace(2, 498);
    serialize_Sound(sound);
    serialize_le(pitch);
    rmc_end_function_trace();
}

void serialize_SetSoundPan(const Sound& sound, float pan) {
    rmc_start_function_trace(2, 499);
    serialize_Sound(sound);
    serialize_le(pan);
    rmc_end_function_trace();
}

void serialize_WaveCopy(const Wave& wave) {
    rmc_start_function_trace(2, 500);
    serialize_Wave(wave);
    rmc_end_function_trace();
}

void serialize_WaveCrop(const Wave* wave, int initFrame, int finalFrame) {
    rmc_start_function_trace(2, 501);
    int length_wave = 1 /* TODO: Specify length for wave */;
    serialize_le(length_wave);
    for(int i = 0; i < length_wave; i++) {
        serialize_Wave(wave[i]);
    }
    serialize_le(initFrame);
    serialize_le(finalFrame);
    rmc_end_function_trace();
}

void serialize_WaveFormat(const Wave* wave, int sampleRate, int sampleSize, int channels) {
    rmc_start_function_trace(2, 502);
    int length_wave = 1 /* TODO: Specify length for wave */;
    serialize_le(length_wave);
    for(int i = 0; i < length_wave; i++) {
        serialize_Wave(wave[i]);
    }
    serialize_le(sampleRate);
    serialize_le(sampleSize);
    serialize_le(channels);
    rmc_end_function_trace();
}

void serialize_UnloadWaveSamples(const float* samples) {
    rmc_start_function_trace(2, 503);
    int length_samples = 1 /* TODO: Specify length for samples */;
    serialize_le(length_samples);
    for(int i = 0; i < length_samples; i++) {
        serialize_le(samples[i]);
    }
    rmc_end_function_trace();
}

void serialize_LoadMusicStream(const char* fileName) {
    rmc_start_function_trace(2, 504);
    int length_fileName = strlen(fileName) + 1;
    serialize_le(length_fileName);
    for(int i = 0; i < length_fileName; i++) {
        serialize_le(fileName[i]);
    }
    rmc_end_function_trace();
}

void serialize_LoadMusicStreamFromMemory(const char* fileType, const unsigned char* data, int dataSize) {
    rmc_start_function_trace(2, 505);
    int length_fileType = strlen(fileType) + 1;
    serialize_le(length_fileType);
    for(int i = 0; i < length_fileType; i++) {
        serialize_le(fileType[i]);
    }
    int length_data = 1 /* TODO: Specify length for data */;
    serialize_le(length_data);
    for(int i = 0; i < length_data; i++) {
        serialize_le(data[i]);
    }
    serialize_le(dataSize);
    rmc_end_function_trace();
}

void serialize_IsMusicValid(const Music& music) {
    rmc_start_function_trace(2, 506);
    serialize_Music(music);
    rmc_end_function_trace();
}

void serialize_UnloadMusicStream(const Music& music) {
    rmc_start_function_trace(2, 507);
    serialize_Music(music);
    rmc_end_function_trace();
}

void serialize_PlayMusicStream(const Music& music) {
    rmc_start_function_trace(2, 508);
    serialize_Music(music);
    rmc_end_function_trace();
}

void serialize_IsMusicStreamPlaying(const Music& music) {
    rmc_start_function_trace(2, 509);
    serialize_Music(music);
    rmc_end_function_trace();
}

void serialize_UpdateMusicStream(const Music& music) {
    rmc_start_function_trace(2, 510);
    serialize_Music(music);
    rmc_end_function_trace();
}

void serialize_StopMusicStream(const Music& music) {
    rmc_start_function_trace(2, 511);
    serialize_Music(music);
    rmc_end_function_trace();
}

void serialize_PauseMusicStream(const Music& music) {
    rmc_start_function_trace(2, 512);
    serialize_Music(music);
    rmc_end_function_trace();
}

void serialize_ResumeMusicStream(const Music& music) {
    rmc_start_function_trace(2, 513);
    serialize_Music(music);
    rmc_end_function_trace();
}

void serialize_SeekMusicStream(const Music& music, float position) {
    rmc_start_function_trace(2, 514);
    serialize_Music(music);
    serialize_le(position);
    rmc_end_function_trace();
}

void serialize_SetMusicVolume(const Music& music, float volume) {
    rmc_start_function_trace(2, 515);
    serialize_Music(music);
    serialize_le(volume);
    rmc_end_function_trace();
}

void serialize_SetMusicPitch(const Music& music, float pitch) {
    rmc_start_function_trace(2, 516);
    serialize_Music(music);
    serialize_le(pitch);
    rmc_end_function_trace();
}

void serialize_SetMusicPan(const Music& music, float pan) {
    rmc_start_function_trace(2, 517);
    serialize_Music(music);
    serialize_le(pan);
    rmc_end_function_trace();
}

void serialize_GetMusicTimeLength(const Music& music) {
    rmc_start_function_trace(2, 518);
    serialize_Music(music);
    rmc_end_function_trace();
}

void serialize_GetMusicTimePlayed(const Music& music) {
    rmc_start_function_trace(2, 519);
    serialize_Music(music);
    rmc_end_function_trace();
}

void serialize_LoadAudioStream(unsigned int sampleRate, unsigned int sampleSize, unsigned int channels) {
    rmc_start_function_trace(2, 520);
    serialize_le(sampleRate);
    serialize_le(sampleSize);
    serialize_le(channels);
    rmc_end_function_trace();
}

void serialize_IsAudioStreamValid(const AudioStream& stream) {
    rmc_start_function_trace(2, 521);
    serialize_AudioStream(stream);
    rmc_end_function_trace();
}

void serialize_UnloadAudioStream(const AudioStream& stream) {
    rmc_start_function_trace(2, 522);
    serialize_AudioStream(stream);
    rmc_end_function_trace();
}

void serialize_UpdateAudioStream(const AudioStream& stream, const void* data, int frameCount) {
    rmc_start_function_trace(2, 523);
    serialize_AudioStream(stream);
    // Skipping data (type: const void*) - not serializable
    serialize_le(frameCount);
    rmc_end_function_trace();
}

void serialize_IsAudioStreamProcessed(const AudioStream& stream) {
    rmc_start_function_trace(2, 524);
    serialize_AudioStream(stream);
    rmc_end_function_trace();
}

void serialize_PlayAudioStream(const AudioStream& stream) {
    rmc_start_function_trace(2, 525);
    serialize_AudioStream(stream);
    rmc_end_function_trace();
}

void serialize_PauseAudioStream(const AudioStream& stream) {
    rmc_start_function_trace(2, 526);
    serialize_AudioStream(stream);
    rmc_end_function_trace();
}

void serialize_ResumeAudioStream(const AudioStream& stream) {
    rmc_start_function_trace(2, 527);
    serialize_AudioStream(stream);
    rmc_end_function_trace();
}

void serialize_IsAudioStreamPlaying(const AudioStream& stream) {
    rmc_start_function_trace(2, 528);
    serialize_AudioStream(stream);
    rmc_end_function_trace();
}

void serialize_StopAudioStream(const AudioStream& stream) {
    rmc_start_function_trace(2, 529);
    serialize_AudioStream(stream);
    rmc_end_function_trace();
}

void serialize_SetAudioStreamVolume(const AudioStream& stream, float volume) {
    rmc_start_function_trace(2, 530);
    serialize_AudioStream(stream);
    serialize_le(volume);
    rmc_end_function_trace();
}

void serialize_SetAudioStreamPitch(const AudioStream& stream, float pitch) {
    rmc_start_function_trace(2, 531);
    serialize_AudioStream(stream);
    serialize_le(pitch);
    rmc_end_function_trace();
}

void serialize_SetAudioStreamPan(const AudioStream& stream, float pan) {
    rmc_start_function_trace(2, 532);
    serialize_AudioStream(stream);
    serialize_le(pan);
    rmc_end_function_trace();
}

void serialize_SetAudioStreamBufferSizeDefault(int size) {
    rmc_start_function_trace(2, 533);
    serialize_le(size);
    rmc_end_function_trace();
}

void serialize_SetAudioStreamCallback(const AudioStream& stream, AudioCallback callback) {
    rmc_start_function_trace(2, 534);
    serialize_AudioStream(stream);
    serialize_le(callback);
    rmc_end_function_trace();
}

void serialize_AttachAudioStreamProcessor(const AudioStream& stream, AudioCallback processor) {
    rmc_start_function_trace(2, 535);
    serialize_AudioStream(stream);
    serialize_le(processor);
    rmc_end_function_trace();
}

void serialize_DetachAudioStreamProcessor(const AudioStream& stream, AudioCallback processor) {
    rmc_start_function_trace(2, 536);
    serialize_AudioStream(stream);
    serialize_le(processor);
    rmc_end_function_trace();
}

void serialize_AttachAudioMixedProcessor(AudioCallback processor) {
    rmc_start_function_trace(2, 537);
    serialize_le(processor);
    rmc_end_function_trace();
}

void serialize_DetachAudioMixedProcessor(AudioCallback processor) {
    rmc_start_function_trace(2, 538);
    serialize_le(processor);
    rmc_end_function_trace();
}

