#include "raylib_deserialization.h"

#include <iostream>

Vector2 deserialize_Vector2() {
    Vector2 s;
    s.x = deserialize_le<float>();
    s.y = deserialize_le<float>();
    return s;
}

Vector3 deserialize_Vector3() {
    Vector3 s;
    s.x = deserialize_le<float>();
    s.y = deserialize_le<float>();
    s.z = deserialize_le<float>();
    return s;
}

Vector4 deserialize_Vector4() {
    Vector4 s;
    s.x = deserialize_le<float>();
    s.y = deserialize_le<float>();
    s.z = deserialize_le<float>();
    s.w = deserialize_le<float>();
    return s;
}

Matrix deserialize_Matrix() {
    Matrix s;
    s.m0 = deserialize_le<float>();
    s.m4 = deserialize_le<float>();
    s.m8 = deserialize_le<float>();
    s.m12 = deserialize_le<float>();
    s.m1 = deserialize_le<float>();
    s.m5 = deserialize_le<float>();
    s.m9 = deserialize_le<float>();
    s.m13 = deserialize_le<float>();
    s.m2 = deserialize_le<float>();
    s.m6 = deserialize_le<float>();
    s.m10 = deserialize_le<float>();
    s.m14 = deserialize_le<float>();
    s.m3 = deserialize_le<float>();
    s.m7 = deserialize_le<float>();
    s.m11 = deserialize_le<float>();
    s.m15 = deserialize_le<float>();
    return s;
}

Color deserialize_Color() {
    Color s;
    s.r = deserialize_le<unsigned char>();
    s.g = deserialize_le<unsigned char>();
    s.b = deserialize_le<unsigned char>();
    s.a = deserialize_le<unsigned char>();
    return s;
}

Rectangle deserialize_Rectangle() {
    Rectangle s;
    s.x = deserialize_le<float>();
    s.y = deserialize_le<float>();
    s.width = deserialize_le<float>();
    s.height = deserialize_le<float>();
    return s;
}

Image deserialize_Image() {
    Image s;
    // Skipping data (type: void*) - not deserializable
    s.data = nullptr;
    s.width = deserialize_le<int>();
    s.height = deserialize_le<int>();
    s.mipmaps = deserialize_le<int>();
    s.format = deserialize_le<int>();
    return s;
}

Texture deserialize_Texture() {
    Texture s;
    s.id = deserialize_le<unsigned int>();
    s.width = deserialize_le<int>();
    s.height = deserialize_le<int>();
    s.mipmaps = deserialize_le<int>();
    s.format = deserialize_le<int>();
    return s;
}

RenderTexture deserialize_RenderTexture() {
    RenderTexture s;
    s.id = deserialize_le<unsigned int>();
    s.texture = deserialize_Texture();
    s.depth = deserialize_Texture();
    return s;
}

NPatchInfo deserialize_NPatchInfo() {
    NPatchInfo s;
    s.source = deserialize_Rectangle();
    s.left = deserialize_le<int>();
    s.top = deserialize_le<int>();
    s.right = deserialize_le<int>();
    s.bottom = deserialize_le<int>();
    s.layout = deserialize_le<int>();
    return s;
}

GlyphInfo deserialize_GlyphInfo() {
    GlyphInfo s;
    s.value = deserialize_le<int>();
    s.offsetX = deserialize_le<int>();
    s.offsetY = deserialize_le<int>();
    s.advanceX = deserialize_le<int>();
    s.image = deserialize_Image();
    return s;
}

Font deserialize_Font() {
    Font s;
    s.baseSize = deserialize_le<int>();
    s.glyphCount = deserialize_le<int>();
    s.glyphPadding = deserialize_le<int>();
    s.texture = deserialize_le<Texture2D>();
    int length_recs = deserialize_le<int>();
    s.recs = new Rectangle[length_recs];
    for(int i = 0; i < length_recs; i++) {
        s.recs[i] = deserialize_Rectangle();
    }
    int length_glyphs = deserialize_le<int>();
    s.glyphs = new GlyphInfo[length_glyphs];
    for(int i = 0; i < length_glyphs; i++) {
        s.glyphs[i] = deserialize_GlyphInfo();
    }
    return s;
}

Camera3D deserialize_Camera3D() {
    Camera3D s;
    s.position = deserialize_Vector3();
    s.target = deserialize_Vector3();
    s.up = deserialize_Vector3();
    s.fovy = deserialize_le<float>();
    s.projection = deserialize_le<int>();
    return s;
}

Camera2D deserialize_Camera2D() {
    Camera2D s;
    s.offset = deserialize_Vector2();
    s.target = deserialize_Vector2();
    s.rotation = deserialize_le<float>();
    s.zoom = deserialize_le<float>();
    return s;
}

Mesh deserialize_Mesh() {
    Mesh s;
    s.vertexCount = deserialize_le<int>();
    s.triangleCount = deserialize_le<int>();
    int length_vertices = deserialize_le<int>();
    s.vertices = new float[length_vertices];
    for(int i = 0; i < length_vertices; i++) {
        s.vertices[i] = deserialize_le<float>();
    }
    int length_texcoords = deserialize_le<int>();
    s.texcoords = new float[length_texcoords];
    for(int i = 0; i < length_texcoords; i++) {
        s.texcoords[i] = deserialize_le<float>();
    }
    int length_texcoords2 = deserialize_le<int>();
    s.texcoords2 = new float[length_texcoords2];
    for(int i = 0; i < length_texcoords2; i++) {
        s.texcoords2[i] = deserialize_le<float>();
    }
    int length_normals = deserialize_le<int>();
    s.normals = new float[length_normals];
    for(int i = 0; i < length_normals; i++) {
        s.normals[i] = deserialize_le<float>();
    }
    int length_tangents = deserialize_le<int>();
    s.tangents = new float[length_tangents];
    for(int i = 0; i < length_tangents; i++) {
        s.tangents[i] = deserialize_le<float>();
    }
    int length_colors = deserialize_le<int>();
    s.colors = new unsigned char[length_colors];
    for(int i = 0; i < length_colors; i++) {
        s.colors[i] = deserialize_le<unsigned char>();
    }
    int length_indices = deserialize_le<int>();
    s.indices = new unsigned short[length_indices];
    for(int i = 0; i < length_indices; i++) {
        s.indices[i] = deserialize_le<unsigned short>();
    }
    int length_animVertices = deserialize_le<int>();
    s.animVertices = new float[length_animVertices];
    for(int i = 0; i < length_animVertices; i++) {
        s.animVertices[i] = deserialize_le<float>();
    }
    int length_animNormals = deserialize_le<int>();
    s.animNormals = new float[length_animNormals];
    for(int i = 0; i < length_animNormals; i++) {
        s.animNormals[i] = deserialize_le<float>();
    }
    int length_boneIds = deserialize_le<int>();
    s.boneIds = new unsigned char[length_boneIds];
    for(int i = 0; i < length_boneIds; i++) {
        s.boneIds[i] = deserialize_le<unsigned char>();
    }
    int length_boneWeights = deserialize_le<int>();
    s.boneWeights = new float[length_boneWeights];
    for(int i = 0; i < length_boneWeights; i++) {
        s.boneWeights[i] = deserialize_le<float>();
    }
    int length_boneMatrices = deserialize_le<int>();
    s.boneMatrices = new Matrix[length_boneMatrices];
    for(int i = 0; i < length_boneMatrices; i++) {
        s.boneMatrices[i] = deserialize_Matrix();
    }
    s.boneCount = deserialize_le<int>();
    s.vaoId = deserialize_le<unsigned int>();
    int length_vboId = deserialize_le<int>();
    s.vboId = new unsigned int[length_vboId];
    for(int i = 0; i < length_vboId; i++) {
        s.vboId[i] = deserialize_le<unsigned int>();
    }
    return s;
}

Shader deserialize_Shader() {
    Shader s;
    s.id = deserialize_le<unsigned int>();
    int length_locs = deserialize_le<int>();
    s.locs = new int[length_locs];
    for(int i = 0; i < length_locs; i++) {
        s.locs[i] = deserialize_le<int>();
    }
    return s;
}

MaterialMap deserialize_MaterialMap() {
    MaterialMap s;
    s.texture = deserialize_le<Texture2D>();
    s.color = deserialize_Color();
    s.value = deserialize_le<float>();
    return s;
}

Material deserialize_Material() {
    Material s;
    s.shader = deserialize_Shader();
    int length_maps = deserialize_le<int>();
    s.maps = new MaterialMap[length_maps];
    for(int i = 0; i < length_maps; i++) {
        s.maps[i] = deserialize_MaterialMap();
    }
    for(int i = 0; i < 4; i++) { 
        s.params[i] = deserialize_le<float>();
    }
    return s;
}

Transform deserialize_Transform() {
    Transform s;
    s.translation = deserialize_Vector3();
    s.rotation = deserialize_le<Quaternion>();
    s.scale = deserialize_Vector3();
    return s;
}

BoneInfo deserialize_BoneInfo() {
    BoneInfo s;
    for(int i = 0; i < 32; i++) { 
        s.name[i] = deserialize_le<char>();
    }
    s.parent = deserialize_le<int>();
    return s;
}

Model deserialize_Model() {
    Model s;
    s.transform = deserialize_Matrix();
    s.meshCount = deserialize_le<int>();
    s.materialCount = deserialize_le<int>();
    int length_meshes = deserialize_le<int>();
    s.meshes = new Mesh[length_meshes];
    for(int i = 0; i < length_meshes; i++) {
        s.meshes[i] = deserialize_Mesh();
    }
    int length_materials = deserialize_le<int>();
    s.materials = new Material[length_materials];
    for(int i = 0; i < length_materials; i++) {
        s.materials[i] = deserialize_Material();
    }
    int length_meshMaterial = deserialize_le<int>();
    s.meshMaterial = new int[length_meshMaterial];
    for(int i = 0; i < length_meshMaterial; i++) {
        s.meshMaterial[i] = deserialize_le<int>();
    }
    s.boneCount = deserialize_le<int>();
    int length_bones = deserialize_le<int>();
    s.bones = new BoneInfo[length_bones];
    for(int i = 0; i < length_bones; i++) {
        s.bones[i] = deserialize_BoneInfo();
    }
    int length_bindPose = deserialize_le<int>();
    s.bindPose = new Transform[length_bindPose];
    for(int i = 0; i < length_bindPose; i++) {
        s.bindPose[i] = deserialize_Transform();
    }
    return s;
}

ModelAnimation deserialize_ModelAnimation() {
    ModelAnimation s;
    s.boneCount = deserialize_le<int>();
    s.frameCount = deserialize_le<int>();
    int length_bones = deserialize_le<int>();
    s.bones = new BoneInfo[length_bones];
    for(int i = 0; i < length_bones; i++) {
        s.bones[i] = deserialize_BoneInfo();
    }
    for(int i = 0; i < 32; i++) { 
        s.name[i] = deserialize_le<char>();
    }
    return s;
}

Ray deserialize_Ray() {
    Ray s;
    s.position = deserialize_Vector3();
    s.direction = deserialize_Vector3();
    return s;
}

RayCollision deserialize_RayCollision() {
    RayCollision s;
    s.hit = deserialize_le<bool>();
    s.distance = deserialize_le<float>();
    s.point = deserialize_Vector3();
    s.normal = deserialize_Vector3();
    return s;
}

BoundingBox deserialize_BoundingBox() {
    BoundingBox s;
    s.min = deserialize_Vector3();
    s.max = deserialize_Vector3();
    return s;
}

Wave deserialize_Wave() {
    Wave s;
    s.frameCount = deserialize_le<unsigned int>();
    s.sampleRate = deserialize_le<unsigned int>();
    s.sampleSize = deserialize_le<unsigned int>();
    s.channels = deserialize_le<unsigned int>();
    // Skipping data (type: void*) - not deserializable
    s.data = nullptr;
    return s;
}

AudioStream deserialize_AudioStream() {
    AudioStream s;
    // Skipping buffer (type: rAudioBuffer*) - not deserializable
    s.buffer = nullptr;
    // Skipping processor (type: rAudioProcessor*) - not deserializable
    s.processor = nullptr;
    s.sampleRate = deserialize_le<unsigned int>();
    s.sampleSize = deserialize_le<unsigned int>();
    s.channels = deserialize_le<unsigned int>();
    return s;
}

Sound deserialize_Sound() {
    Sound s;
    s.stream = deserialize_AudioStream();
    s.frameCount = deserialize_le<unsigned int>();
    return s;
}

Music deserialize_Music() {
    Music s;
    s.stream = deserialize_AudioStream();
    s.frameCount = deserialize_le<unsigned int>();
    s.looping = deserialize_le<bool>();
    s.ctxType = deserialize_le<int>();
    // Skipping ctxData (type: void*) - not deserializable
    s.ctxData = nullptr;
    return s;
}

VrDeviceInfo deserialize_VrDeviceInfo() {
    VrDeviceInfo s;
    s.hResolution = deserialize_le<int>();
    s.vResolution = deserialize_le<int>();
    s.hScreenSize = deserialize_le<float>();
    s.vScreenSize = deserialize_le<float>();
    s.eyeToScreenDistance = deserialize_le<float>();
    s.lensSeparationDistance = deserialize_le<float>();
    s.interpupillaryDistance = deserialize_le<float>();
    for(int i = 0; i < 4; i++) { 
        s.lensDistortionValues[i] = deserialize_le<float>();
    }
    for(int i = 0; i < 4; i++) { 
        s.chromaAbCorrection[i] = deserialize_le<float>();
    }
    return s;
}

VrStereoConfig deserialize_VrStereoConfig() {
    VrStereoConfig s;
    for(int i = 0; i < 2; i++) { 
        s.projection[i] = deserialize_Matrix();
    }
    for(int i = 0; i < 2; i++) { 
        s.viewOffset[i] = deserialize_Matrix();
    }
    for(int i = 0; i < 2; i++) { 
        s.leftLensCenter[i] = deserialize_le<float>();
    }
    for(int i = 0; i < 2; i++) { 
        s.rightLensCenter[i] = deserialize_le<float>();
    }
    for(int i = 0; i < 2; i++) { 
        s.leftScreenCenter[i] = deserialize_le<float>();
    }
    for(int i = 0; i < 2; i++) { 
        s.rightScreenCenter[i] = deserialize_le<float>();
    }
    for(int i = 0; i < 2; i++) { 
        s.scale[i] = deserialize_le<float>();
    }
    for(int i = 0; i < 2; i++) { 
        s.scaleIn[i] = deserialize_le<float>();
    }
    return s;
}

FilePathList deserialize_FilePathList() {
    FilePathList s;
    s.capacity = deserialize_le<unsigned int>();
    s.count = deserialize_le<unsigned int>();
    return s;
}

AutomationEvent deserialize_AutomationEvent() {
    AutomationEvent s;
    s.frame = deserialize_le<unsigned int>();
    s.type = deserialize_le<unsigned int>();
    for(int i = 0; i < 4; i++) { 
        s.params[i] = deserialize_le<int>();
    }
    return s;
}

AutomationEventList deserialize_AutomationEventList() {
    AutomationEventList s;
    s.capacity = deserialize_le<unsigned int>();
    s.count = deserialize_le<unsigned int>();
    int length_events = deserialize_le<int>();
    s.count = length_events;
    s.events = new AutomationEvent[length_events];
    for(int i = 0; i < length_events; i++) {
        s.events[i] = deserialize_AutomationEvent();
    }
    return s;
}

