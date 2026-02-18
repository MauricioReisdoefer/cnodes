#pragma once

#include "math/vector2.h"

#define MAX_COMPONENTS 16894

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

Transform *CN_Transform_Get(int index);

int CN_Transform_Create();
void CN_Transform_Destroy(int index);