#ifndef RAYLIB_DESERIALIZATION_H
#define RAYLIB_DESERIALIZATION_H

#include <vector>
#include <cstdint>
#include <cstring>
#include "raylib.h"
#include "trace_internal.h"

Vector2 deserialize_Vector2();
Vector3 deserialize_Vector3();
Vector4 deserialize_Vector4();
Matrix deserialize_Matrix();
Color deserialize_Color();
Rectangle deserialize_Rectangle();
Image deserialize_Image();
Texture deserialize_Texture();
RenderTexture deserialize_RenderTexture();
NPatchInfo deserialize_NPatchInfo();
GlyphInfo deserialize_GlyphInfo();
Font deserialize_Font();
Camera3D deserialize_Camera3D();
Camera2D deserialize_Camera2D();
Mesh deserialize_Mesh();
Shader deserialize_Shader();
MaterialMap deserialize_MaterialMap();
Material deserialize_Material();
Transform deserialize_Transform();
BoneInfo deserialize_BoneInfo();
Model deserialize_Model();
ModelAnimation deserialize_ModelAnimation();
Ray deserialize_Ray();
RayCollision deserialize_RayCollision();
BoundingBox deserialize_BoundingBox();
Wave deserialize_Wave();
AudioStream deserialize_AudioStream();
Sound deserialize_Sound();
Music deserialize_Music();
VrDeviceInfo deserialize_VrDeviceInfo();
VrStereoConfig deserialize_VrStereoConfig();
FilePathList deserialize_FilePathList();
AutomationEvent deserialize_AutomationEvent();
AutomationEventList deserialize_AutomationEventList();
void dispatch_raylib_function_call(uint64_t id, const uint8_t* buffer, uint64_t buffer_size);

#endif // RAYLIB_DESERIALIZATION_H
