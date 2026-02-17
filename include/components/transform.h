#pragma once

#include "vector2.h"

#define MAX_COMPONENTS 16894

typedef int CNodes_Transform_Index;

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

CNodes_Transform_Index CNodes_Transform_Create();
void CNodes_Transform_Destroy(CNodes_Transform_Index index);

Transform *CNodes_Transform_Get(CNodes_Transform_Index index);