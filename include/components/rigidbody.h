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

    CNodes_Bool use_gravity;
    CNodes_Rigidbody2D_Index internal_index;

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
void CNodes_Rigidbody2D_Update(Component *self, float dt);

void CNodes_Rigidbody2D_AddForce(CNodes_Rigidbody2D_Index index, Vector2 force);
void CNodes_Rigidbody2D_SetMass(CNodes_Rigidbody2D_Index index, float mass);
void CNodes_Rigidbody2D_SetVelocity(CNodes_Rigidbody2D_Index index, Vector2 velocity);
Vector2 CNodes_Rigidbody2D_GetVelocity(CNodes_Rigidbody2D_Index index);
void CNodes_Rigidbody2D_SetGravityScale(CNodes_Rigidbody2D_Index index, float scale);
void CNodes_Rigidbody2D_UseGravity(CNodes_Rigidbody2D_Index index, int use);
void CNodes_Rigidbody2D_SetLinearDrag(CNodes_Rigidbody2D_Index index, float drag);

CNodes_Rigidbody2D *CNodes_INTERN_Rigidbody2D_Get(CNodes_Rigidbody2D_Index index);