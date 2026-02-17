#pragma once

#include "vector2.h"
#include "component.h"

#define MAX_COMPONENTS 16894

typedef int CNodes_Rigidbody2D_Index;

typedef struct CNodes_Rigidbody2D
{
    Component base;
    Vector2 velocity;
    Vector2 force_accumulator;

    float gravity_scale;
    int use_gravity;

    int internal_index;

    float mass;
    float inverse_mass;
    float linear_drag;
} CNodes_Rigidbody2D;

extern CNodes_Rigidbody2D g_rigidbodys[MAX_COMPONENTS];

extern int g_rigidbody_count;

extern int rigidbody_free_list[MAX_COMPONENTS];
extern int rigidbody_free_count;

CNodes_Rigidbody2D_Index CNodes_Rigidbody2D_Create();
void CNodes_Rigidbody2D_Destroy(CNodes_Rigidbody2D_Index index);
void CNodes_Rigidbody2D_AddForce(CNodes_Rigidbody2D_Index index);