void dispatch_raylib_function_call(uint64_t id, const uint8_t* buffer, uint64_t buffer_size){
    // Set up deserialization context
    auto& ctx = get_trace_context();
    ctx.parameter_stream.data.assign(buffer, buffer + buffer_size);
    ctx.parameter_stream.read_offset = 0;

    switch(id) {
        case 0: // InitWindow
        {
            int width = deserialize_le<int>();
            int height = deserialize_le<int>();
            int length_title = deserialize_le<int>();
            std::vector<char> temp_title(length_title);
            for(int i = 0; i < length_title; i++) {
                temp_title[i] = deserialize_le<char>();
            }
            InitWindow(width, height, temp_title.data());
            break;
        }
        case 1: // CloseWindow
        {
            CloseWindow();
            break;
        }
        case 2: // WindowShouldClose
        {
            bool result = WindowShouldClose();
            break;
        }
        case 3: // IsWindowReady
        {
            bool result = IsWindowReady();
            break;
        }
        case 4: // IsWindowFullscreen
        {
            bool result = IsWindowFullscreen();
            break;
        }
        case 5: // IsWindowHidden
        {
            bool result = IsWindowHidden();
            break;
        }
        case 6: // IsWindowMinimized
        {
            bool result = IsWindowMinimized();
            break;
        }
        case 7: // IsWindowMaximized
        {
            bool result = IsWindowMaximized();
            break;
        }
        case 8: // IsWindowFocused
        {
            bool result = IsWindowFocused();
            break;
        }
        case 9: // IsWindowResized
        {
            bool result = IsWindowResized();
            break;
        }
        case 10: // IsWindowState
        {
            unsigned int flag = deserialize_le<unsigned int>();
            bool result = IsWindowState(flag);
            break;
        }
        case 11: // SetWindowState
        {
            unsigned int flags = deserialize_le<unsigned int>();
            SetWindowState(flags);
            break;
        }
        case 12: // ClearWindowState
        {
            unsigned int flags = deserialize_le<unsigned int>();
            ClearWindowState(flags);
            break;
        }
        case 13: // ToggleFullscreen
        {
            ToggleFullscreen();
            break;
        }
        case 14: // ToggleBorderlessWindowed
        {
            ToggleBorderlessWindowed();
            break;
        }
        case 15: // MaximizeWindow
        {
            MaximizeWindow();
            break;
        }
        case 16: // MinimizeWindow
        {
            MinimizeWindow();
            break;
        }
        case 17: // RestoreWindow
        {
            RestoreWindow();
            break;
        }
        case 18: // SetWindowIcon
        {
            Image image = deserialize_Image();
            SetWindowIcon(image);
            break;
        }
        case 19: // SetWindowIcons
        {
            int length_images = deserialize_le<int>();
            std::vector<Image> temp_images(length_images);
            for(int i = 0; i < length_images; i++) {
                temp_images[i] = deserialize_Image();
            }
            int count = deserialize_le<int>();
            SetWindowIcons(temp_images.data(), count);
            break;
        }
        case 20: // SetWindowTitle
        {
            int length_title = deserialize_le<int>();
            std::vector<char> temp_title(length_title);
            for(int i = 0; i < length_title; i++) {
                temp_title[i] = deserialize_le<char>();
            }
            SetWindowTitle(temp_title.data());
            break;
        }
        case 21: // SetWindowPosition
        {
            int x = deserialize_le<int>();
            int y = deserialize_le<int>();
            SetWindowPosition(x, y);
            break;
        }
        case 22: // SetWindowMonitor
        {
            int monitor = deserialize_le<int>();
            SetWindowMonitor(monitor);
            break;
        }
        case 23: // SetWindowMinSize
        {
            int width = deserialize_le<int>();
            int height = deserialize_le<int>();
            SetWindowMinSize(width, height);
            break;
        }
        case 24: // SetWindowMaxSize
        {
            int width = deserialize_le<int>();
            int height = deserialize_le<int>();
            SetWindowMaxSize(width, height);
            break;
        }
        case 25: // SetWindowSize
        {
            int width = deserialize_le<int>();
            int height = deserialize_le<int>();
            SetWindowSize(width, height);
            break;
        }
        case 26: // SetWindowOpacity
        {
            float opacity = deserialize_le<float>();
            SetWindowOpacity(opacity);
            break;
        }
        case 27: // SetWindowFocused
        {
            SetWindowFocused();
            break;
        }
        case 28: // GetScreenWidth
        {
            int result = GetScreenWidth();
            break;
        }
        case 29: // GetScreenHeight
        {
            int result = GetScreenHeight();
            break;
        }
        case 30: // GetRenderWidth
        {
            int result = GetRenderWidth();
            break;
        }
        case 31: // GetRenderHeight
        {
            int result = GetRenderHeight();
            break;
        }
        case 32: // GetMonitorCount
        {
            int result = GetMonitorCount();
            break;
        }
        case 33: // GetCurrentMonitor
        {
            int result = GetCurrentMonitor();
            break;
        }
        case 34: // GetMonitorPosition
        {
            int monitor = deserialize_le<int>();
            Vector2 result = GetMonitorPosition(monitor);
            break;
        }
        case 35: // GetMonitorWidth
        {
            int monitor = deserialize_le<int>();
            int result = GetMonitorWidth(monitor);
            break;
        }
        case 36: // GetMonitorHeight
        {
            int monitor = deserialize_le<int>();
            int result = GetMonitorHeight(monitor);
            break;
        }
        case 37: // GetMonitorPhysicalWidth
        {
            int monitor = deserialize_le<int>();
            int result = GetMonitorPhysicalWidth(monitor);
            break;
        }
        case 38: // GetMonitorPhysicalHeight
        {
            int monitor = deserialize_le<int>();
            int result = GetMonitorPhysicalHeight(monitor);
            break;
        }
        case 39: // GetMonitorRefreshRate
        {
            int monitor = deserialize_le<int>();
            int result = GetMonitorRefreshRate(monitor);
            break;
        }
        case 40: // GetWindowPosition
        {
            Vector2 result = GetWindowPosition();
            break;
        }
        case 41: // GetWindowScaleDPI
        {
            Vector2 result = GetWindowScaleDPI();
            break;
        }
        case 42: // SetClipboardText
        {
            int length_text = deserialize_le<int>();
            std::vector<char> temp_text(length_text);
            for(int i = 0; i < length_text; i++) {
                temp_text[i] = deserialize_le<char>();
            }
            SetClipboardText(temp_text.data());
            break;
        }
        case 43: // GetClipboardImage
        {
            Image result = GetClipboardImage();
            break;
        }
        case 44: // EnableEventWaiting
        {
            EnableEventWaiting();
            break;
        }
        case 45: // DisableEventWaiting
        {
            DisableEventWaiting();
            break;
        }
        case 46: // ShowCursor
        {
            ShowCursor();
            break;
        }
        case 47: // HideCursor
        {
            HideCursor();
            break;
        }
        case 48: // IsCursorHidden
        {
            bool result = IsCursorHidden();
            break;
        }
        case 49: // EnableCursor
        {
            EnableCursor();
            break;
        }
        case 50: // DisableCursor
        {
            DisableCursor();
            break;
        }
        case 51: // IsCursorOnScreen
        {
            bool result = IsCursorOnScreen();
            break;
        }
        case 52: // ClearBackground
        {
            Color color = deserialize_Color();
            ClearBackground(color);
            break;
        }
        case 53: // BeginDrawing
        {
            BeginDrawing();
            break;
        }
        case 54: // EndDrawing
        {
            EndDrawing();
            break;
        }
        case 55: // BeginMode2D
        {
            Camera2D camera = deserialize_Camera2D();
            BeginMode2D(camera);
            break;
        }
        case 56: // EndMode2D
        {
            EndMode2D();
            break;
        }
        case 57: // BeginMode3D
        {
            Camera3D camera = deserialize_Camera3D();
            BeginMode3D(camera);
            break;
        }
        case 58: // EndMode3D
        {
            EndMode3D();
            break;
        }
        case 59: // BeginTextureMode
        {
            RenderTexture2D target = deserialize_le<RenderTexture2D>();
            BeginTextureMode(target);
            break;
        }
        case 60: // EndTextureMode
        {
            EndTextureMode();
            break;
        }
        case 61: // BeginShaderMode
        {
            Shader shader = deserialize_Shader();
            BeginShaderMode(shader);
            break;
        }
        case 62: // EndShaderMode
        {
            EndShaderMode();
            break;
        }
        case 63: // BeginBlendMode
        {
            int mode = deserialize_le<int>();
            BeginBlendMode(mode);
            break;
        }
        case 64: // EndBlendMode
        {
            EndBlendMode();
            break;
        }
        case 65: // BeginScissorMode
        {
            int x = deserialize_le<int>();
            int y = deserialize_le<int>();
            int width = deserialize_le<int>();
            int height = deserialize_le<int>();
            BeginScissorMode(x, y, width, height);
            break;
        }
        case 66: // EndScissorMode
        {
            EndScissorMode();
            break;
        }
        case 67: // BeginVrStereoMode
        {
            VrStereoConfig config = deserialize_VrStereoConfig();
            BeginVrStereoMode(config);
            break;
        }
        case 68: // EndVrStereoMode
        {
            EndVrStereoMode();
            break;
        }
        case 69: // LoadVrStereoConfig
        {
            VrDeviceInfo device = deserialize_VrDeviceInfo();
            VrStereoConfig result = LoadVrStereoConfig(device);
            break;
        }
        case 70: // UnloadVrStereoConfig
        {
            VrStereoConfig config = deserialize_VrStereoConfig();
            UnloadVrStereoConfig(config);
            break;
        }
        case 71: // LoadShader
        {
            int length_vsFileName = deserialize_le<int>();
            std::vector<char> temp_vsFileName(length_vsFileName);
            for(int i = 0; i < length_vsFileName; i++) {
                temp_vsFileName[i] = deserialize_le<char>();
            }
            int length_fsFileName = deserialize_le<int>();
            std::vector<char> temp_fsFileName(length_fsFileName);
            for(int i = 0; i < length_fsFileName; i++) {
                temp_fsFileName[i] = deserialize_le<char>();
            }
            Shader result = LoadShader(temp_vsFileName.data(), temp_fsFileName.data());
            break;
        }
        case 72: // LoadShaderFromMemory
        {
            int length_vsCode = deserialize_le<int>();
            std::vector<char> temp_vsCode(length_vsCode);
            for(int i = 0; i < length_vsCode; i++) {
                temp_vsCode[i] = deserialize_le<char>();
            }
            int length_fsCode = deserialize_le<int>();
            std::vector<char> temp_fsCode(length_fsCode);
            for(int i = 0; i < length_fsCode; i++) {
                temp_fsCode[i] = deserialize_le<char>();
            }
            Shader result = LoadShaderFromMemory(temp_vsCode.data(), temp_fsCode.data());
            break;
        }
        case 73: // IsShaderValid
        {
            Shader shader = deserialize_Shader();
            bool result = IsShaderValid(shader);
            break;
        }
        case 74: // GetShaderLocation
        {
            Shader shader = deserialize_Shader();
            int length_uniformName = deserialize_le<int>();
            std::vector<char> temp_uniformName(length_uniformName);
            for(int i = 0; i < length_uniformName; i++) {
                temp_uniformName[i] = deserialize_le<char>();
            }
            int result = GetShaderLocation(shader, temp_uniformName.data());
            break;
        }
        case 75: // GetShaderLocationAttrib
        {
            Shader shader = deserialize_Shader();
            int length_attribName = deserialize_le<int>();
            std::vector<char> temp_attribName(length_attribName);
            for(int i = 0; i < length_attribName; i++) {
                temp_attribName[i] = deserialize_le<char>();
            }
            int result = GetShaderLocationAttrib(shader, temp_attribName.data());
            break;
        }
        case 76: // SetShaderValue
        {
            Shader shader = deserialize_Shader();
            int locIndex = deserialize_le<int>();
            // Skipping value (type: const void*) - not deserializable
            int uniformType = deserialize_le<int>();
            SetShaderValue(shader, locIndex, nullptr, uniformType);
            break;
        }
        case 77: // SetShaderValueV
        {
            Shader shader = deserialize_Shader();
            int locIndex = deserialize_le<int>();
            // Skipping value (type: const void*) - not deserializable
            int uniformType = deserialize_le<int>();
            int count = deserialize_le<int>();
            SetShaderValueV(shader, locIndex, nullptr, uniformType, count);
            break;
        }
        case 78: // SetShaderValueMatrix
        {
            Shader shader = deserialize_Shader();
            int locIndex = deserialize_le<int>();
            Matrix mat = deserialize_Matrix();
            SetShaderValueMatrix(shader, locIndex, mat);
            break;
        }
        case 79: // SetShaderValueTexture
        {
            Shader shader = deserialize_Shader();
            int locIndex = deserialize_le<int>();
            Texture2D texture = deserialize_le<Texture2D>();
            SetShaderValueTexture(shader, locIndex, texture);
            break;
        }
        case 80: // UnloadShader
        {
            Shader shader = deserialize_Shader();
            UnloadShader(shader);
            break;
        }
        case 81: // GetScreenToWorldRay
        {
            Vector2 position = deserialize_Vector2();
            Camera camera = deserialize_le<Camera>();
            Ray result = GetScreenToWorldRay(position, camera);
            break;
        }
        case 82: // GetScreenToWorldRayEx
        {
            Vector2 position = deserialize_Vector2();
            Camera camera = deserialize_le<Camera>();
            int width = deserialize_le<int>();
            int height = deserialize_le<int>();
            Ray result = GetScreenToWorldRayEx(position, camera, width, height);
            break;
        }
        case 83: // GetWorldToScreen
        {
            Vector3 position = deserialize_Vector3();
            Camera camera = deserialize_le<Camera>();
            Vector2 result = GetWorldToScreen(position, camera);
            break;
        }
        case 84: // GetWorldToScreenEx
        {
            Vector3 position = deserialize_Vector3();
            Camera camera = deserialize_le<Camera>();
            int width = deserialize_le<int>();
            int height = deserialize_le<int>();
            Vector2 result = GetWorldToScreenEx(position, camera, width, height);
            break;
        }
        case 85: // GetWorldToScreen2D
        {
            Vector2 position = deserialize_Vector2();
            Camera2D camera = deserialize_Camera2D();
            Vector2 result = GetWorldToScreen2D(position, camera);
            break;
        }
        case 86: // GetScreenToWorld2D
        {
            Vector2 position = deserialize_Vector2();
            Camera2D camera = deserialize_Camera2D();
            Vector2 result = GetScreenToWorld2D(position, camera);
            break;
        }
        case 87: // GetCameraMatrix
        {
            Camera camera = deserialize_le<Camera>();
            Matrix result = GetCameraMatrix(camera);
            break;
        }
        case 88: // GetCameraMatrix2D
        {
            Camera2D camera = deserialize_Camera2D();
            Matrix result = GetCameraMatrix2D(camera);
            break;
        }
        case 89: // SetTargetFPS
        {
            int fps = deserialize_le<int>();
            SetTargetFPS(fps);
            break;
        }
        case 90: // GetFrameTime
        {
            float result = GetFrameTime();
            break;
        }
        case 91: // GetTime
        {
            double result = GetTime();
            break;
        }
        case 92: // GetFPS
        {
            int result = GetFPS();
            break;
        }
        case 93: // SwapScreenBuffer
        {
            SwapScreenBuffer();
            break;
        }
        case 94: // PollInputEvents
        {
            PollInputEvents();
            break;
        }
        case 95: // WaitTime
        {
            double seconds = deserialize_le<double>();
            WaitTime(seconds);
            break;
        }
        case 96: // SetRandomSeed
        {
            unsigned int seed = deserialize_le<unsigned int>();
            SetRandomSeed(seed);
            break;
        }
        case 97: // GetRandomValue
        {
            int min = deserialize_le<int>();
            int max = deserialize_le<int>();
            int result = GetRandomValue(min, max);
            break;
        }
        case 98: // UnloadRandomSequence
        {
            int length_sequence = deserialize_le<int>();
            std::vector<int> temp_sequence(length_sequence);
            for(int i = 0; i < length_sequence; i++) {
                temp_sequence[i] = deserialize_le<int>();
            }
            UnloadRandomSequence(temp_sequence.data());
            break;
        }
        case 99: // TakeScreenshot
        {
            int length_fileName = deserialize_le<int>();
            std::vector<char> temp_fileName(length_fileName);
            for(int i = 0; i < length_fileName; i++) {
                temp_fileName[i] = deserialize_le<char>();
            }
            TakeScreenshot(temp_fileName.data());
            break;
        }
        case 100: // SetConfigFlags
        {
            unsigned int flags = deserialize_le<unsigned int>();
            SetConfigFlags(flags);
            break;
        }
        case 101: // OpenURL
        {
            int length_url = deserialize_le<int>();
            std::vector<char> temp_url(length_url);
            for(int i = 0; i < length_url; i++) {
                temp_url[i] = deserialize_le<char>();
            }
            OpenURL(temp_url.data());
            break;
        }
        case 102: // TraceLog
        {
            int logLevel = deserialize_le<int>();
            int length_text = deserialize_le<int>();
            std::vector<char> temp_text(length_text);
            for(int i = 0; i < length_text; i++) {
                temp_text[i] = deserialize_le<char>();
            }
            TraceLog(logLevel, temp_text.data());
            break;
        }
        case 103: // SetTraceLogLevel
        {
            int logLevel = deserialize_le<int>();
            SetTraceLogLevel(logLevel);
            break;
        }
        case 104: // MemFree
        {
            // Skipping ptr (type: void*) - not deserializable
            MemFree(nullptr);
            break;
        }
        case 105: // SetTraceLogCallback
        {
            TraceLogCallback callback = deserialize_le<TraceLogCallback>();
            SetTraceLogCallback(callback);
            break;
        }
        case 106: // SetLoadFileDataCallback
        {
            LoadFileDataCallback callback = deserialize_le<LoadFileDataCallback>();
            SetLoadFileDataCallback(callback);
            break;
        }
        case 107: // SetSaveFileDataCallback
        {
            SaveFileDataCallback callback = deserialize_le<SaveFileDataCallback>();
            SetSaveFileDataCallback(callback);
            break;
        }
        case 108: // SetLoadFileTextCallback
        {
            LoadFileTextCallback callback = deserialize_le<LoadFileTextCallback>();
            SetLoadFileTextCallback(callback);
            break;
        }
        case 109: // SetSaveFileTextCallback
        {
            SaveFileTextCallback callback = deserialize_le<SaveFileTextCallback>();
            SetSaveFileTextCallback(callback);
            break;
        }
        case 110: // UnloadFileData
        {
            int length_data = deserialize_le<int>();
            std::vector<unsigned char> temp_data(length_data);
            for(int i = 0; i < length_data; i++) {
                temp_data[i] = deserialize_le<unsigned char>();
            }
            UnloadFileData(temp_data.data());
            break;
        }
        case 111: // SaveFileData
        {
            int length_fileName = deserialize_le<int>();
            std::vector<char> temp_fileName(length_fileName);
            for(int i = 0; i < length_fileName; i++) {
                temp_fileName[i] = deserialize_le<char>();
            }
            // Skipping data (type: void*) - not deserializable
            int dataSize = deserialize_le<int>();
            bool result = SaveFileData(temp_fileName.data(), nullptr, dataSize);
            break;
        }
        case 112: // ExportDataAsCode
        {
            int length_data = deserialize_le<int>();
            std::vector<unsigned char> temp_data(length_data);
            for(int i = 0; i < length_data; i++) {
                temp_data[i] = deserialize_le<unsigned char>();
            }
            int dataSize = deserialize_le<int>();
            int length_fileName = deserialize_le<int>();
            std::vector<char> temp_fileName(length_fileName);
            for(int i = 0; i < length_fileName; i++) {
                temp_fileName[i] = deserialize_le<char>();
            }
            bool result = ExportDataAsCode(temp_data.data(), dataSize, temp_fileName.data());
            break;
        }
        case 113: // UnloadFileText
        {
            int length_text = deserialize_le<int>();
            std::vector<char> temp_text(length_text);
            for(int i = 0; i < length_text; i++) {
                temp_text[i] = deserialize_le<char>();
            }
            UnloadFileText(temp_text.data());
            break;
        }
        case 114: // SaveFileText
        {
            int length_fileName = deserialize_le<int>();
            std::vector<char> temp_fileName(length_fileName);
            for(int i = 0; i < length_fileName; i++) {
                temp_fileName[i] = deserialize_le<char>();
            }
            int length_text = deserialize_le<int>();
            std::vector<char> temp_text(length_text);
            for(int i = 0; i < length_text; i++) {
                temp_text[i] = deserialize_le<char>();
            }
            bool result = SaveFileText(temp_fileName.data(), temp_text.data());
            break;
        }
        case 115: // FileExists
        {
            int length_fileName = deserialize_le<int>();
            std::vector<char> temp_fileName(length_fileName);
            for(int i = 0; i < length_fileName; i++) {
                temp_fileName[i] = deserialize_le<char>();
            }
            bool result = FileExists(temp_fileName.data());
            break;
        }
        case 116: // DirectoryExists
        {
            int length_dirPath = deserialize_le<int>();
            std::vector<char> temp_dirPath(length_dirPath);
            for(int i = 0; i < length_dirPath; i++) {
                temp_dirPath[i] = deserialize_le<char>();
            }
            bool result = DirectoryExists(temp_dirPath.data());
            break;
        }
        case 117: // IsFileExtension
        {
            int length_fileName = deserialize_le<int>();
            std::vector<char> temp_fileName(length_fileName);
            for(int i = 0; i < length_fileName; i++) {
                temp_fileName[i] = deserialize_le<char>();
            }
            int length_ext = deserialize_le<int>();
            std::vector<char> temp_ext(length_ext);
            for(int i = 0; i < length_ext; i++) {
                temp_ext[i] = deserialize_le<char>();
            }
            bool result = IsFileExtension(temp_fileName.data(), temp_ext.data());
            break;
        }
        case 118: // GetFileLength
        {
            int length_fileName = deserialize_le<int>();
            std::vector<char> temp_fileName(length_fileName);
            for(int i = 0; i < length_fileName; i++) {
                temp_fileName[i] = deserialize_le<char>();
            }
            int result = GetFileLength(temp_fileName.data());
            break;
        }
        case 119: // MakeDirectory
        {
            int length_dirPath = deserialize_le<int>();
            std::vector<char> temp_dirPath(length_dirPath);
            for(int i = 0; i < length_dirPath; i++) {
                temp_dirPath[i] = deserialize_le<char>();
            }
            int result = MakeDirectory(temp_dirPath.data());
            break;
        }
        case 120: // ChangeDirectory
        {
            int length_dir = deserialize_le<int>();
            std::vector<char> temp_dir(length_dir);
            for(int i = 0; i < length_dir; i++) {
                temp_dir[i] = deserialize_le<char>();
            }
            bool result = ChangeDirectory(temp_dir.data());
            break;
        }
        case 121: // IsPathFile
        {
            int length_path = deserialize_le<int>();
            std::vector<char> temp_path(length_path);
            for(int i = 0; i < length_path; i++) {
                temp_path[i] = deserialize_le<char>();
            }
            bool result = IsPathFile(temp_path.data());
            break;
        }
        case 122: // IsFileNameValid
        {
            int length_fileName = deserialize_le<int>();
            std::vector<char> temp_fileName(length_fileName);
            for(int i = 0; i < length_fileName; i++) {
                temp_fileName[i] = deserialize_le<char>();
            }
            bool result = IsFileNameValid(temp_fileName.data());
            break;
        }
        case 123: // LoadDirectoryFiles
        {
            int length_dirPath = deserialize_le<int>();
            std::vector<char> temp_dirPath(length_dirPath);
            for(int i = 0; i < length_dirPath; i++) {
                temp_dirPath[i] = deserialize_le<char>();
            }
            FilePathList result = LoadDirectoryFiles(temp_dirPath.data());
            break;
        }
        case 124: // LoadDirectoryFilesEx
        {
            int length_basePath = deserialize_le<int>();
            std::vector<char> temp_basePath(length_basePath);
            for(int i = 0; i < length_basePath; i++) {
                temp_basePath[i] = deserialize_le<char>();
            }
            int length_filter = deserialize_le<int>();
            std::vector<char> temp_filter(length_filter);
            for(int i = 0; i < length_filter; i++) {
                temp_filter[i] = deserialize_le<char>();
            }
            bool scanSubdirs = deserialize_le<bool>();
            FilePathList result = LoadDirectoryFilesEx(temp_basePath.data(), temp_filter.data(), scanSubdirs);
            break;
        }
        case 125: // UnloadDirectoryFiles
        {
            FilePathList files = deserialize_FilePathList();
            UnloadDirectoryFiles(files);
            break;
        }
        case 126: // IsFileDropped
        {
            bool result = IsFileDropped();
            break;
        }
        case 127: // LoadDroppedFiles
        {
            FilePathList result = LoadDroppedFiles();
            break;
        }
        case 128: // UnloadDroppedFiles
        {
            FilePathList files = deserialize_FilePathList();
            UnloadDroppedFiles(files);
            break;
        }
        case 129: // GetFileModTime
        {
            int length_fileName = deserialize_le<int>();
            std::vector<char> temp_fileName(length_fileName);
            for(int i = 0; i < length_fileName; i++) {
                temp_fileName[i] = deserialize_le<char>();
            }
            long result = GetFileModTime(temp_fileName.data());
            break;
        }
        case 130: // ComputeCRC32
        {
            int length_data = deserialize_le<int>();
            std::vector<unsigned char> temp_data(length_data);
            for(int i = 0; i < length_data; i++) {
                temp_data[i] = deserialize_le<unsigned char>();
            }
            int dataSize = deserialize_le<int>();
            int result = ComputeCRC32(temp_data.data(), dataSize);
            break;
        }
        case 131: // LoadAutomationEventList
        {
            int length_fileName = deserialize_le<int>();
            std::vector<char> temp_fileName(length_fileName);
            for(int i = 0; i < length_fileName; i++) {
                temp_fileName[i] = deserialize_le<char>();
            }
            AutomationEventList result = LoadAutomationEventList(temp_fileName.data());
            break;
        }
        case 132: // UnloadAutomationEventList
        {
            AutomationEventList list = deserialize_AutomationEventList();
            UnloadAutomationEventList(list);
            break;
        }
        case 133: // ExportAutomationEventList
        {
            AutomationEventList list = deserialize_AutomationEventList();
            int length_fileName = deserialize_le<int>();
            std::vector<char> temp_fileName(length_fileName);
            for(int i = 0; i < length_fileName; i++) {
                temp_fileName[i] = deserialize_le<char>();
            }
            bool result = ExportAutomationEventList(list, temp_fileName.data());
            break;
        }
        case 134: // SetAutomationEventList
        {
            int length_list = deserialize_le<int>();
            std::vector<AutomationEventList> temp_list(length_list);
            for(int i = 0; i < length_list; i++) {
                temp_list[i] = deserialize_AutomationEventList();
            }
            SetAutomationEventList(temp_list.data());
            break;
        }
        case 135: // SetAutomationEventBaseFrame
        {
            int frame = deserialize_le<int>();
            SetAutomationEventBaseFrame(frame);
            break;
        }
        case 136: // StartAutomationEventRecording
        {
            StartAutomationEventRecording();
            break;
        }
        case 137: // StopAutomationEventRecording
        {
            StopAutomationEventRecording();
            break;
        }
        case 138: // PlayAutomationEvent
        {
            AutomationEvent event = deserialize_AutomationEvent();
            PlayAutomationEvent(event);
            break;
        }
        case 139: // IsKeyPressed
        {
            int key = deserialize_le<int>();
            bool result = IsKeyPressed(key);
            break;
        }
        case 140: // IsKeyPressedRepeat
        {
            int key = deserialize_le<int>();
            bool result = IsKeyPressedRepeat(key);
            break;
        }
        case 141: // IsKeyDown
        {
            int key = deserialize_le<int>();
            bool result = IsKeyDown(key);
            break;
        }
        case 142: // IsKeyReleased
        {
            int key = deserialize_le<int>();
            bool result = IsKeyReleased(key);
            break;
        }
        case 143: // IsKeyUp
        {
            int key = deserialize_le<int>();
            bool result = IsKeyUp(key);
            break;
        }
        case 144: // GetKeyPressed
        {
            int result = GetKeyPressed();
            break;
        }
        case 145: // GetCharPressed
        {
            int result = GetCharPressed();
            break;
        }
        case 146: // SetExitKey
        {
            int key = deserialize_le<int>();
            SetExitKey(key);
            break;
        }
        case 147: // IsGamepadAvailable
        {
            int gamepad = deserialize_le<int>();
            bool result = IsGamepadAvailable(gamepad);
            break;
        }
        case 148: // IsGamepadButtonPressed
        {
            int gamepad = deserialize_le<int>();
            int button = deserialize_le<int>();
            bool result = IsGamepadButtonPressed(gamepad, button);
            break;
        }
        case 149: // IsGamepadButtonDown
        {
            int gamepad = deserialize_le<int>();
            int button = deserialize_le<int>();
            bool result = IsGamepadButtonDown(gamepad, button);
            break;
        }
        case 150: // IsGamepadButtonReleased
        {
            int gamepad = deserialize_le<int>();
            int button = deserialize_le<int>();
            bool result = IsGamepadButtonReleased(gamepad, button);
            break;
        }
        case 151: // IsGamepadButtonUp
        {
            int gamepad = deserialize_le<int>();
            int button = deserialize_le<int>();
            bool result = IsGamepadButtonUp(gamepad, button);
            break;
        }
        case 152: // GetGamepadButtonPressed
        {
            int result = GetGamepadButtonPressed();
            break;
        }
        case 153: // GetGamepadAxisCount
        {
            int gamepad = deserialize_le<int>();
            int result = GetGamepadAxisCount(gamepad);
            break;
        }
        case 154: // GetGamepadAxisMovement
        {
            int gamepad = deserialize_le<int>();
            int axis = deserialize_le<int>();
            float result = GetGamepadAxisMovement(gamepad, axis);
            break;
        }
        case 155: // SetGamepadMappings
        {
            int length_mappings = deserialize_le<int>();
            std::vector<char> temp_mappings(length_mappings);
            for(int i = 0; i < length_mappings; i++) {
                temp_mappings[i] = deserialize_le<char>();
            }
            int result = SetGamepadMappings(temp_mappings.data());
            break;
        }
        case 156: // SetGamepadVibration
        {
            int gamepad = deserialize_le<int>();
            float leftMotor = deserialize_le<float>();
            float rightMotor = deserialize_le<float>();
            float duration = deserialize_le<float>();
            SetGamepadVibration(gamepad, leftMotor, rightMotor, duration);
            break;
        }
        case 157: // IsMouseButtonPressed
        {
            int button = deserialize_le<int>();
            bool result = IsMouseButtonPressed(button);
            break;
        }
        case 158: // IsMouseButtonDown
        {
            int button = deserialize_le<int>();
            bool result = IsMouseButtonDown(button);
            break;
        }
        case 159: // IsMouseButtonReleased
        {
            int button = deserialize_le<int>();
            bool result = IsMouseButtonReleased(button);
            break;
        }
        case 160: // IsMouseButtonUp
        {
            int button = deserialize_le<int>();
            bool result = IsMouseButtonUp(button);
            break;
        }
        case 161: // GetMouseX
        {
            int result = GetMouseX();
            break;
        }
        case 162: // GetMouseY
        {
            int result = GetMouseY();
            break;
        }
        case 163: // GetMousePosition
        {
            Vector2 result = GetMousePosition();
            break;
        }
        case 164: // GetMouseDelta
        {
            Vector2 result = GetMouseDelta();
            break;
        }
        case 165: // SetMousePosition
        {
            int x = deserialize_le<int>();
            int y = deserialize_le<int>();
            SetMousePosition(x, y);
            break;
        }
        case 166: // SetMouseOffset
        {
            int offsetX = deserialize_le<int>();
            int offsetY = deserialize_le<int>();
            SetMouseOffset(offsetX, offsetY);
            break;
        }
        case 167: // SetMouseScale
        {
            float scaleX = deserialize_le<float>();
            float scaleY = deserialize_le<float>();
            SetMouseScale(scaleX, scaleY);
            break;
        }
        case 168: // GetMouseWheelMove
        {
            float result = GetMouseWheelMove();
            break;
        }
        case 169: // GetMouseWheelMoveV
        {
            Vector2 result = GetMouseWheelMoveV();
            break;
        }
        case 170: // SetMouseCursor
        {
            int cursor = deserialize_le<int>();
            SetMouseCursor(cursor);
            break;
        }
        case 171: // GetTouchX
        {
            int result = GetTouchX();
            break;
        }
        case 172: // GetTouchY
        {
            int result = GetTouchY();
            break;
        }
        case 173: // GetTouchPosition
        {
            int index = deserialize_le<int>();
            Vector2 result = GetTouchPosition(index);
            break;
        }
        case 174: // GetTouchPointId
        {
            int index = deserialize_le<int>();
            int result = GetTouchPointId(index);
            break;
        }
        case 175: // GetTouchPointCount
        {
            int result = GetTouchPointCount();
            break;
        }
        case 176: // SetGesturesEnabled
        {
            unsigned int flags = deserialize_le<unsigned int>();
            SetGesturesEnabled(flags);
            break;
        }
        case 177: // IsGestureDetected
        {
            unsigned int gesture = deserialize_le<unsigned int>();
            bool result = IsGestureDetected(gesture);
            break;
        }
        case 178: // GetGestureDetected
        {
            int result = GetGestureDetected();
            break;
        }
        case 179: // GetGestureHoldDuration
        {
            float result = GetGestureHoldDuration();
            break;
        }
        case 180: // GetGestureDragVector
        {
            Vector2 result = GetGestureDragVector();
            break;
        }
        case 181: // GetGestureDragAngle
        {
            float result = GetGestureDragAngle();
            break;
        }
        case 182: // GetGesturePinchVector
        {
            Vector2 result = GetGesturePinchVector();
            break;
        }
        case 183: // GetGesturePinchAngle
        {
            float result = GetGesturePinchAngle();
            break;
        }
        case 184: // UpdateCamera
        {
            int length_camera = deserialize_le<int>();
            std::vector<Camera> temp_camera(length_camera);
            for(int i = 0; i < length_camera; i++) {
                temp_camera[i] = deserialize_le<Camera>();
            }
            int mode = deserialize_le<int>();
            UpdateCamera(temp_camera.data(), mode);
            break;
        }
        case 185: // UpdateCameraPro
        {
            int length_camera = deserialize_le<int>();
            std::vector<Camera> temp_camera(length_camera);
            for(int i = 0; i < length_camera; i++) {
                temp_camera[i] = deserialize_le<Camera>();
            }
            Vector3 movement = deserialize_Vector3();
            Vector3 rotation = deserialize_Vector3();
            float zoom = deserialize_le<float>();
            UpdateCameraPro(temp_camera.data(), movement, rotation, zoom);
            break;
        }
        case 186: // SetShapesTexture
        {
            Texture2D texture = deserialize_le<Texture2D>();
            Rectangle source = deserialize_Rectangle();
            SetShapesTexture(texture, source);
            break;
        }
        case 187: // GetShapesTexture
        {
            Texture2D result = GetShapesTexture();
            break;
        }
        case 188: // GetShapesTextureRectangle
        {
            Rectangle result = GetShapesTextureRectangle();
            break;
        }
        case 189: // DrawPixel
        {
            int posX = deserialize_le<int>();
            int posY = deserialize_le<int>();
            Color color = deserialize_Color();
            DrawPixel(posX, posY, color);
            break;
        }
        case 190: // DrawPixelV
        {
            Vector2 position = deserialize_Vector2();
            Color color = deserialize_Color();
            DrawPixelV(position, color);
            break;
        }
        case 191: // DrawLine
        {
            int startPosX = deserialize_le<int>();
            int startPosY = deserialize_le<int>();
            int endPosX = deserialize_le<int>();
            int endPosY = deserialize_le<int>();
            Color color = deserialize_Color();
            DrawLine(startPosX, startPosY, endPosX, endPosY, color);
            break;
        }
        case 192: // DrawLineV
        {
            Vector2 startPos = deserialize_Vector2();
            Vector2 endPos = deserialize_Vector2();
            Color color = deserialize_Color();
            DrawLineV(startPos, endPos, color);
            break;
        }
        case 193: // DrawLineEx
        {
            Vector2 startPos = deserialize_Vector2();
            Vector2 endPos = deserialize_Vector2();
            float thick = deserialize_le<float>();
            Color color = deserialize_Color();
            DrawLineEx(startPos, endPos, thick, color);
            break;
        }
        case 194: // DrawLineStrip
        {
            int length_points = deserialize_le<int>();
            std::vector<Vector2> temp_points(length_points);
            for(int i = 0; i < length_points; i++) {
                temp_points[i] = deserialize_Vector2();
            }
            int pointCount = deserialize_le<int>();
            Color color = deserialize_Color();
            DrawLineStrip(temp_points.data(), pointCount, color);
            break;
        }
        case 195: // DrawLineBezier
        {
            Vector2 startPos = deserialize_Vector2();
            Vector2 endPos = deserialize_Vector2();
            float thick = deserialize_le<float>();
            Color color = deserialize_Color();
            DrawLineBezier(startPos, endPos, thick, color);
            break;
        }
        case 196: // DrawCircle
        {
            int centerX = deserialize_le<int>();
            int centerY = deserialize_le<int>();
            float radius = deserialize_le<float>();
            Color color = deserialize_Color();
            DrawCircle(centerX, centerY, radius, color);
            break;
        }
        case 197: // DrawCircleSector
        {
            Vector2 center = deserialize_Vector2();
            float radius = deserialize_le<float>();
            float startAngle = deserialize_le<float>();
            float endAngle = deserialize_le<float>();
            int segments = deserialize_le<int>();
            Color color = deserialize_Color();
            DrawCircleSector(center, radius, startAngle, endAngle, segments, color);
            break;
        }
        case 198: // DrawCircleSectorLines
        {
            Vector2 center = deserialize_Vector2();
            float radius = deserialize_le<float>();
            float startAngle = deserialize_le<float>();
            float endAngle = deserialize_le<float>();
            int segments = deserialize_le<int>();
            Color color = deserialize_Color();
            DrawCircleSectorLines(center, radius, startAngle, endAngle, segments, color);
            break;
        }
        case 199: // DrawCircleGradient
        {
            int centerX = deserialize_le<int>();
            int centerY = deserialize_le<int>();
            float radius = deserialize_le<float>();
            Color inner = deserialize_Color();
            Color outer = deserialize_Color();
            DrawCircleGradient(centerX, centerY, radius, inner, outer);
            break;
        }
        case 200: // DrawCircleV
        {
            Vector2 center = deserialize_Vector2();
            float radius = deserialize_le<float>();
            Color color = deserialize_Color();
            DrawCircleV(center, radius, color);
            break;
        }
        case 201: // DrawCircleLines
        {
            int centerX = deserialize_le<int>();
            int centerY = deserialize_le<int>();
            float radius = deserialize_le<float>();
            Color color = deserialize_Color();
            DrawCircleLines(centerX, centerY, radius, color);
            break;
        }
        case 202: // DrawCircleLinesV
        {
            Vector2 center = deserialize_Vector2();
            float radius = deserialize_le<float>();
            Color color = deserialize_Color();
            DrawCircleLinesV(center, radius, color);
            break;
        }
        case 203: // DrawEllipse
        {
            int centerX = deserialize_le<int>();
            int centerY = deserialize_le<int>();
            float radiusH = deserialize_le<float>();
            float radiusV = deserialize_le<float>();
            Color color = deserialize_Color();
            DrawEllipse(centerX, centerY, radiusH, radiusV, color);
            break;
        }
        case 204: // DrawEllipseV
        {
            Vector2 center = deserialize_Vector2();
            float radiusH = deserialize_le<float>();
            float radiusV = deserialize_le<float>();
            Color color = deserialize_Color();
            DrawEllipseV(center, radiusH, radiusV, color);
            break;
        }
        case 205: // DrawEllipseLines
        {
            int centerX = deserialize_le<int>();
            int centerY = deserialize_le<int>();
            float radiusH = deserialize_le<float>();
            float radiusV = deserialize_le<float>();
            Color color = deserialize_Color();
            DrawEllipseLines(centerX, centerY, radiusH, radiusV, color);
            break;
        }
        case 206: // DrawEllipseLinesV
        {
            Vector2 center = deserialize_Vector2();
            float radiusH = deserialize_le<float>();
            float radiusV = deserialize_le<float>();
            Color color = deserialize_Color();
            DrawEllipseLinesV(center, radiusH, radiusV, color);
            break;
        }
        case 207: // DrawRing
        {
            Vector2 center = deserialize_Vector2();
            float innerRadius = deserialize_le<float>();
            float outerRadius = deserialize_le<float>();
            float startAngle = deserialize_le<float>();
            float endAngle = deserialize_le<float>();
            int segments = deserialize_le<int>();
            Color color = deserialize_Color();
            DrawRing(center, innerRadius, outerRadius, startAngle, endAngle, segments, color);
            break;
        }
        case 208: // DrawRingLines
        {
            Vector2 center = deserialize_Vector2();
            float innerRadius = deserialize_le<float>();
            float outerRadius = deserialize_le<float>();
            float startAngle = deserialize_le<float>();
            float endAngle = deserialize_le<float>();
            int segments = deserialize_le<int>();
            Color color = deserialize_Color();
            DrawRingLines(center, innerRadius, outerRadius, startAngle, endAngle, segments, color);
            break;
        }
        case 209: // DrawRectangle
        {
            int posX = deserialize_le<int>();
            int posY = deserialize_le<int>();
            int width = deserialize_le<int>();
            int height = deserialize_le<int>();
            Color color = deserialize_Color();
            DrawRectangle(posX, posY, width, height, color);
            break;
        }
        case 210: // DrawRectangleV
        {
            Vector2 position = deserialize_Vector2();
            Vector2 size = deserialize_Vector2();
            Color color = deserialize_Color();
            DrawRectangleV(position, size, color);
            break;
        }
        case 211: // DrawRectangleRec
        {
            Rectangle rec = deserialize_Rectangle();
            Color color = deserialize_Color();
            DrawRectangleRec(rec, color);
            break;
        }
        case 212: // DrawRectanglePro
        {
            Rectangle rec = deserialize_Rectangle();
            Vector2 origin = deserialize_Vector2();
            float rotation = deserialize_le<float>();
            Color color = deserialize_Color();
            DrawRectanglePro(rec, origin, rotation, color);
            break;
        }
        case 213: // DrawRectangleGradientV
        {
            int posX = deserialize_le<int>();
            int posY = deserialize_le<int>();
            int width = deserialize_le<int>();
            int height = deserialize_le<int>();
            Color top = deserialize_Color();
            Color bottom = deserialize_Color();
            DrawRectangleGradientV(posX, posY, width, height, top, bottom);
            break;
        }
        case 214: // DrawRectangleGradientH
        {
            int posX = deserialize_le<int>();
            int posY = deserialize_le<int>();
            int width = deserialize_le<int>();
            int height = deserialize_le<int>();
            Color left = deserialize_Color();
            Color right = deserialize_Color();
            DrawRectangleGradientH(posX, posY, width, height, left, right);
            break;
        }
        case 215: // DrawRectangleGradientEx
        {
            Rectangle rec = deserialize_Rectangle();
            Color topLeft = deserialize_Color();
            Color bottomLeft = deserialize_Color();
            Color bottomRight = deserialize_Color();
            Color topRight = deserialize_Color();
            DrawRectangleGradientEx(rec, topLeft, bottomLeft, bottomRight, topRight);
            break;
        }
        case 216: // DrawRectangleLines
        {
            int posX = deserialize_le<int>();
            int posY = deserialize_le<int>();
            int width = deserialize_le<int>();
            int height = deserialize_le<int>();
            Color color = deserialize_Color();
            DrawRectangleLines(posX, posY, width, height, color);
            break;
        }
        case 217: // DrawRectangleLinesEx
        {
            Rectangle rec = deserialize_Rectangle();
            float lineThick = deserialize_le<float>();
            Color color = deserialize_Color();
            DrawRectangleLinesEx(rec, lineThick, color);
            break;
        }
        case 218: // DrawRectangleRounded
        {
            Rectangle rec = deserialize_Rectangle();
            float roundness = deserialize_le<float>();
            int segments = deserialize_le<int>();
            Color color = deserialize_Color();
            DrawRectangleRounded(rec, roundness, segments, color);
            break;
        }
        case 219: // DrawRectangleRoundedLines
        {
            Rectangle rec = deserialize_Rectangle();
            float roundness = deserialize_le<float>();
            int segments = deserialize_le<int>();
            Color color = deserialize_Color();
            DrawRectangleRoundedLines(rec, roundness, segments, color);
            break;
        }
        case 220: // DrawRectangleRoundedLinesEx
        {
            Rectangle rec = deserialize_Rectangle();
            float roundness = deserialize_le<float>();
            int segments = deserialize_le<int>();
            float lineThick = deserialize_le<float>();
            Color color = deserialize_Color();
            DrawRectangleRoundedLinesEx(rec, roundness, segments, lineThick, color);
            break;
        }
        case 221: // DrawTriangle
        {
            Vector2 v1 = deserialize_Vector2();
            Vector2 v2 = deserialize_Vector2();
            Vector2 v3 = deserialize_Vector2();
            Color color = deserialize_Color();
            DrawTriangle(v1, v2, v3, color);
            break;
        }
        case 222: // DrawTriangleLines
        {
            Vector2 v1 = deserialize_Vector2();
            Vector2 v2 = deserialize_Vector2();
            Vector2 v3 = deserialize_Vector2();
            Color color = deserialize_Color();
            DrawTriangleLines(v1, v2, v3, color);
            break;
        }
        case 223: // DrawTriangleFan
        {
            int length_points = deserialize_le<int>();
            std::vector<Vector2> temp_points(length_points);
            for(int i = 0; i < length_points; i++) {
                temp_points[i] = deserialize_Vector2();
            }
            int pointCount = deserialize_le<int>();
            Color color = deserialize_Color();
            DrawTriangleFan(temp_points.data(), pointCount, color);
            break;
        }
        case 224: // DrawTriangleStrip
        {
            int length_points = deserialize_le<int>();
            std::vector<Vector2> temp_points(length_points);
            for(int i = 0; i < length_points; i++) {
                temp_points[i] = deserialize_Vector2();
            }
            int pointCount = deserialize_le<int>();
            Color color = deserialize_Color();
            DrawTriangleStrip(temp_points.data(), pointCount, color);
            break;
        }
        case 225: // DrawPoly
        {
            Vector2 center = deserialize_Vector2();
            int sides = deserialize_le<int>();
            float radius = deserialize_le<float>();
            float rotation = deserialize_le<float>();
            Color color = deserialize_Color();
            DrawPoly(center, sides, radius, rotation, color);
            break;
        }
        case 226: // DrawPolyLines
        {
            Vector2 center = deserialize_Vector2();
            int sides = deserialize_le<int>();
            float radius = deserialize_le<float>();
            float rotation = deserialize_le<float>();
            Color color = deserialize_Color();
            DrawPolyLines(center, sides, radius, rotation, color);
            break;
        }
        case 227: // DrawPolyLinesEx
        {
            Vector2 center = deserialize_Vector2();
            int sides = deserialize_le<int>();
            float radius = deserialize_le<float>();
            float rotation = deserialize_le<float>();
            float lineThick = deserialize_le<float>();
            Color color = deserialize_Color();
            DrawPolyLinesEx(center, sides, radius, rotation, lineThick, color);
            break;
        }
        case 228: // DrawSplineLinear
        {
            int length_points = deserialize_le<int>();
            std::vector<Vector2> temp_points(length_points);
            for(int i = 0; i < length_points; i++) {
                temp_points[i] = deserialize_Vector2();
            }
            int pointCount = deserialize_le<int>();
            float thick = deserialize_le<float>();
            Color color = deserialize_Color();
            DrawSplineLinear(temp_points.data(), pointCount, thick, color);
            break;
        }
        case 229: // DrawSplineBasis
        {
            int length_points = deserialize_le<int>();
            std::vector<Vector2> temp_points(length_points);
            for(int i = 0; i < length_points; i++) {
                temp_points[i] = deserialize_Vector2();
            }
            int pointCount = deserialize_le<int>();
            float thick = deserialize_le<float>();
            Color color = deserialize_Color();
            DrawSplineBasis(temp_points.data(), pointCount, thick, color);
            break;
        }
        case 230: // DrawSplineCatmullRom
        {
            int length_points = deserialize_le<int>();
            std::vector<Vector2> temp_points(length_points);
            for(int i = 0; i < length_points; i++) {
                temp_points[i] = deserialize_Vector2();
            }
            int pointCount = deserialize_le<int>();
            float thick = deserialize_le<float>();
            Color color = deserialize_Color();
            DrawSplineCatmullRom(temp_points.data(), pointCount, thick, color);
            break;
        }
        case 231: // DrawSplineBezierQuadratic
        {
            int length_points = deserialize_le<int>();
            std::vector<Vector2> temp_points(length_points);
            for(int i = 0; i < length_points; i++) {
                temp_points[i] = deserialize_Vector2();
            }
            int pointCount = deserialize_le<int>();
            float thick = deserialize_le<float>();
            Color color = deserialize_Color();
            DrawSplineBezierQuadratic(temp_points.data(), pointCount, thick, color);
            break;
        }
        case 232: // DrawSplineBezierCubic
        {
            int length_points = deserialize_le<int>();
            std::vector<Vector2> temp_points(length_points);
            for(int i = 0; i < length_points; i++) {
                temp_points[i] = deserialize_Vector2();
            }
            int pointCount = deserialize_le<int>();
            float thick = deserialize_le<float>();
            Color color = deserialize_Color();
            DrawSplineBezierCubic(temp_points.data(), pointCount, thick, color);
            break;
        }
        case 233: // DrawSplineSegmentLinear
        {
            Vector2 p1 = deserialize_Vector2();
            Vector2 p2 = deserialize_Vector2();
            float thick = deserialize_le<float>();
            Color color = deserialize_Color();
            DrawSplineSegmentLinear(p1, p2, thick, color);
            break;
        }
        case 234: // DrawSplineSegmentBasis
        {
            Vector2 p1 = deserialize_Vector2();
            Vector2 p2 = deserialize_Vector2();
            Vector2 p3 = deserialize_Vector2();
            Vector2 p4 = deserialize_Vector2();
            float thick = deserialize_le<float>();
            Color color = deserialize_Color();
            DrawSplineSegmentBasis(p1, p2, p3, p4, thick, color);
            break;
        }
        case 235: // DrawSplineSegmentCatmullRom
        {
            Vector2 p1 = deserialize_Vector2();
            Vector2 p2 = deserialize_Vector2();
            Vector2 p3 = deserialize_Vector2();
            Vector2 p4 = deserialize_Vector2();
            float thick = deserialize_le<float>();
            Color color = deserialize_Color();
            DrawSplineSegmentCatmullRom(p1, p2, p3, p4, thick, color);
            break;
        }
        case 236: // DrawSplineSegmentBezierQuadratic
        {
            Vector2 p1 = deserialize_Vector2();
            Vector2 c2 = deserialize_Vector2();
            Vector2 p3 = deserialize_Vector2();
            float thick = deserialize_le<float>();
            Color color = deserialize_Color();
            DrawSplineSegmentBezierQuadratic(p1, c2, p3, thick, color);
            break;
        }
        case 237: // DrawSplineSegmentBezierCubic
        {
            Vector2 p1 = deserialize_Vector2();
            Vector2 c2 = deserialize_Vector2();
            Vector2 c3 = deserialize_Vector2();
            Vector2 p4 = deserialize_Vector2();
            float thick = deserialize_le<float>();
            Color color = deserialize_Color();
            DrawSplineSegmentBezierCubic(p1, c2, c3, p4, thick, color);
            break;
        }
        case 238: // GetSplinePointLinear
        {
            Vector2 startPos = deserialize_Vector2();
            Vector2 endPos = deserialize_Vector2();
            float t = deserialize_le<float>();
            Vector2 result = GetSplinePointLinear(startPos, endPos, t);
            break;
        }
        case 239: // GetSplinePointBasis
        {
            Vector2 p1 = deserialize_Vector2();
            Vector2 p2 = deserialize_Vector2();
            Vector2 p3 = deserialize_Vector2();
            Vector2 p4 = deserialize_Vector2();
            float t = deserialize_le<float>();
            Vector2 result = GetSplinePointBasis(p1, p2, p3, p4, t);
            break;
        }
        case 240: // GetSplinePointCatmullRom
        {
            Vector2 p1 = deserialize_Vector2();
            Vector2 p2 = deserialize_Vector2();
            Vector2 p3 = deserialize_Vector2();
            Vector2 p4 = deserialize_Vector2();
            float t = deserialize_le<float>();
            Vector2 result = GetSplinePointCatmullRom(p1, p2, p3, p4, t);
            break;
        }
        case 241: // GetSplinePointBezierQuad
        {
            Vector2 p1 = deserialize_Vector2();
            Vector2 c2 = deserialize_Vector2();
            Vector2 p3 = deserialize_Vector2();
            float t = deserialize_le<float>();
            Vector2 result = GetSplinePointBezierQuad(p1, c2, p3, t);
            break;
        }
        case 242: // GetSplinePointBezierCubic
        {
            Vector2 p1 = deserialize_Vector2();
            Vector2 c2 = deserialize_Vector2();
            Vector2 c3 = deserialize_Vector2();
            Vector2 p4 = deserialize_Vector2();
            float t = deserialize_le<float>();
            Vector2 result = GetSplinePointBezierCubic(p1, c2, c3, p4, t);
            break;
        }
        case 243: // CheckCollisionRecs
        {
            Rectangle rec1 = deserialize_Rectangle();
            Rectangle rec2 = deserialize_Rectangle();
            bool result = CheckCollisionRecs(rec1, rec2);
            break;
        }
        case 244: // CheckCollisionCircles
        {
            Vector2 center1 = deserialize_Vector2();
            float radius1 = deserialize_le<float>();
            Vector2 center2 = deserialize_Vector2();
            float radius2 = deserialize_le<float>();
            bool result = CheckCollisionCircles(center1, radius1, center2, radius2);
            break;
        }
        case 245: // CheckCollisionCircleRec
        {
            Vector2 center = deserialize_Vector2();
            float radius = deserialize_le<float>();
            Rectangle rec = deserialize_Rectangle();
            bool result = CheckCollisionCircleRec(center, radius, rec);
            break;
        }
        case 246: // CheckCollisionCircleLine
        {
            Vector2 center = deserialize_Vector2();
            float radius = deserialize_le<float>();
            Vector2 p1 = deserialize_Vector2();
            Vector2 p2 = deserialize_Vector2();
            bool result = CheckCollisionCircleLine(center, radius, p1, p2);
            break;
        }
        case 247: // CheckCollisionPointRec
        {
            Vector2 point = deserialize_Vector2();
            Rectangle rec = deserialize_Rectangle();
            bool result = CheckCollisionPointRec(point, rec);
            break;
        }
        case 248: // CheckCollisionPointCircle
        {
            Vector2 point = deserialize_Vector2();
            Vector2 center = deserialize_Vector2();
            float radius = deserialize_le<float>();
            bool result = CheckCollisionPointCircle(point, center, radius);
            break;
        }
        case 249: // CheckCollisionPointTriangle
        {
            Vector2 point = deserialize_Vector2();
            Vector2 p1 = deserialize_Vector2();
            Vector2 p2 = deserialize_Vector2();
            Vector2 p3 = deserialize_Vector2();
            bool result = CheckCollisionPointTriangle(point, p1, p2, p3);
            break;
        }
        case 250: // CheckCollisionPointLine
        {
            Vector2 point = deserialize_Vector2();
            Vector2 p1 = deserialize_Vector2();
            Vector2 p2 = deserialize_Vector2();
            int threshold = deserialize_le<int>();
            bool result = CheckCollisionPointLine(point, p1, p2, threshold);
            break;
        }
        case 251: // CheckCollisionPointPoly
        {
            Vector2 point = deserialize_Vector2();
            int length_points = deserialize_le<int>();
            std::vector<Vector2> temp_points(length_points);
            for(int i = 0; i < length_points; i++) {
                temp_points[i] = deserialize_Vector2();
            }
            int pointCount = deserialize_le<int>();
            bool result = CheckCollisionPointPoly(point, temp_points.data(), pointCount);
            break;
        }
        case 252: // CheckCollisionLines
        {
            Vector2 startPos1 = deserialize_Vector2();
            Vector2 endPos1 = deserialize_Vector2();
            Vector2 startPos2 = deserialize_Vector2();
            Vector2 endPos2 = deserialize_Vector2();
            int length_collisionPoint = deserialize_le<int>();
            std::vector<Vector2> temp_collisionPoint(length_collisionPoint);
            for(int i = 0; i < length_collisionPoint; i++) {
                temp_collisionPoint[i] = deserialize_Vector2();
            }
            bool result = CheckCollisionLines(startPos1, endPos1, startPos2, endPos2, temp_collisionPoint.data());
            break;
        }
        case 253: // GetCollisionRec
        {
            Rectangle rec1 = deserialize_Rectangle();
            Rectangle rec2 = deserialize_Rectangle();
            Rectangle result = GetCollisionRec(rec1, rec2);
            break;
        }
        case 254: // LoadImage
        {
            int length_fileName = deserialize_le<int>();
            std::vector<char> temp_fileName(length_fileName);
            for(int i = 0; i < length_fileName; i++) {
                temp_fileName[i] = deserialize_le<char>();
            }
            Image result = LoadImage(temp_fileName.data());
            break;
        }
        case 255: // LoadImageRaw
        {
            int length_fileName = deserialize_le<int>();
            std::vector<char> temp_fileName(length_fileName);
            for(int i = 0; i < length_fileName; i++) {
                temp_fileName[i] = deserialize_le<char>();
            }
            int width = deserialize_le<int>();
            int height = deserialize_le<int>();
            int format = deserialize_le<int>();
            int headerSize = deserialize_le<int>();
            Image result = LoadImageRaw(temp_fileName.data(), width, height, format, headerSize);
            break;
        }
        case 256: // LoadImageAnim
        {
            int length_fileName = deserialize_le<int>();
            std::vector<char> temp_fileName(length_fileName);
            for(int i = 0; i < length_fileName; i++) {
                temp_fileName[i] = deserialize_le<char>();
            }
            int length_frames = deserialize_le<int>();
            std::vector<int> temp_frames(length_frames);
            for(int i = 0; i < length_frames; i++) {
                temp_frames[i] = deserialize_le<int>();
            }
            Image result = LoadImageAnim(temp_fileName.data(), temp_frames.data());
            break;
        }
        case 257: // LoadImageAnimFromMemory
        {
            int length_fileType = deserialize_le<int>();
            std::vector<char> temp_fileType(length_fileType);
            for(int i = 0; i < length_fileType; i++) {
                temp_fileType[i] = deserialize_le<char>();
            }
            int length_fileData = deserialize_le<int>();
            std::vector<unsigned char> temp_fileData(length_fileData);
            for(int i = 0; i < length_fileData; i++) {
                temp_fileData[i] = deserialize_le<unsigned char>();
            }
            int dataSize = deserialize_le<int>();
            int length_frames = deserialize_le<int>();
            std::vector<int> temp_frames(length_frames);
            for(int i = 0; i < length_frames; i++) {
                temp_frames[i] = deserialize_le<int>();
            }
            Image result = LoadImageAnimFromMemory(temp_fileType.data(), temp_fileData.data(), dataSize, temp_frames.data());
            break;
        }
        case 258: // LoadImageFromMemory
        {
            int length_fileType = deserialize_le<int>();
            std::vector<char> temp_fileType(length_fileType);
            for(int i = 0; i < length_fileType; i++) {
                temp_fileType[i] = deserialize_le<char>();
            }
            int length_fileData = deserialize_le<int>();
            std::vector<unsigned char> temp_fileData(length_fileData);
            for(int i = 0; i < length_fileData; i++) {
                temp_fileData[i] = deserialize_le<unsigned char>();
            }
            int dataSize = deserialize_le<int>();
            Image result = LoadImageFromMemory(temp_fileType.data(), temp_fileData.data(), dataSize);
            break;
        }
        case 259: // LoadImageFromTexture
        {
            Texture2D texture = deserialize_le<Texture2D>();
            Image result = LoadImageFromTexture(texture);
            break;
        }
        case 260: // LoadImageFromScreen
        {
            Image result = LoadImageFromScreen();
            break;
        }
        case 261: // IsImageValid
        {
            Image image = deserialize_Image();
            bool result = IsImageValid(image);
            break;
        }
        case 262: // UnloadImage
        {
            Image image = deserialize_Image();
            UnloadImage(image);
            break;
        }
        case 263: // ExportImage
        {
            Image image = deserialize_Image();
            int length_fileName = deserialize_le<int>();
            std::vector<char> temp_fileName(length_fileName);
            for(int i = 0; i < length_fileName; i++) {
                temp_fileName[i] = deserialize_le<char>();
            }
            bool result = ExportImage(image, temp_fileName.data());
            break;
        }
        case 264: // ExportImageAsCode
        {
            Image image = deserialize_Image();
            int length_fileName = deserialize_le<int>();
            std::vector<char> temp_fileName(length_fileName);
            for(int i = 0; i < length_fileName; i++) {
                temp_fileName[i] = deserialize_le<char>();
            }
            bool result = ExportImageAsCode(image, temp_fileName.data());
            break;
        }
        case 265: // GenImageColor
        {
            int width = deserialize_le<int>();
            int height = deserialize_le<int>();
            Color color = deserialize_Color();
            Image result = GenImageColor(width, height, color);
            break;
        }
        case 266: // GenImageGradientLinear
        {
            int width = deserialize_le<int>();
            int height = deserialize_le<int>();
            int direction = deserialize_le<int>();
            Color start = deserialize_Color();
            Color end = deserialize_Color();
            Image result = GenImageGradientLinear(width, height, direction, start, end);
            break;
        }
        case 267: // GenImageGradientRadial
        {
            int width = deserialize_le<int>();
            int height = deserialize_le<int>();
            float density = deserialize_le<float>();
            Color inner = deserialize_Color();
            Color outer = deserialize_Color();
            Image result = GenImageGradientRadial(width, height, density, inner, outer);
            break;
        }
        case 268: // GenImageGradientSquare
        {
            int width = deserialize_le<int>();
            int height = deserialize_le<int>();
            float density = deserialize_le<float>();
            Color inner = deserialize_Color();
            Color outer = deserialize_Color();
            Image result = GenImageGradientSquare(width, height, density, inner, outer);
            break;
        }
        case 269: // GenImageChecked
        {
            int width = deserialize_le<int>();
            int height = deserialize_le<int>();
            int checksX = deserialize_le<int>();
            int checksY = deserialize_le<int>();
            Color col1 = deserialize_Color();
            Color col2 = deserialize_Color();
            Image result = GenImageChecked(width, height, checksX, checksY, col1, col2);
            break;
        }
        case 270: // GenImageWhiteNoise
        {
            int width = deserialize_le<int>();
            int height = deserialize_le<int>();
            float factor = deserialize_le<float>();
            Image result = GenImageWhiteNoise(width, height, factor);
            break;
        }
        case 271: // GenImagePerlinNoise
        {
            int width = deserialize_le<int>();
            int height = deserialize_le<int>();
            int offsetX = deserialize_le<int>();
            int offsetY = deserialize_le<int>();
            float scale = deserialize_le<float>();
            Image result = GenImagePerlinNoise(width, height, offsetX, offsetY, scale);
            break;
        }
        case 272: // GenImageCellular
        {
            int width = deserialize_le<int>();
            int height = deserialize_le<int>();
            int tileSize = deserialize_le<int>();
            Image result = GenImageCellular(width, height, tileSize);
            break;
        }
        case 273: // GenImageText
        {
            int width = deserialize_le<int>();
            int height = deserialize_le<int>();
            int length_text = deserialize_le<int>();
            std::vector<char> temp_text(length_text);
            for(int i = 0; i < length_text; i++) {
                temp_text[i] = deserialize_le<char>();
            }
            Image result = GenImageText(width, height, temp_text.data());
            break;
        }
        case 274: // ImageCopy
        {
            Image image = deserialize_Image();
            Image result = ImageCopy(image);
            break;
        }
        case 275: // ImageFromImage
        {
            Image image = deserialize_Image();
            Rectangle rec = deserialize_Rectangle();
            Image result = ImageFromImage(image, rec);
            break;
        }
        case 276: // ImageFromChannel
        {
            Image image = deserialize_Image();
            int selectedChannel = deserialize_le<int>();
            Image result = ImageFromChannel(image, selectedChannel);
            break;
        }
        case 277: // ImageText
        {
            int length_text = deserialize_le<int>();
            std::vector<char> temp_text(length_text);
            for(int i = 0; i < length_text; i++) {
                temp_text[i] = deserialize_le<char>();
            }
            int fontSize = deserialize_le<int>();
            Color color = deserialize_Color();
            Image result = ImageText(temp_text.data(), fontSize, color);
            break;
        }
        case 278: // ImageTextEx
        {
            Font font = deserialize_Font();
            int length_text = deserialize_le<int>();
            std::vector<char> temp_text(length_text);
            for(int i = 0; i < length_text; i++) {
                temp_text[i] = deserialize_le<char>();
            }
            float fontSize = deserialize_le<float>();
            float spacing = deserialize_le<float>();
            Color tint = deserialize_Color();
            Image result = ImageTextEx(font, temp_text.data(), fontSize, spacing, tint);
            break;
        }
        case 279: // ImageFormat
        {
            int length_image = deserialize_le<int>();
            std::vector<Image> temp_image(length_image);
            for(int i = 0; i < length_image; i++) {
                temp_image[i] = deserialize_Image();
            }
            int newFormat = deserialize_le<int>();
            ImageFormat(temp_image.data(), newFormat);
            break;
        }
        case 280: // ImageToPOT
        {
            int length_image = deserialize_le<int>();
            std::vector<Image> temp_image(length_image);
            for(int i = 0; i < length_image; i++) {
                temp_image[i] = deserialize_Image();
            }
            Color fill = deserialize_Color();
            ImageToPOT(temp_image.data(), fill);
            break;
        }
        case 281: // ImageCrop
        {
            int length_image = deserialize_le<int>();
            std::vector<Image> temp_image(length_image);
            for(int i = 0; i < length_image; i++) {
                temp_image[i] = deserialize_Image();
            }
            Rectangle crop = deserialize_Rectangle();
            ImageCrop(temp_image.data(), crop);
            break;
        }
        case 282: // ImageAlphaCrop
        {
            int length_image = deserialize_le<int>();
            std::vector<Image> temp_image(length_image);
            for(int i = 0; i < length_image; i++) {
                temp_image[i] = deserialize_Image();
            }
            float threshold = deserialize_le<float>();
            ImageAlphaCrop(temp_image.data(), threshold);
            break;
        }
        case 283: // ImageAlphaClear
        {
            int length_image = deserialize_le<int>();
            std::vector<Image> temp_image(length_image);
            for(int i = 0; i < length_image; i++) {
                temp_image[i] = deserialize_Image();
            }
            Color color = deserialize_Color();
            float threshold = deserialize_le<float>();
            ImageAlphaClear(temp_image.data(), color, threshold);
            break;
        }
        case 284: // ImageAlphaMask
        {
            int length_image = deserialize_le<int>();
            std::vector<Image> temp_image(length_image);
            for(int i = 0; i < length_image; i++) {
                temp_image[i] = deserialize_Image();
            }
            Image alphaMask = deserialize_Image();
            ImageAlphaMask(temp_image.data(), alphaMask);
            break;
        }
        case 285: // ImageAlphaPremultiply
        {
            int length_image = deserialize_le<int>();
            std::vector<Image> temp_image(length_image);
            for(int i = 0; i < length_image; i++) {
                temp_image[i] = deserialize_Image();
            }
            ImageAlphaPremultiply(temp_image.data());
            break;
        }
        case 286: // ImageBlurGaussian
        {
            int length_image = deserialize_le<int>();
            std::vector<Image> temp_image(length_image);
            for(int i = 0; i < length_image; i++) {
                temp_image[i] = deserialize_Image();
            }
            int blurSize = deserialize_le<int>();
            ImageBlurGaussian(temp_image.data(), blurSize);
            break;
        }
        case 287: // ImageKernelConvolution
        {
            int length_image = deserialize_le<int>();
            std::vector<Image> temp_image(length_image);
            for(int i = 0; i < length_image; i++) {
                temp_image[i] = deserialize_Image();
            }
            int length_kernel = deserialize_le<int>();
            std::vector<float> temp_kernel(length_kernel);
            for(int i = 0; i < length_kernel; i++) {
                temp_kernel[i] = deserialize_le<float>();
            }
            int kernelSize = deserialize_le<int>();
            ImageKernelConvolution(temp_image.data(), temp_kernel.data(), kernelSize);
            break;
        }
        case 288: // ImageResize
        {
            int length_image = deserialize_le<int>();
            std::vector<Image> temp_image(length_image);
            for(int i = 0; i < length_image; i++) {
                temp_image[i] = deserialize_Image();
            }
            int newWidth = deserialize_le<int>();
            int newHeight = deserialize_le<int>();
            ImageResize(temp_image.data(), newWidth, newHeight);
            break;
        }
        case 289: // ImageResizeNN
        {
            int length_image = deserialize_le<int>();
            std::vector<Image> temp_image(length_image);
            for(int i = 0; i < length_image; i++) {
                temp_image[i] = deserialize_Image();
            }
            int newWidth = deserialize_le<int>();
            int newHeight = deserialize_le<int>();
            ImageResizeNN(temp_image.data(), newWidth, newHeight);
            break;
        }
        case 290: // ImageResizeCanvas
        {
            int length_image = deserialize_le<int>();
            std::vector<Image> temp_image(length_image);
            for(int i = 0; i < length_image; i++) {
                temp_image[i] = deserialize_Image();
            }
            int newWidth = deserialize_le<int>();
            int newHeight = deserialize_le<int>();
            int offsetX = deserialize_le<int>();
            int offsetY = deserialize_le<int>();
            Color fill = deserialize_Color();
            ImageResizeCanvas(temp_image.data(), newWidth, newHeight, offsetX, offsetY, fill);
            break;
        }
        case 291: // ImageMipmaps
        {
            int length_image = deserialize_le<int>();
            std::vector<Image> temp_image(length_image);
            for(int i = 0; i < length_image; i++) {
                temp_image[i] = deserialize_Image();
            }
            ImageMipmaps(temp_image.data());
            break;
        }
        case 292: // ImageDither
        {
            int length_image = deserialize_le<int>();
            std::vector<Image> temp_image(length_image);
            for(int i = 0; i < length_image; i++) {
                temp_image[i] = deserialize_Image();
            }
            int rBpp = deserialize_le<int>();
            int gBpp = deserialize_le<int>();
            int bBpp = deserialize_le<int>();
            int aBpp = deserialize_le<int>();
            ImageDither(temp_image.data(), rBpp, gBpp, bBpp, aBpp);
            break;
        }
        case 293: // ImageFlipVertical
        {
            int length_image = deserialize_le<int>();
            std::vector<Image> temp_image(length_image);
            for(int i = 0; i < length_image; i++) {
                temp_image[i] = deserialize_Image();
            }
            ImageFlipVertical(temp_image.data());
            break;
        }
        case 294: // ImageFlipHorizontal
        {
            int length_image = deserialize_le<int>();
            std::vector<Image> temp_image(length_image);
            for(int i = 0; i < length_image; i++) {
                temp_image[i] = deserialize_Image();
            }
            ImageFlipHorizontal(temp_image.data());
            break;
        }
        case 295: // ImageRotate
        {
            int length_image = deserialize_le<int>();
            std::vector<Image> temp_image(length_image);
            for(int i = 0; i < length_image; i++) {
                temp_image[i] = deserialize_Image();
            }
            int degrees = deserialize_le<int>();
            ImageRotate(temp_image.data(), degrees);
            break;
        }
        case 296: // ImageRotateCW
        {
            int length_image = deserialize_le<int>();
            std::vector<Image> temp_image(length_image);
            for(int i = 0; i < length_image; i++) {
                temp_image[i] = deserialize_Image();
            }
            ImageRotateCW(temp_image.data());
            break;
        }
        case 297: // ImageRotateCCW
        {
            int length_image = deserialize_le<int>();
            std::vector<Image> temp_image(length_image);
            for(int i = 0; i < length_image; i++) {
                temp_image[i] = deserialize_Image();
            }
            ImageRotateCCW(temp_image.data());
            break;
        }
        case 298: // ImageColorTint
        {
            int length_image = deserialize_le<int>();
            std::vector<Image> temp_image(length_image);
            for(int i = 0; i < length_image; i++) {
                temp_image[i] = deserialize_Image();
            }
            Color color = deserialize_Color();
            ImageColorTint(temp_image.data(), color);
            break;
        }
        case 299: // ImageColorInvert
        {
            int length_image = deserialize_le<int>();
            std::vector<Image> temp_image(length_image);
            for(int i = 0; i < length_image; i++) {
                temp_image[i] = deserialize_Image();
            }
            ImageColorInvert(temp_image.data());
            break;
        }
        case 300: // ImageColorGrayscale
        {
            int length_image = deserialize_le<int>();
            std::vector<Image> temp_image(length_image);
            for(int i = 0; i < length_image; i++) {
                temp_image[i] = deserialize_Image();
            }
            ImageColorGrayscale(temp_image.data());
            break;
        }
        case 301: // ImageColorContrast
        {
            int length_image = deserialize_le<int>();
            std::vector<Image> temp_image(length_image);
            for(int i = 0; i < length_image; i++) {
                temp_image[i] = deserialize_Image();
            }
            float contrast = deserialize_le<float>();
            ImageColorContrast(temp_image.data(), contrast);
            break;
        }
        case 302: // ImageColorBrightness
        {
            int length_image = deserialize_le<int>();
            std::vector<Image> temp_image(length_image);
            for(int i = 0; i < length_image; i++) {
                temp_image[i] = deserialize_Image();
            }
            int brightness = deserialize_le<int>();
            ImageColorBrightness(temp_image.data(), brightness);
            break;
        }
        case 303: // ImageColorReplace
        {
            int length_image = deserialize_le<int>();
            std::vector<Image> temp_image(length_image);
            for(int i = 0; i < length_image; i++) {
                temp_image[i] = deserialize_Image();
            }
            Color color = deserialize_Color();
            Color replace = deserialize_Color();
            ImageColorReplace(temp_image.data(), color, replace);
            break;
        }
        case 304: // UnloadImageColors
        {
            int length_colors = deserialize_le<int>();
            std::vector<Color> temp_colors(length_colors);
            for(int i = 0; i < length_colors; i++) {
                temp_colors[i] = deserialize_Color();
            }
            UnloadImageColors(temp_colors.data());
            break;
        }
        case 305: // UnloadImagePalette
        {
            int length_colors = deserialize_le<int>();
            std::vector<Color> temp_colors(length_colors);
            for(int i = 0; i < length_colors; i++) {
                temp_colors[i] = deserialize_Color();
            }
            UnloadImagePalette(temp_colors.data());
            break;
        }
        case 306: // GetImageAlphaBorder
        {
            Image image = deserialize_Image();
            float threshold = deserialize_le<float>();
            Rectangle result = GetImageAlphaBorder(image, threshold);
            break;
        }
        case 307: // GetImageColor
        {
            Image image = deserialize_Image();
            int x = deserialize_le<int>();
            int y = deserialize_le<int>();
            Color result = GetImageColor(image, x, y);
            break;
        }
        case 308: // ImageClearBackground
        {
            int length_dst = deserialize_le<int>();
            std::vector<Image> temp_dst(length_dst);
            for(int i = 0; i < length_dst; i++) {
                temp_dst[i] = deserialize_Image();
            }
            Color color = deserialize_Color();
            ImageClearBackground(temp_dst.data(), color);
            break;
        }
        case 309: // ImageDrawPixel
        {
            int length_dst = deserialize_le<int>();
            std::vector<Image> temp_dst(length_dst);
            for(int i = 0; i < length_dst; i++) {
                temp_dst[i] = deserialize_Image();
            }
            int posX = deserialize_le<int>();
            int posY = deserialize_le<int>();
            Color color = deserialize_Color();
            ImageDrawPixel(temp_dst.data(), posX, posY, color);
            break;
        }
        case 310: // ImageDrawPixelV
        {
            int length_dst = deserialize_le<int>();
            std::vector<Image> temp_dst(length_dst);
            for(int i = 0; i < length_dst; i++) {
                temp_dst[i] = deserialize_Image();
            }
            Vector2 position = deserialize_Vector2();
            Color color = deserialize_Color();
            ImageDrawPixelV(temp_dst.data(), position, color);
            break;
        }
        case 311: // ImageDrawLine
        {
            int length_dst = deserialize_le<int>();
            std::vector<Image> temp_dst(length_dst);
            for(int i = 0; i < length_dst; i++) {
                temp_dst[i] = deserialize_Image();
            }
            int startPosX = deserialize_le<int>();
            int startPosY = deserialize_le<int>();
            int endPosX = deserialize_le<int>();
            int endPosY = deserialize_le<int>();
            Color color = deserialize_Color();
            ImageDrawLine(temp_dst.data(), startPosX, startPosY, endPosX, endPosY, color);
            break;
        }
        case 312: // ImageDrawLineV
        {
            int length_dst = deserialize_le<int>();
            std::vector<Image> temp_dst(length_dst);
            for(int i = 0; i < length_dst; i++) {
                temp_dst[i] = deserialize_Image();
            }
            Vector2 start = deserialize_Vector2();
            Vector2 end = deserialize_Vector2();
            Color color = deserialize_Color();
            ImageDrawLineV(temp_dst.data(), start, end, color);
            break;
        }
        case 313: // ImageDrawLineEx
        {
            int length_dst = deserialize_le<int>();
            std::vector<Image> temp_dst(length_dst);
            for(int i = 0; i < length_dst; i++) {
                temp_dst[i] = deserialize_Image();
            }
            Vector2 start = deserialize_Vector2();
            Vector2 end = deserialize_Vector2();
            int thick = deserialize_le<int>();
            Color color = deserialize_Color();
            ImageDrawLineEx(temp_dst.data(), start, end, thick, color);
            break;
        }
        case 314: // ImageDrawCircle
        {
            int length_dst = deserialize_le<int>();
            std::vector<Image> temp_dst(length_dst);
            for(int i = 0; i < length_dst; i++) {
                temp_dst[i] = deserialize_Image();
            }
            int centerX = deserialize_le<int>();
            int centerY = deserialize_le<int>();
            int radius = deserialize_le<int>();
            Color color = deserialize_Color();
            ImageDrawCircle(temp_dst.data(), centerX, centerY, radius, color);
            break;
        }
        case 315: // ImageDrawCircleV
        {
            int length_dst = deserialize_le<int>();
            std::vector<Image> temp_dst(length_dst);
            for(int i = 0; i < length_dst; i++) {
                temp_dst[i] = deserialize_Image();
            }
            Vector2 center = deserialize_Vector2();
            int radius = deserialize_le<int>();
            Color color = deserialize_Color();
            ImageDrawCircleV(temp_dst.data(), center, radius, color);
            break;
        }
        case 316: // ImageDrawCircleLines
        {
            int length_dst = deserialize_le<int>();
            std::vector<Image> temp_dst(length_dst);
            for(int i = 0; i < length_dst; i++) {
                temp_dst[i] = deserialize_Image();
            }
            int centerX = deserialize_le<int>();
            int centerY = deserialize_le<int>();
            int radius = deserialize_le<int>();
            Color color = deserialize_Color();
            ImageDrawCircleLines(temp_dst.data(), centerX, centerY, radius, color);
            break;
        }
        case 317: // ImageDrawCircleLinesV
        {
            int length_dst = deserialize_le<int>();
            std::vector<Image> temp_dst(length_dst);
            for(int i = 0; i < length_dst; i++) {
                temp_dst[i] = deserialize_Image();
            }
            Vector2 center = deserialize_Vector2();
            int radius = deserialize_le<int>();
            Color color = deserialize_Color();
            ImageDrawCircleLinesV(temp_dst.data(), center, radius, color);
            break;
        }
        case 318: // ImageDrawRectangle
        {
            int length_dst = deserialize_le<int>();
            std::vector<Image> temp_dst(length_dst);
            for(int i = 0; i < length_dst; i++) {
                temp_dst[i] = deserialize_Image();
            }
            int posX = deserialize_le<int>();
            int posY = deserialize_le<int>();
            int width = deserialize_le<int>();
            int height = deserialize_le<int>();
            Color color = deserialize_Color();
            ImageDrawRectangle(temp_dst.data(), posX, posY, width, height, color);
            break;
        }
        case 319: // ImageDrawRectangleV
        {
            Image temp_dst = deserialize_Image();
            Vector2 position = deserialize_Vector2();
            Vector2 size = deserialize_Vector2();
            Color color = deserialize_Color();
            ImageDrawRectangleV(&temp_dst, position, size, color);
            break;
        }
        case 320: // ImageDrawRectangleRec
        {
            int length_dst = deserialize_le<int>();
            std::vector<Image> temp_dst(length_dst);
            for(int i = 0; i < length_dst; i++) {
                temp_dst[i] = deserialize_Image();
            }
            Rectangle rec = deserialize_Rectangle();
            Color color = deserialize_Color();
            ImageDrawRectangleRec(temp_dst.data(), rec, color);
            break;
        }
        case 321: // ImageDrawRectangleLines
        {
            int length_dst = deserialize_le<int>();
            std::vector<Image> temp_dst(length_dst);
            for(int i = 0; i < length_dst; i++) {
                temp_dst[i] = deserialize_Image();
            }
            Rectangle rec = deserialize_Rectangle();
            int thick = deserialize_le<int>();
            Color color = deserialize_Color();
            ImageDrawRectangleLines(temp_dst.data(), rec, thick, color);
            break;
        }
        case 322: // ImageDrawTriangle
        {
            int length_dst = deserialize_le<int>();
            std::vector<Image> temp_dst(length_dst);
            for(int i = 0; i < length_dst; i++) {
                temp_dst[i] = deserialize_Image();
            }
            Vector2 v1 = deserialize_Vector2();
            Vector2 v2 = deserialize_Vector2();
            Vector2 v3 = deserialize_Vector2();
            Color color = deserialize_Color();
            ImageDrawTriangle(temp_dst.data(), v1, v2, v3, color);
            break;
        }
        case 323: // ImageDrawTriangleEx
        {
            int length_dst = deserialize_le<int>();
            std::vector<Image> temp_dst(length_dst);
            for(int i = 0; i < length_dst; i++) {
                temp_dst[i] = deserialize_Image();
            }
            Vector2 v1 = deserialize_Vector2();
            Vector2 v2 = deserialize_Vector2();
            Vector2 v3 = deserialize_Vector2();
            Color c1 = deserialize_Color();
            Color c2 = deserialize_Color();
            Color c3 = deserialize_Color();
            ImageDrawTriangleEx(temp_dst.data(), v1, v2, v3, c1, c2, c3);
            break;
        }
        case 324: // ImageDrawTriangleLines
        {
            int length_dst = deserialize_le<int>();
            std::vector<Image> temp_dst(length_dst);
            for(int i = 0; i < length_dst; i++) {
                temp_dst[i] = deserialize_Image();
            }
            Vector2 v1 = deserialize_Vector2();
            Vector2 v2 = deserialize_Vector2();
            Vector2 v3 = deserialize_Vector2();
            Color color = deserialize_Color();
            ImageDrawTriangleLines(temp_dst.data(), v1, v2, v3, color);
            break;
        }
        case 325: // ImageDrawTriangleFan
        {
            int length_dst = deserialize_le<int>();
            std::vector<Image> temp_dst(length_dst);
            for(int i = 0; i < length_dst; i++) {
                temp_dst[i] = deserialize_Image();
            }
            int length_points = deserialize_le<int>();
            std::vector<Vector2> temp_points(length_points);
            for(int i = 0; i < length_points; i++) {
                temp_points[i] = deserialize_Vector2();
            }
            int pointCount = deserialize_le<int>();
            Color color = deserialize_Color();
            ImageDrawTriangleFan(temp_dst.data(), temp_points.data(), pointCount, color);
            break;
        }
        case 326: // ImageDrawTriangleStrip
        {
            int length_dst = deserialize_le<int>();
            std::vector<Image> temp_dst(length_dst);
            for(int i = 0; i < length_dst; i++) {
                temp_dst[i] = deserialize_Image();
            }
            int length_points = deserialize_le<int>();
            std::vector<Vector2> temp_points(length_points);
            for(int i = 0; i < length_points; i++) {
                temp_points[i] = deserialize_Vector2();
            }
            int pointCount = deserialize_le<int>();
            Color color = deserialize_Color();
            ImageDrawTriangleStrip(temp_dst.data(), temp_points.data(), pointCount, color);
            break;
        }
        case 327: // ImageDraw
        {
            int length_dst = deserialize_le<int>();
            std::vector<Image> temp_dst(length_dst);
            for(int i = 0; i < length_dst; i++) {
                temp_dst[i] = deserialize_Image();
            }
            Image src = deserialize_Image();
            Rectangle srcRec = deserialize_Rectangle();
            Rectangle dstRec = deserialize_Rectangle();
            Color tint = deserialize_Color();
            ImageDraw(temp_dst.data(), src, srcRec, dstRec, tint);
            break;
        }
        case 328: // ImageDrawText
        {
            int length_dst = deserialize_le<int>();
            std::vector<Image> temp_dst(length_dst);
            for(int i = 0; i < length_dst; i++) {
                temp_dst[i] = deserialize_Image();
            }
            int length_text = deserialize_le<int>();
            std::vector<char> temp_text(length_text);
            for(int i = 0; i < length_text; i++) {
                temp_text[i] = deserialize_le<char>();
            }
            int posX = deserialize_le<int>();
            int posY = deserialize_le<int>();
            int fontSize = deserialize_le<int>();
            Color color = deserialize_Color();
            ImageDrawText(temp_dst.data(), temp_text.data(), posX, posY, fontSize, color);
            break;
        }
        case 329: // ImageDrawTextEx
        {
            int length_dst = deserialize_le<int>();
            std::vector<Image> temp_dst(length_dst);
            for(int i = 0; i < length_dst; i++) {
                temp_dst[i] = deserialize_Image();
            }
            Font font = deserialize_Font();
            int length_text = deserialize_le<int>();
            std::vector<char> temp_text(length_text);
            for(int i = 0; i < length_text; i++) {
                temp_text[i] = deserialize_le<char>();
            }
            Vector2 position = deserialize_Vector2();
            float fontSize = deserialize_le<float>();
            float spacing = deserialize_le<float>();
            Color tint = deserialize_Color();
            ImageDrawTextEx(temp_dst.data(), font, temp_text.data(), position, fontSize, spacing, tint);
            break;
        }
        case 330: // LoadTexture
        {
            int length_fileName = deserialize_le<int>();
            std::vector<char> temp_fileName(length_fileName);
            for(int i = 0; i < length_fileName; i++) {
                temp_fileName[i] = deserialize_le<char>();
            }
            Texture2D result = LoadTexture(temp_fileName.data());
            break;
        }
        case 331: // LoadTextureFromImage
        {
            Image image = deserialize_Image();
            Texture2D result = LoadTextureFromImage(image);
            break;
        }
        case 332: // LoadTextureCubemap
        {
            Image image = deserialize_Image();
            int layout = deserialize_le<int>();
            TextureCubemap result = LoadTextureCubemap(image, layout);
            break;
        }
        case 333: // LoadRenderTexture
        {
            int width = deserialize_le<int>();
            int height = deserialize_le<int>();
            RenderTexture2D result = LoadRenderTexture(width, height);
            break;
        }
        case 334: // IsTextureValid
        {
            Texture2D texture = deserialize_le<Texture2D>();
            bool result = IsTextureValid(texture);
            break;
        }
        case 335: // UnloadTexture
        {
            Texture2D texture = deserialize_le<Texture2D>();
            UnloadTexture(texture);
            break;
        }
        case 336: // IsRenderTextureValid
        {
            RenderTexture2D target = deserialize_le<RenderTexture2D>();
            bool result = IsRenderTextureValid(target);
            break;
        }
        case 337: // UnloadRenderTexture
        {
            RenderTexture2D target = deserialize_le<RenderTexture2D>();
            UnloadRenderTexture(target);
            break;
        }
        case 338: // UpdateTexture
        {
            Texture2D texture = deserialize_le<Texture2D>();
            // Skipping pixels (type: const void*) - not deserializable
            UpdateTexture(texture, nullptr);
            break;
        }
        case 339: // UpdateTextureRec
        {
            Texture2D texture = deserialize_le<Texture2D>();
            Rectangle rec = deserialize_Rectangle();
            // Skipping pixels (type: const void*) - not deserializable
            UpdateTextureRec(texture, rec, nullptr);
            break;
        }
        case 340: // GenTextureMipmaps
        {
            int length_texture = deserialize_le<int>();
            std::vector<Texture2D> temp_texture(length_texture);
            for(int i = 0; i < length_texture; i++) {
                temp_texture[i] = deserialize_le<Texture2D>();
            }
            GenTextureMipmaps(temp_texture.data());
            break;
        }
        case 341: // SetTextureFilter
        {
            Texture2D texture = deserialize_le<Texture2D>();
            int filter = deserialize_le<int>();
            SetTextureFilter(texture, filter);
            break;
        }
        case 342: // SetTextureWrap
        {
            Texture2D texture = deserialize_le<Texture2D>();
            int wrap = deserialize_le<int>();
            SetTextureWrap(texture, wrap);
            break;
        }
        case 343: // DrawTexture
        {
            Texture2D texture = deserialize_le<Texture2D>();
            int posX = deserialize_le<int>();
            int posY = deserialize_le<int>();
            Color tint = deserialize_Color();
            DrawTexture(texture, posX, posY, tint);
            break;
        }
        case 344: // DrawTextureV
        {
            Texture2D texture = deserialize_le<Texture2D>();
            Vector2 position = deserialize_Vector2();
            Color tint = deserialize_Color();
            DrawTextureV(texture, position, tint);
            break;
        }
        case 345: // DrawTextureEx
        {
            Texture2D texture = deserialize_le<Texture2D>();
            Vector2 position = deserialize_Vector2();
            float rotation = deserialize_le<float>();
            float scale = deserialize_le<float>();
            Color tint = deserialize_Color();
            DrawTextureEx(texture, position, rotation, scale, tint);
            break;
        }
        case 346: // DrawTextureRec
        {
            Texture2D texture = deserialize_le<Texture2D>();
            Rectangle source = deserialize_Rectangle();
            Vector2 position = deserialize_Vector2();
            Color tint = deserialize_Color();
            DrawTextureRec(texture, source, position, tint);
            break;
        }
        case 347: // DrawTexturePro
        {
            Texture2D texture = deserialize_le<Texture2D>();
            Rectangle source = deserialize_Rectangle();
            Rectangle dest = deserialize_Rectangle();
            Vector2 origin = deserialize_Vector2();
            float rotation = deserialize_le<float>();
            Color tint = deserialize_Color();
            DrawTexturePro(texture, source, dest, origin, rotation, tint);
            break;
        }
        case 348: // DrawTextureNPatch
        {
            Texture2D texture = deserialize_le<Texture2D>();
            NPatchInfo nPatchInfo = deserialize_NPatchInfo();
            Rectangle dest = deserialize_Rectangle();
            Vector2 origin = deserialize_Vector2();
            float rotation = deserialize_le<float>();
            Color tint = deserialize_Color();
            DrawTextureNPatch(texture, nPatchInfo, dest, origin, rotation, tint);
            break;
        }
        case 349: // ColorIsEqual
        {
            Color col1 = deserialize_Color();
            Color col2 = deserialize_Color();
            bool result = ColorIsEqual(col1, col2);
            break;
        }
        case 350: // Fade
        {
            Color color = deserialize_Color();
            float alpha = deserialize_le<float>();
            Color result = Fade(color, alpha);
            break;
        }
        case 351: // ColorToInt
        {
            Color color = deserialize_Color();
            int result = ColorToInt(color);
            break;
        }
        case 352: // ColorNormalize
        {
            Color color = deserialize_Color();
            Vector4 result = ColorNormalize(color);
            break;
        }
        case 353: // ColorFromNormalized
        {
            Vector4 normalized = deserialize_Vector4();
            Color result = ColorFromNormalized(normalized);
            break;
        }
        case 354: // ColorToHSV
        {
            Color color = deserialize_Color();
            Vector3 result = ColorToHSV(color);
            break;
        }
        case 355: // ColorFromHSV
        {
            float hue = deserialize_le<float>();
            float saturation = deserialize_le<float>();
            float value = deserialize_le<float>();
            Color result = ColorFromHSV(hue, saturation, value);
            break;
        }
        case 356: // ColorTint
        {
            Color color = deserialize_Color();
            Color tint = deserialize_Color();
            Color result = ColorTint(color, tint);
            break;
        }
        case 357: // ColorBrightness
        {
            Color color = deserialize_Color();
            float factor = deserialize_le<float>();
            Color result = ColorBrightness(color, factor);
            break;
        }
        case 358: // ColorContrast
        {
            Color color = deserialize_Color();
            float contrast = deserialize_le<float>();
            Color result = ColorContrast(color, contrast);
            break;
        }
        case 359: // ColorAlpha
        {
            Color color = deserialize_Color();
            float alpha = deserialize_le<float>();
            Color result = ColorAlpha(color, alpha);
            break;
        }
        case 360: // ColorAlphaBlend
        {
            Color dst = deserialize_Color();
            Color src = deserialize_Color();
            Color tint = deserialize_Color();
            Color result = ColorAlphaBlend(dst, src, tint);
            break;
        }
        case 361: // ColorLerp
        {
            Color color1 = deserialize_Color();
            Color color2 = deserialize_Color();
            float factor = deserialize_le<float>();
            Color result = ColorLerp(color1, color2, factor);
            break;
        }
        case 362: // GetColor
        {
            unsigned int hexValue = deserialize_le<unsigned int>();
            Color result = GetColor(hexValue);
            break;
        }
        case 363: // GetPixelColor
        {
            // Skipping srcPtr (type: void*) - not deserializable
            int format = deserialize_le<int>();
            Color result = GetPixelColor(nullptr, format);
            break;
        }
        case 364: // SetPixelColor
        {
            // Skipping dstPtr (type: void*) - not deserializable
            Color color = deserialize_Color();
            int format = deserialize_le<int>();
            SetPixelColor(nullptr, color, format);
            break;
        }
        case 365: // GetPixelDataSize
        {
            int width = deserialize_le<int>();
            int height = deserialize_le<int>();
            int format = deserialize_le<int>();
            int result = GetPixelDataSize(width, height, format);
            break;
        }
        case 366: // GetFontDefault
        {
            Font result = GetFontDefault();
            break;
        }
        case 367: // LoadFont
        {
            int length_fileName = deserialize_le<int>();
            std::vector<char> temp_fileName(length_fileName);
            for(int i = 0; i < length_fileName; i++) {
                temp_fileName[i] = deserialize_le<char>();
            }
            Font result = LoadFont(temp_fileName.data());
            break;
        }
        case 368: // LoadFontEx
        {
            int length_fileName = deserialize_le<int>();
            std::vector<char> temp_fileName(length_fileName);
            for(int i = 0; i < length_fileName; i++) {
                temp_fileName[i] = deserialize_le<char>();
            }
            int fontSize = deserialize_le<int>();
            int length_codepoints = deserialize_le<int>();
            std::vector<int> temp_codepoints(length_codepoints);
            for(int i = 0; i < length_codepoints; i++) {
                temp_codepoints[i] = deserialize_le<int>();
            }
            int codepointCount = deserialize_le<int>();
            Font result = LoadFontEx(temp_fileName.data(), fontSize, temp_codepoints.data(), codepointCount);
            break;
        }
        case 369: // LoadFontFromImage
        {
            Image image = deserialize_Image();
            Color key = deserialize_Color();
            int firstChar = deserialize_le<int>();
            Font result = LoadFontFromImage(image, key, firstChar);
            break;
        }
        case 370: // LoadFontFromMemory
        {
            int length_fileType = deserialize_le<int>();
            std::vector<char> temp_fileType(length_fileType);
            for(int i = 0; i < length_fileType; i++) {
                temp_fileType[i] = deserialize_le<char>();
            }
            int length_fileData = deserialize_le<int>();
            std::vector<unsigned char> temp_fileData(length_fileData);
            for(int i = 0; i < length_fileData; i++) {
                temp_fileData[i] = deserialize_le<unsigned char>();
            }
            int dataSize = deserialize_le<int>();
            int fontSize = deserialize_le<int>();
            int length_codepoints = deserialize_le<int>();
            std::vector<int> temp_codepoints(length_codepoints);
            for(int i = 0; i < length_codepoints; i++) {
                temp_codepoints[i] = deserialize_le<int>();
            }
            int codepointCount = deserialize_le<int>();
            Font result = LoadFontFromMemory(temp_fileType.data(), temp_fileData.data(), dataSize, fontSize, temp_codepoints.data(), codepointCount);
            break;
        }
        case 371: // IsFontValid
        {
            Font font = deserialize_Font();
            bool result = IsFontValid(font);
            break;
        }
        case 372: // UnloadFontData
        {
            int length_glyphs = deserialize_le<int>();
            std::vector<GlyphInfo> temp_glyphs(length_glyphs);
            for(int i = 0; i < length_glyphs; i++) {
                temp_glyphs[i] = deserialize_GlyphInfo();
            }
            int glyphCount = deserialize_le<int>();
            UnloadFontData(temp_glyphs.data(), glyphCount);
            break;
        }
        case 373: // UnloadFont
        {
            Font font = deserialize_Font();
            UnloadFont(font);
            break;
        }
        case 374: // ExportFontAsCode
        {
            Font font = deserialize_Font();
            int length_fileName = deserialize_le<int>();
            std::vector<char> temp_fileName(length_fileName);
            for(int i = 0; i < length_fileName; i++) {
                temp_fileName[i] = deserialize_le<char>();
            }
            bool result = ExportFontAsCode(font, temp_fileName.data());
            break;
        }
        case 375: // DrawFPS
        {
            int posX = deserialize_le<int>();
            int posY = deserialize_le<int>();
            DrawFPS(posX, posY);
            break;
        }
        case 376: // DrawText
        {
            int length_text = deserialize_le<int>();
            std::vector<char> temp_text(length_text);
            for(int i = 0; i < length_text; i++) {
                temp_text[i] = deserialize_le<char>();
            }
            int posX = deserialize_le<int>();
            int posY = deserialize_le<int>();
            int fontSize = deserialize_le<int>();
            Color color = deserialize_Color();
            DrawText(temp_text.data(), posX, posY, fontSize, color);
            break;
        }
        case 377: // DrawTextEx
        {
            Font font = deserialize_Font();
            int length_text = deserialize_le<int>();
            std::vector<char> temp_text(length_text);
            for(int i = 0; i < length_text; i++) {
                temp_text[i] = deserialize_le<char>();
            }
            Vector2 position = deserialize_Vector2();
            float fontSize = deserialize_le<float>();
            float spacing = deserialize_le<float>();
            Color tint = deserialize_Color();
            DrawTextEx(font, temp_text.data(), position, fontSize, spacing, tint);
            break;
        }
        case 378: // DrawTextPro
        {
            Font font = deserialize_Font();
            int length_text = deserialize_le<int>();
            std::vector<char> temp_text(length_text);
            for(int i = 0; i < length_text; i++) {
                temp_text[i] = deserialize_le<char>();
            }
            Vector2 position = deserialize_Vector2();
            Vector2 origin = deserialize_Vector2();
            float rotation = deserialize_le<float>();
            float fontSize = deserialize_le<float>();
            float spacing = deserialize_le<float>();
            Color tint = deserialize_Color();
            DrawTextPro(font, temp_text.data(), position, origin, rotation, fontSize, spacing, tint);
            break;
        }
        case 379: // DrawTextCodepoint
        {
            Font font = deserialize_Font();
            int codepoint = deserialize_le<int>();
            Vector2 position = deserialize_Vector2();
            float fontSize = deserialize_le<float>();
            Color tint = deserialize_Color();
            DrawTextCodepoint(font, codepoint, position, fontSize, tint);
            break;
        }
        case 380: // DrawTextCodepoints
        {
            Font font = deserialize_Font();
            int length_codepoints = deserialize_le<int>();
            std::vector<int> temp_codepoints(length_codepoints);
            for(int i = 0; i < length_codepoints; i++) {
                temp_codepoints[i] = deserialize_le<int>();
            }
            int codepointCount = deserialize_le<int>();
            Vector2 position = deserialize_Vector2();
            float fontSize = deserialize_le<float>();
            float spacing = deserialize_le<float>();
            Color tint = deserialize_Color();
            DrawTextCodepoints(font, temp_codepoints.data(), codepointCount, position, fontSize, spacing, tint);
            break;
        }
        case 381: // SetTextLineSpacing
        {
            int spacing = deserialize_le<int>();
            SetTextLineSpacing(spacing);
            break;
        }
        case 382: // MeasureText
        {
            int length_text = deserialize_le<int>();
            std::vector<char> temp_text(length_text);
            for(int i = 0; i < length_text; i++) {
                temp_text[i] = deserialize_le<char>();
            }
            int fontSize = deserialize_le<int>();
            int result = MeasureText(temp_text.data(), fontSize);
            break;
        }
        case 383: // MeasureTextEx
        {
            Font font = deserialize_Font();
            int length_text = deserialize_le<int>();
            std::vector<char> temp_text(length_text);
            for(int i = 0; i < length_text; i++) {
                temp_text[i] = deserialize_le<char>();
            }
            float fontSize = deserialize_le<float>();
            float spacing = deserialize_le<float>();
            Vector2 result = MeasureTextEx(font, temp_text.data(), fontSize, spacing);
            break;
        }
        case 384: // GetGlyphIndex
        {
            Font font = deserialize_Font();
            int codepoint = deserialize_le<int>();
            int result = GetGlyphIndex(font, codepoint);
            break;
        }
        case 385: // GetGlyphInfo
        {
            Font font = deserialize_Font();
            int codepoint = deserialize_le<int>();
            GlyphInfo result = GetGlyphInfo(font, codepoint);
            break;
        }
        case 386: // GetGlyphAtlasRec
        {
            Font font = deserialize_Font();
            int codepoint = deserialize_le<int>();
            Rectangle result = GetGlyphAtlasRec(font, codepoint);
            break;
        }
        case 387: // UnloadUTF8
        {
            int length_text = deserialize_le<int>();
            std::vector<char> temp_text(length_text);
            for(int i = 0; i < length_text; i++) {
                temp_text[i] = deserialize_le<char>();
            }
            UnloadUTF8(temp_text.data());
            break;
        }
        case 388: // UnloadCodepoints
        {
            int length_codepoints = deserialize_le<int>();
            std::vector<int> temp_codepoints(length_codepoints);
            for(int i = 0; i < length_codepoints; i++) {
                temp_codepoints[i] = deserialize_le<int>();
            }
            UnloadCodepoints(temp_codepoints.data());
            break;
        }
        case 389: // GetCodepointCount
        {
            int length_text = deserialize_le<int>();
            std::vector<char> temp_text(length_text);
            for(int i = 0; i < length_text; i++) {
                temp_text[i] = deserialize_le<char>();
            }
            int result = GetCodepointCount(temp_text.data());
            break;
        }
        case 390: // GetCodepoint
        {
            int length_text = deserialize_le<int>();
            std::vector<char> temp_text(length_text);
            for(int i = 0; i < length_text; i++) {
                temp_text[i] = deserialize_le<char>();
            }
            int length_codepointSize = deserialize_le<int>();
            std::vector<int> temp_codepointSize(length_codepointSize);
            for(int i = 0; i < length_codepointSize; i++) {
                temp_codepointSize[i] = deserialize_le<int>();
            }
            int result = GetCodepoint(temp_text.data(), temp_codepointSize.data());
            break;
        }
        case 391: // GetCodepointNext
        {
            int length_text = deserialize_le<int>();
            std::vector<char> temp_text(length_text);
            for(int i = 0; i < length_text; i++) {
                temp_text[i] = deserialize_le<char>();
            }
            int length_codepointSize = deserialize_le<int>();
            std::vector<int> temp_codepointSize(length_codepointSize);
            for(int i = 0; i < length_codepointSize; i++) {
                temp_codepointSize[i] = deserialize_le<int>();
            }
            int result = GetCodepointNext(temp_text.data(), temp_codepointSize.data());
            break;
        }
        case 392: // GetCodepointPrevious
        {
            int length_text = deserialize_le<int>();
            std::vector<char> temp_text(length_text);
            for(int i = 0; i < length_text; i++) {
                temp_text[i] = deserialize_le<char>();
            }
            int length_codepointSize = deserialize_le<int>();
            std::vector<int> temp_codepointSize(length_codepointSize);
            for(int i = 0; i < length_codepointSize; i++) {
                temp_codepointSize[i] = deserialize_le<int>();
            }
            int result = GetCodepointPrevious(temp_text.data(), temp_codepointSize.data());
            break;
        }
        case 393: // TextCopy
        {
            int length_dst = deserialize_le<int>();
            std::vector<char> temp_dst(length_dst);
            for(int i = 0; i < length_dst; i++) {
                temp_dst[i] = deserialize_le<char>();
            }
            int length_src = deserialize_le<int>();
            std::vector<char> temp_src(length_src);
            for(int i = 0; i < length_src; i++) {
                temp_src[i] = deserialize_le<char>();
            }
            int result = TextCopy(temp_dst.data(), temp_src.data());
            break;
        }
        case 394: // TextIsEqual
        {
            int length_text1 = deserialize_le<int>();
            std::vector<char> temp_text1(length_text1);
            for(int i = 0; i < length_text1; i++) {
                temp_text1[i] = deserialize_le<char>();
            }
            int length_text2 = deserialize_le<int>();
            std::vector<char> temp_text2(length_text2);
            for(int i = 0; i < length_text2; i++) {
                temp_text2[i] = deserialize_le<char>();
            }
            bool result = TextIsEqual(temp_text1.data(), temp_text2.data());
            break;
        }
        case 395: // TextLength
        {
            int length_text = deserialize_le<int>();
            std::vector<char> temp_text(length_text);
            for(int i = 0; i < length_text; i++) {
                temp_text[i] = deserialize_le<char>();
            }
            int result = TextLength(temp_text.data());
            break;
        }
        case 396: // TextAppend
        {
            int length_text = deserialize_le<int>();
            std::vector<char> temp_text(length_text);
            for(int i = 0; i < length_text; i++) {
                temp_text[i] = deserialize_le<char>();
            }
            int length_append = deserialize_le<int>();
            std::vector<char> temp_append(length_append);
            for(int i = 0; i < length_append; i++) {
                temp_append[i] = deserialize_le<char>();
            }
            int length_position = deserialize_le<int>();
            std::vector<int> temp_position(length_position);
            for(int i = 0; i < length_position; i++) {
                temp_position[i] = deserialize_le<int>();
            }
            TextAppend(temp_text.data(), temp_append.data(), temp_position.data());
            break;
        }
        case 397: // TextFindIndex
        {
            int length_text = deserialize_le<int>();
            std::vector<char> temp_text(length_text);
            for(int i = 0; i < length_text; i++) {
                temp_text[i] = deserialize_le<char>();
            }
            int length_find = deserialize_le<int>();
            std::vector<char> temp_find(length_find);
            for(int i = 0; i < length_find; i++) {
                temp_find[i] = deserialize_le<char>();
            }
            int result = TextFindIndex(temp_text.data(), temp_find.data());
            break;
        }
        case 398: // TextToInteger
        {
            int length_text = deserialize_le<int>();
            std::vector<char> temp_text(length_text);
            for(int i = 0; i < length_text; i++) {
                temp_text[i] = deserialize_le<char>();
            }
            int result = TextToInteger(temp_text.data());
            break;
        }
        case 399: // TextToFloat
        {
            int length_text = deserialize_le<int>();
            std::vector<char> temp_text(length_text);
            for(int i = 0; i < length_text; i++) {
                temp_text[i] = deserialize_le<char>();
            }
            float result = TextToFloat(temp_text.data());
            break;
        }
        case 400: // DrawLine3D
        {
            Vector3 startPos = deserialize_Vector3();
            Vector3 endPos = deserialize_Vector3();
            Color color = deserialize_Color();
            DrawLine3D(startPos, endPos, color);
            break;
        }
        case 401: // DrawPoint3D
        {
            Vector3 position = deserialize_Vector3();
            Color color = deserialize_Color();
            DrawPoint3D(position, color);
            break;
        }
        case 402: // DrawCircle3D
        {
            Vector3 center = deserialize_Vector3();
            float radius = deserialize_le<float>();
            Vector3 rotationAxis = deserialize_Vector3();
            float rotationAngle = deserialize_le<float>();
            Color color = deserialize_Color();
            DrawCircle3D(center, radius, rotationAxis, rotationAngle, color);
            break;
        }
        case 403: // DrawTriangle3D
        {
            Vector3 v1 = deserialize_Vector3();
            Vector3 v2 = deserialize_Vector3();
            Vector3 v3 = deserialize_Vector3();
            Color color = deserialize_Color();
            DrawTriangle3D(v1, v2, v3, color);
            break;
        }
        case 404: // DrawTriangleStrip3D
        {
            int length_points = deserialize_le<int>();
            std::vector<Vector3> temp_points(length_points);
            for(int i = 0; i < length_points; i++) {
                temp_points[i] = deserialize_Vector3();
            }
            int pointCount = deserialize_le<int>();
            Color color = deserialize_Color();
            DrawTriangleStrip3D(temp_points.data(), pointCount, color);
            break;
        }
        case 405: // DrawCube
        {
            Vector3 position = deserialize_Vector3();
            float width = deserialize_le<float>();
            float height = deserialize_le<float>();
            float length = deserialize_le<float>();
            Color color = deserialize_Color();
            DrawCube(position, width, height, length, color);
            break;
        }
        case 406: // DrawCubeV
        {
            Vector3 position = deserialize_Vector3();
            Vector3 size = deserialize_Vector3();
            Color color = deserialize_Color();
            DrawCubeV(position, size, color);
            break;
        }
        case 407: // DrawCubeWires
        {
            Vector3 position = deserialize_Vector3();
            float width = deserialize_le<float>();
            float height = deserialize_le<float>();
            float length = deserialize_le<float>();
            Color color = deserialize_Color();
            DrawCubeWires(position, width, height, length, color);
            break;
        }
        case 408: // DrawCubeWiresV
        {
            Vector3 position = deserialize_Vector3();
            Vector3 size = deserialize_Vector3();
            Color color = deserialize_Color();
            DrawCubeWiresV(position, size, color);
            break;
        }
        case 409: // DrawSphere
        {
            Vector3 centerPos = deserialize_Vector3();
            float radius = deserialize_le<float>();
            Color color = deserialize_Color();
            DrawSphere(centerPos, radius, color);
            break;
        }
        case 410: // DrawSphereEx
        {
            Vector3 centerPos = deserialize_Vector3();
            float radius = deserialize_le<float>();
            int rings = deserialize_le<int>();
            int slices = deserialize_le<int>();
            Color color = deserialize_Color();
            DrawSphereEx(centerPos, radius, rings, slices, color);
            break;
        }
        case 411: // DrawSphereWires
        {
            Vector3 centerPos = deserialize_Vector3();
            float radius = deserialize_le<float>();
            int rings = deserialize_le<int>();
            int slices = deserialize_le<int>();
            Color color = deserialize_Color();
            DrawSphereWires(centerPos, radius, rings, slices, color);
            break;
        }
        case 412: // DrawCylinder
        {
            Vector3 position = deserialize_Vector3();
            float radiusTop = deserialize_le<float>();
            float radiusBottom = deserialize_le<float>();
            float height = deserialize_le<float>();
            int slices = deserialize_le<int>();
            Color color = deserialize_Color();
            DrawCylinder(position, radiusTop, radiusBottom, height, slices, color);
            break;
        }
        case 413: // DrawCylinderEx
        {
            Vector3 startPos = deserialize_Vector3();
            Vector3 endPos = deserialize_Vector3();
            float startRadius = deserialize_le<float>();
            float endRadius = deserialize_le<float>();
            int sides = deserialize_le<int>();
            Color color = deserialize_Color();
            DrawCylinderEx(startPos, endPos, startRadius, endRadius, sides, color);
            break;
        }
        case 414: // DrawCylinderWires
        {
            Vector3 position = deserialize_Vector3();
            float radiusTop = deserialize_le<float>();
            float radiusBottom = deserialize_le<float>();
            float height = deserialize_le<float>();
            int slices = deserialize_le<int>();
            Color color = deserialize_Color();
            DrawCylinderWires(position, radiusTop, radiusBottom, height, slices, color);
            break;
        }
        case 415: // DrawCylinderWiresEx
        {
            Vector3 startPos = deserialize_Vector3();
            Vector3 endPos = deserialize_Vector3();
            float startRadius = deserialize_le<float>();
            float endRadius = deserialize_le<float>();
            int sides = deserialize_le<int>();
            Color color = deserialize_Color();
            DrawCylinderWiresEx(startPos, endPos, startRadius, endRadius, sides, color);
            break;
        }
        case 416: // DrawCapsule
        {
            Vector3 startPos = deserialize_Vector3();
            Vector3 endPos = deserialize_Vector3();
            float radius = deserialize_le<float>();
            int slices = deserialize_le<int>();
            int rings = deserialize_le<int>();
            Color color = deserialize_Color();
            DrawCapsule(startPos, endPos, radius, slices, rings, color);
            break;
        }
        case 417: // DrawCapsuleWires
        {
            Vector3 startPos = deserialize_Vector3();
            Vector3 endPos = deserialize_Vector3();
            float radius = deserialize_le<float>();
            int slices = deserialize_le<int>();
            int rings = deserialize_le<int>();
            Color color = deserialize_Color();
            DrawCapsuleWires(startPos, endPos, radius, slices, rings, color);
            break;
        }
        case 418: // DrawPlane
        {
            Vector3 centerPos = deserialize_Vector3();
            Vector2 size = deserialize_Vector2();
            Color color = deserialize_Color();
            DrawPlane(centerPos, size, color);
            break;
        }
        case 419: // DrawRay
        {
            Ray ray = deserialize_Ray();
            Color color = deserialize_Color();
            DrawRay(ray, color);
            break;
        }
        case 420: // DrawGrid
        {
            int slices = deserialize_le<int>();
            float spacing = deserialize_le<float>();
            DrawGrid(slices, spacing);
            break;
        }
        case 421: // LoadModel
        {
            int length_fileName = deserialize_le<int>();
            std::vector<char> temp_fileName(length_fileName);
            for(int i = 0; i < length_fileName; i++) {
                temp_fileName[i] = deserialize_le<char>();
            }
            Model result = LoadModel(temp_fileName.data());
            break;
        }
        case 422: // LoadModelFromMesh
        {
            Mesh mesh = deserialize_Mesh();
            Model result = LoadModelFromMesh(mesh);
            break;
        }
        case 423: // IsModelValid
        {
            Model model = deserialize_Model();
            bool result = IsModelValid(model);
            break;
        }
        case 424: // UnloadModel
        {
            Model model = deserialize_Model();
            UnloadModel(model);
            break;
        }
        case 425: // GetModelBoundingBox
        {
            Model model = deserialize_Model();
            BoundingBox result = GetModelBoundingBox(model);
            break;
        }
        case 426: // DrawModel
        {
            Model model = deserialize_Model();
            Vector3 position = deserialize_Vector3();
            float scale = deserialize_le<float>();
            Color tint = deserialize_Color();
            DrawModel(model, position, scale, tint);
            break;
        }
        case 427: // DrawModelEx
        {
            Model model = deserialize_Model();
            Vector3 position = deserialize_Vector3();
            Vector3 rotationAxis = deserialize_Vector3();
            float rotationAngle = deserialize_le<float>();
            Vector3 scale = deserialize_Vector3();
            Color tint = deserialize_Color();
            DrawModelEx(model, position, rotationAxis, rotationAngle, scale, tint);
            break;
        }
        case 428: // DrawModelWires
        {
            Model model = deserialize_Model();
            Vector3 position = deserialize_Vector3();
            float scale = deserialize_le<float>();
            Color tint = deserialize_Color();
            DrawModelWires(model, position, scale, tint);
            break;
        }
        case 429: // DrawModelWiresEx
        {
            Model model = deserialize_Model();
            Vector3 position = deserialize_Vector3();
            Vector3 rotationAxis = deserialize_Vector3();
            float rotationAngle = deserialize_le<float>();
            Vector3 scale = deserialize_Vector3();
            Color tint = deserialize_Color();
            DrawModelWiresEx(model, position, rotationAxis, rotationAngle, scale, tint);
            break;
        }
        case 430: // DrawModelPoints
        {
            Model model = deserialize_Model();
            Vector3 position = deserialize_Vector3();
            float scale = deserialize_le<float>();
            Color tint = deserialize_Color();
            DrawModelPoints(model, position, scale, tint);
            break;
        }
        case 431: // DrawModelPointsEx
        {
            Model model = deserialize_Model();
            Vector3 position = deserialize_Vector3();
            Vector3 rotationAxis = deserialize_Vector3();
            float rotationAngle = deserialize_le<float>();
            Vector3 scale = deserialize_Vector3();
            Color tint = deserialize_Color();
            DrawModelPointsEx(model, position, rotationAxis, rotationAngle, scale, tint);
            break;
        }
        case 432: // DrawBoundingBox
        {
            BoundingBox box = deserialize_BoundingBox();
            Color color = deserialize_Color();
            DrawBoundingBox(box, color);
            break;
        }
        case 433: // DrawBillboard
        {
            Camera camera = deserialize_le<Camera>();
            Texture2D texture = deserialize_le<Texture2D>();
            Vector3 position = deserialize_Vector3();
            float scale = deserialize_le<float>();
            Color tint = deserialize_Color();
            DrawBillboard(camera, texture, position, scale, tint);
            break;
        }
        case 434: // DrawBillboardRec
        {
            Camera camera = deserialize_le<Camera>();
            Texture2D texture = deserialize_le<Texture2D>();
            Rectangle source = deserialize_Rectangle();
            Vector3 position = deserialize_Vector3();
            Vector2 size = deserialize_Vector2();
            Color tint = deserialize_Color();
            DrawBillboardRec(camera, texture, source, position, size, tint);
            break;
        }
        case 435: // DrawBillboardPro
        {
            Camera camera = deserialize_le<Camera>();
            Texture2D texture = deserialize_le<Texture2D>();
            Rectangle source = deserialize_Rectangle();
            Vector3 position = deserialize_Vector3();
            Vector3 up = deserialize_Vector3();
            Vector2 size = deserialize_Vector2();
            Vector2 origin = deserialize_Vector2();
            float rotation = deserialize_le<float>();
            Color tint = deserialize_Color();
            DrawBillboardPro(camera, texture, source, position, up, size, origin, rotation, tint);
            break;
        }
        case 436: // UploadMesh
        {
            int length_mesh = deserialize_le<int>();
            std::vector<Mesh> temp_mesh(length_mesh);
            for(int i = 0; i < length_mesh; i++) {
                temp_mesh[i] = deserialize_Mesh();
            }
            bool dynamic = deserialize_le<bool>();
            UploadMesh(temp_mesh.data(), dynamic);
            break;
        }
        case 437: // UpdateMeshBuffer
        {
            Mesh mesh = deserialize_Mesh();
            int index = deserialize_le<int>();
            // Skipping data (type: const void*) - not deserializable
            int dataSize = deserialize_le<int>();
            int offset = deserialize_le<int>();
            UpdateMeshBuffer(mesh, index, nullptr, dataSize, offset);
            break;
        }
        case 438: // UnloadMesh
        {
            Mesh mesh = deserialize_Mesh();
            UnloadMesh(mesh);
            break;
        }
        case 439: // DrawMesh
        {
            Mesh mesh = deserialize_Mesh();
            Material material = deserialize_Material();
            Matrix transform = deserialize_Matrix();
            DrawMesh(mesh, material, transform);
            break;
        }
        case 440: // DrawMeshInstanced
        {
            Mesh mesh = deserialize_Mesh();
            Material material = deserialize_Material();
            int length_transforms = deserialize_le<int>();
            std::vector<Matrix> temp_transforms(length_transforms);
            for(int i = 0; i < length_transforms; i++) {
                temp_transforms[i] = deserialize_Matrix();
            }
            int instances = deserialize_le<int>();
            DrawMeshInstanced(mesh, material, temp_transforms.data(), instances);
            break;
        }
        case 441: // GetMeshBoundingBox
        {
            Mesh mesh = deserialize_Mesh();
            BoundingBox result = GetMeshBoundingBox(mesh);
            break;
        }
        case 442: // GenMeshTangents
        {
            int length_mesh = deserialize_le<int>();
            std::vector<Mesh> temp_mesh(length_mesh);
            for(int i = 0; i < length_mesh; i++) {
                temp_mesh[i] = deserialize_Mesh();
            }
            GenMeshTangents(temp_mesh.data());
            break;
        }
        case 443: // ExportMesh
        {
            Mesh mesh = deserialize_Mesh();
            int length_fileName = deserialize_le<int>();
            std::vector<char> temp_fileName(length_fileName);
            for(int i = 0; i < length_fileName; i++) {
                temp_fileName[i] = deserialize_le<char>();
            }
            bool result = ExportMesh(mesh, temp_fileName.data());
            break;
        }
        case 444: // ExportMeshAsCode
        {
            Mesh mesh = deserialize_Mesh();
            int length_fileName = deserialize_le<int>();
            std::vector<char> temp_fileName(length_fileName);
            for(int i = 0; i < length_fileName; i++) {
                temp_fileName[i] = deserialize_le<char>();
            }
            bool result = ExportMeshAsCode(mesh, temp_fileName.data());
            break;
        }
        case 445: // GenMeshPoly
        {
            int sides = deserialize_le<int>();
            float radius = deserialize_le<float>();
            Mesh result = GenMeshPoly(sides, radius);
            break;
        }
        case 446: // GenMeshPlane
        {
            float width = deserialize_le<float>();
            float length = deserialize_le<float>();
            int resX = deserialize_le<int>();
            int resZ = deserialize_le<int>();
            Mesh result = GenMeshPlane(width, length, resX, resZ);
            break;
        }
        case 447: // GenMeshCube
        {
            float width = deserialize_le<float>();
            float height = deserialize_le<float>();
            float length = deserialize_le<float>();
            Mesh result = GenMeshCube(width, height, length);
            break;
        }
        case 448: // GenMeshSphere
        {
            float radius = deserialize_le<float>();
            int rings = deserialize_le<int>();
            int slices = deserialize_le<int>();
            Mesh result = GenMeshSphere(radius, rings, slices);
            break;
        }
        case 449: // GenMeshHemiSphere
        {
            float radius = deserialize_le<float>();
            int rings = deserialize_le<int>();
            int slices = deserialize_le<int>();
            Mesh result = GenMeshHemiSphere(radius, rings, slices);
            break;
        }
        case 450: // GenMeshCylinder
        {
            float radius = deserialize_le<float>();
            float height = deserialize_le<float>();
            int slices = deserialize_le<int>();
            Mesh result = GenMeshCylinder(radius, height, slices);
            break;
        }
        case 451: // GenMeshCone
        {
            float radius = deserialize_le<float>();
            float height = deserialize_le<float>();
            int slices = deserialize_le<int>();
            Mesh result = GenMeshCone(radius, height, slices);
            break;
        }
        case 452: // GenMeshTorus
        {
            float radius = deserialize_le<float>();
            float size = deserialize_le<float>();
            int radSeg = deserialize_le<int>();
            int sides = deserialize_le<int>();
            Mesh result = GenMeshTorus(radius, size, radSeg, sides);
            break;
        }
        case 453: // GenMeshKnot
        {
            float radius = deserialize_le<float>();
            float size = deserialize_le<float>();
            int radSeg = deserialize_le<int>();
            int sides = deserialize_le<int>();
            Mesh result = GenMeshKnot(radius, size, radSeg, sides);
            break;
        }
        case 454: // GenMeshHeightmap
        {
            Image heightmap = deserialize_Image();
            Vector3 size = deserialize_Vector3();
            Mesh result = GenMeshHeightmap(heightmap, size);
            break;
        }
        case 455: // GenMeshCubicmap
        {
            Image cubicmap = deserialize_Image();
            Vector3 cubeSize = deserialize_Vector3();
            Mesh result = GenMeshCubicmap(cubicmap, cubeSize);
            break;
        }
        case 456: // LoadMaterialDefault
        {
            Material result = LoadMaterialDefault();
            break;
        }
        case 457: // IsMaterialValid
        {
            Material material = deserialize_Material();
            bool result = IsMaterialValid(material);
            break;
        }
        case 458: // UnloadMaterial
        {
            Material material = deserialize_Material();
            UnloadMaterial(material);
            break;
        }
        case 459: // SetMaterialTexture
        {
            int length_material = deserialize_le<int>();
            std::vector<Material> temp_material(length_material);
            for(int i = 0; i < length_material; i++) {
                temp_material[i] = deserialize_Material();
            }
            int mapType = deserialize_le<int>();
            Texture2D texture = deserialize_le<Texture2D>();
            SetMaterialTexture(temp_material.data(), mapType, texture);
            break;
        }
        case 460: // SetModelMeshMaterial
        {
            int length_model = deserialize_le<int>();
            std::vector<Model> temp_model(length_model);
            for(int i = 0; i < length_model; i++) {
                temp_model[i] = deserialize_Model();
            }
            int meshId = deserialize_le<int>();
            int materialId = deserialize_le<int>();
            SetModelMeshMaterial(temp_model.data(), meshId, materialId);
            break;
        }
        case 461: // UpdateModelAnimation
        {
            Model model = deserialize_Model();
            ModelAnimation anim = deserialize_ModelAnimation();
            int frame = deserialize_le<int>();
            UpdateModelAnimation(model, anim, frame);
            break;
        }
        case 462: // UpdateModelAnimationBones
        {
            Model model = deserialize_Model();
            ModelAnimation anim = deserialize_ModelAnimation();
            int frame = deserialize_le<int>();
            UpdateModelAnimationBones(model, anim, frame);
            break;
        }
        case 463: // UnloadModelAnimation
        {
            ModelAnimation anim = deserialize_ModelAnimation();
            UnloadModelAnimation(anim);
            break;
        }
        case 464: // UnloadModelAnimations
        {
            int length_animations = deserialize_le<int>();
            std::vector<ModelAnimation> temp_animations(length_animations);
            for(int i = 0; i < length_animations; i++) {
                temp_animations[i] = deserialize_ModelAnimation();
            }
            int animCount = deserialize_le<int>();
            UnloadModelAnimations(temp_animations.data(), animCount);
            break;
        }
        case 465: // IsModelAnimationValid
        {
            Model model = deserialize_Model();
            ModelAnimation anim = deserialize_ModelAnimation();
            bool result = IsModelAnimationValid(model, anim);
            break;
        }
        case 466: // CheckCollisionSpheres
        {
            Vector3 center1 = deserialize_Vector3();
            float radius1 = deserialize_le<float>();
            Vector3 center2 = deserialize_Vector3();
            float radius2 = deserialize_le<float>();
            bool result = CheckCollisionSpheres(center1, radius1, center2, radius2);
            break;
        }
        case 467: // CheckCollisionBoxes
        {
            BoundingBox box1 = deserialize_BoundingBox();
            BoundingBox box2 = deserialize_BoundingBox();
            bool result = CheckCollisionBoxes(box1, box2);
            break;
        }
        case 468: // CheckCollisionBoxSphere
        {
            BoundingBox box = deserialize_BoundingBox();
            Vector3 center = deserialize_Vector3();
            float radius = deserialize_le<float>();
            bool result = CheckCollisionBoxSphere(box, center, radius);
            break;
        }
        case 469: // GetRayCollisionSphere
        {
            Ray ray = deserialize_Ray();
            Vector3 center = deserialize_Vector3();
            float radius = deserialize_le<float>();
            RayCollision result = GetRayCollisionSphere(ray, center, radius);
            break;
        }
        case 470: // GetRayCollisionBox
        {
            Ray ray = deserialize_Ray();
            BoundingBox box = deserialize_BoundingBox();
            RayCollision result = GetRayCollisionBox(ray, box);
            break;
        }
        case 471: // GetRayCollisionMesh
        {
            Ray ray = deserialize_Ray();
            Mesh mesh = deserialize_Mesh();
            Matrix transform = deserialize_Matrix();
            RayCollision result = GetRayCollisionMesh(ray, mesh, transform);
            break;
        }
        case 472: // GetRayCollisionTriangle
        {
            Ray ray = deserialize_Ray();
            Vector3 p1 = deserialize_Vector3();
            Vector3 p2 = deserialize_Vector3();
            Vector3 p3 = deserialize_Vector3();
            RayCollision result = GetRayCollisionTriangle(ray, p1, p2, p3);
            break;
        }
        case 473: // GetRayCollisionQuad
        {
            Ray ray = deserialize_Ray();
            Vector3 p1 = deserialize_Vector3();
            Vector3 p2 = deserialize_Vector3();
            Vector3 p3 = deserialize_Vector3();
            Vector3 p4 = deserialize_Vector3();
            RayCollision result = GetRayCollisionQuad(ray, p1, p2, p3, p4);
            break;
        }
        case 474: // InitAudioDevice
        {
            InitAudioDevice();
            break;
        }
        case 475: // CloseAudioDevice
        {
            CloseAudioDevice();
            break;
        }
        case 476: // IsAudioDeviceReady
        {
            bool result = IsAudioDeviceReady();
            break;
        }
        case 477: // SetMasterVolume
        {
            float volume = deserialize_le<float>();
            SetMasterVolume(volume);
            break;
        }
        case 478: // GetMasterVolume
        {
            float result = GetMasterVolume();
            break;
        }
        case 479: // LoadWave
        {
            int length_fileName = deserialize_le<int>();
            std::vector<char> temp_fileName(length_fileName);
            for(int i = 0; i < length_fileName; i++) {
                temp_fileName[i] = deserialize_le<char>();
            }
            Wave result = LoadWave(temp_fileName.data());
            break;
        }
        case 480: // LoadWaveFromMemory
        {
            int length_fileType = deserialize_le<int>();
            std::vector<char> temp_fileType(length_fileType);
            for(int i = 0; i < length_fileType; i++) {
                temp_fileType[i] = deserialize_le<char>();
            }
            int length_fileData = deserialize_le<int>();
            std::vector<unsigned char> temp_fileData(length_fileData);
            for(int i = 0; i < length_fileData; i++) {
                temp_fileData[i] = deserialize_le<unsigned char>();
            }
            int dataSize = deserialize_le<int>();
            Wave result = LoadWaveFromMemory(temp_fileType.data(), temp_fileData.data(), dataSize);
            break;
        }
        case 481: // IsWaveValid
        {
            Wave wave = deserialize_Wave();
            bool result = IsWaveValid(wave);
            break;
        }
        case 482: // LoadSound
        {
            int length_fileName = deserialize_le<int>();
            std::vector<char> temp_fileName(length_fileName);
            for(int i = 0; i < length_fileName; i++) {
                temp_fileName[i] = deserialize_le<char>();
            }
            Sound result = LoadSound(temp_fileName.data());
            break;
        }
        case 483: // LoadSoundFromWave
        {
            Wave wave = deserialize_Wave();
            Sound result = LoadSoundFromWave(wave);
            break;
        }
        case 484: // LoadSoundAlias
        {
            Sound source = deserialize_Sound();
            Sound result = LoadSoundAlias(source);
            break;
        }
        case 485: // IsSoundValid
        {
            Sound sound = deserialize_Sound();
            bool result = IsSoundValid(sound);
            break;
        }
        case 486: // UpdateSound
        {
            Sound sound = deserialize_Sound();
            // Skipping data (type: const void*) - not deserializable
            int sampleCount = deserialize_le<int>();
            UpdateSound(sound, nullptr, sampleCount);
            break;
        }
        case 487: // UnloadWave
        {
            Wave wave = deserialize_Wave();
            UnloadWave(wave);
            break;
        }
        case 488: // UnloadSound
        {
            Sound sound = deserialize_Sound();
            UnloadSound(sound);
            break;
        }
        case 489: // UnloadSoundAlias
        {
            Sound alias = deserialize_Sound();
            UnloadSoundAlias(alias);
            break;
        }
        case 490: // ExportWave
        {
            Wave wave = deserialize_Wave();
            int length_fileName = deserialize_le<int>();
            std::vector<char> temp_fileName(length_fileName);
            for(int i = 0; i < length_fileName; i++) {
                temp_fileName[i] = deserialize_le<char>();
            }
            bool result = ExportWave(wave, temp_fileName.data());
            break;
        }
        case 491: // ExportWaveAsCode
        {
            Wave wave = deserialize_Wave();
            int length_fileName = deserialize_le<int>();
            std::vector<char> temp_fileName(length_fileName);
            for(int i = 0; i < length_fileName; i++) {
                temp_fileName[i] = deserialize_le<char>();
            }
            bool result = ExportWaveAsCode(wave, temp_fileName.data());
            break;
        }
        case 492: // PlaySound
        {
            Sound sound = deserialize_Sound();
            PlaySound(sound);
            break;
        }
        case 493: // StopSound
        {
            Sound sound = deserialize_Sound();
            StopSound(sound);
            break;
        }
        case 494: // PauseSound
        {
            Sound sound = deserialize_Sound();
            PauseSound(sound);
            break;
        }
        case 495: // ResumeSound
        {
            Sound sound = deserialize_Sound();
            ResumeSound(sound);
            break;
        }
        case 496: // IsSoundPlaying
        {
            Sound sound = deserialize_Sound();
            bool result = IsSoundPlaying(sound);
            break;
        }
        case 497: // SetSoundVolume
        {
            Sound sound = deserialize_Sound();
            float volume = deserialize_le<float>();
            SetSoundVolume(sound, volume);
            break;
        }
        case 498: // SetSoundPitch
        {
            Sound sound = deserialize_Sound();
            float pitch = deserialize_le<float>();
            SetSoundPitch(sound, pitch);
            break;
        }
        case 499: // SetSoundPan
        {
            Sound sound = deserialize_Sound();
            float pan = deserialize_le<float>();
            SetSoundPan(sound, pan);
            break;
        }
        case 500: // WaveCopy
        {
            Wave wave = deserialize_Wave();
            Wave result = WaveCopy(wave);
            break;
        }
        case 501: // WaveCrop
        {
            int length_wave = deserialize_le<int>();
            std::vector<Wave> temp_wave(length_wave);
            for(int i = 0; i < length_wave; i++) {
                temp_wave[i] = deserialize_Wave();
            }
            int initFrame = deserialize_le<int>();
            int finalFrame = deserialize_le<int>();
            WaveCrop(temp_wave.data(), initFrame, finalFrame);
            break;
        }
        case 502: // WaveFormat
        {
            int length_wave = deserialize_le<int>();
            std::vector<Wave> temp_wave(length_wave);
            for(int i = 0; i < length_wave; i++) {
                temp_wave[i] = deserialize_Wave();
            }
            int sampleRate = deserialize_le<int>();
            int sampleSize = deserialize_le<int>();
            int channels = deserialize_le<int>();
            WaveFormat(temp_wave.data(), sampleRate, sampleSize, channels);
            break;
        }
        case 503: // UnloadWaveSamples
        {
            int length_samples = deserialize_le<int>();
            std::vector<float> temp_samples(length_samples);
            for(int i = 0; i < length_samples; i++) {
                temp_samples[i] = deserialize_le<float>();
            }
            UnloadWaveSamples(temp_samples.data());
            break;
        }
        case 504: // LoadMusicStream
        {
            int length_fileName = deserialize_le<int>();
            std::vector<char> temp_fileName(length_fileName);
            for(int i = 0; i < length_fileName; i++) {
                temp_fileName[i] = deserialize_le<char>();
            }
            Music result = LoadMusicStream(temp_fileName.data());
            break;
        }
        case 505: // LoadMusicStreamFromMemory
        {
            int length_fileType = deserialize_le<int>();
            std::vector<char> temp_fileType(length_fileType);
            for(int i = 0; i < length_fileType; i++) {
                temp_fileType[i] = deserialize_le<char>();
            }
            int length_data = deserialize_le<int>();
            std::vector<unsigned char> temp_data(length_data);
            for(int i = 0; i < length_data; i++) {
                temp_data[i] = deserialize_le<unsigned char>();
            }
            int dataSize = deserialize_le<int>();
            Music result = LoadMusicStreamFromMemory(temp_fileType.data(), temp_data.data(), dataSize);
            break;
        }
        case 506: // IsMusicValid
        {
            Music music = deserialize_Music();
            bool result = IsMusicValid(music);
            break;
        }
        case 507: // UnloadMusicStream
        {
            Music music = deserialize_Music();
            UnloadMusicStream(music);
            break;
        }
        case 508: // PlayMusicStream
        {
            Music music = deserialize_Music();
            PlayMusicStream(music);
            break;
        }
        case 509: // IsMusicStreamPlaying
        {
            Music music = deserialize_Music();
            bool result = IsMusicStreamPlaying(music);
            break;
        }
        case 510: // UpdateMusicStream
        {
            Music music = deserialize_Music();
            UpdateMusicStream(music);
            break;
        }
        case 511: // StopMusicStream
        {
            Music music = deserialize_Music();
            StopMusicStream(music);
            break;
        }
        case 512: // PauseMusicStream
        {
            Music music = deserialize_Music();
            PauseMusicStream(music);
            break;
        }
        case 513: // ResumeMusicStream
        {
            Music music = deserialize_Music();
            ResumeMusicStream(music);
            break;
        }
        case 514: // SeekMusicStream
        {
            Music music = deserialize_Music();
            float position = deserialize_le<float>();
            SeekMusicStream(music, position);
            break;
        }
        case 515: // SetMusicVolume
        {
            Music music = deserialize_Music();
            float volume = deserialize_le<float>();
            SetMusicVolume(music, volume);
            break;
        }
        case 516: // SetMusicPitch
        {
            Music music = deserialize_Music();
            float pitch = deserialize_le<float>();
            SetMusicPitch(music, pitch);
            break;
        }
        case 517: // SetMusicPan
        {
            Music music = deserialize_Music();
            float pan = deserialize_le<float>();
            SetMusicPan(music, pan);
            break;
        }
        case 518: // GetMusicTimeLength
        {
            Music music = deserialize_Music();
            float result = GetMusicTimeLength(music);
            break;
        }
        case 519: // GetMusicTimePlayed
        {
            Music music = deserialize_Music();
            float result = GetMusicTimePlayed(music);
            break;
        }
        case 520: // LoadAudioStream
        {
            unsigned int sampleRate = deserialize_le<unsigned int>();
            unsigned int sampleSize = deserialize_le<unsigned int>();
            unsigned int channels = deserialize_le<unsigned int>();
            AudioStream result = LoadAudioStream(sampleRate, sampleSize, channels);
            break;
        }
        case 521: // IsAudioStreamValid
        {
            AudioStream stream = deserialize_AudioStream();
            bool result = IsAudioStreamValid(stream);
            break;
        }
        case 522: // UnloadAudioStream
        {
            AudioStream stream = deserialize_AudioStream();
            UnloadAudioStream(stream);
            break;
        }
        case 523: // UpdateAudioStream
        {
            AudioStream stream = deserialize_AudioStream();
            // Skipping data (type: const void*) - not deserializable
            int frameCount = deserialize_le<int>();
            UpdateAudioStream(stream, nullptr, frameCount);
            break;
        }
        case 524: // IsAudioStreamProcessed
        {
            AudioStream stream = deserialize_AudioStream();
            bool result = IsAudioStreamProcessed(stream);
            break;
        }
        case 525: // PlayAudioStream
        {
            AudioStream stream = deserialize_AudioStream();
            PlayAudioStream(stream);
            break;
        }
        case 526: // PauseAudioStream
        {
            AudioStream stream = deserialize_AudioStream();
            PauseAudioStream(stream);
            break;
        }
        case 527: // ResumeAudioStream
        {
            AudioStream stream = deserialize_AudioStream();
            ResumeAudioStream(stream);
            break;
        }
        case 528: // IsAudioStreamPlaying
        {
            AudioStream stream = deserialize_AudioStream();
            bool result = IsAudioStreamPlaying(stream);
            break;
        }
        case 529: // StopAudioStream
        {
            AudioStream stream = deserialize_AudioStream();
            StopAudioStream(stream);
            break;
        }
        case 530: // SetAudioStreamVolume
        {
            AudioStream stream = deserialize_AudioStream();
            float volume = deserialize_le<float>();
            SetAudioStreamVolume(stream, volume);
            break;
        }
        case 531: // SetAudioStreamPitch
        {
            AudioStream stream = deserialize_AudioStream();
            float pitch = deserialize_le<float>();
            SetAudioStreamPitch(stream, pitch);
            break;
        }
        case 532: // SetAudioStreamPan
        {
            AudioStream stream = deserialize_AudioStream();
            float pan = deserialize_le<float>();
            SetAudioStreamPan(stream, pan);
            break;
        }
        case 533: // SetAudioStreamBufferSizeDefault
        {
            int size = deserialize_le<int>();
            SetAudioStreamBufferSizeDefault(size);
            break;
        }
        case 534: // SetAudioStreamCallback
        {
            AudioStream stream = deserialize_AudioStream();
            AudioCallback callback = deserialize_le<AudioCallback>();
            SetAudioStreamCallback(stream, callback);
            break;
        }
        case 535: // AttachAudioStreamProcessor
        {
            AudioStream stream = deserialize_AudioStream();
            AudioCallback processor = deserialize_le<AudioCallback>();
            AttachAudioStreamProcessor(stream, processor);
            break;
        }
        case 536: // DetachAudioStreamProcessor
        {
            AudioStream stream = deserialize_AudioStream();
            AudioCallback processor = deserialize_le<AudioCallback>();
            DetachAudioStreamProcessor(stream, processor);
            break;
        }
        case 537: // AttachAudioMixedProcessor
        {
            AudioCallback processor = deserialize_le<AudioCallback>();
            AttachAudioMixedProcessor(processor);
            break;
        }
        case 538: // DetachAudioMixedProcessor
        {
            AudioCallback processor = deserialize_le<AudioCallback>();
            DetachAudioMixedProcessor(processor);
            break;
        }
        default:
            std::cout << "Unknown function ID: " << id << std::endl;
            break;
    }
}
