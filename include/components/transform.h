#pragma once

#include "vector2.h"

#define MAX_COMPONENTS 16894

typedef int CN_Transform_Index;

typedef struct Transform
{
    Vector2 position; // 8 bytes
    Vector2 scale;    // 8 bytes
    Vector2 rotation; // 8 bytes
} Transform;

extern Transform g_transforms[MAX_COMPONENTS];

extern int g_transform_count;

extern int transform_free_list[MAX_COMPONENTS];
extern int transform_free_count;

CN_Transform_Index CN_Transform_Create();
void CN_Transform_Destroy(CN_Transform_Index index);

Transform *CN_Transform_Get(CN_Transform_Index index);