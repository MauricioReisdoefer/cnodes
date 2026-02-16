#pragma once

#include "vector2.h"

#define MAX_COMPONENTS 16894

typedef struct Transform
{
    Vector2 position;
    Vector2 scale;
    Vector2 rotation;
} Transform;

extern Transform g_transforms[MAX_COMPONENTS];

extern int g_transform_count;

extern int transform_free_list[MAX_COMPONENTS];
extern int transform_free_count;

int Transform_Create();
void Transform_Destroy(int index);