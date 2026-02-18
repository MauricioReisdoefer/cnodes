#pragma once

#include "vector2.h"
#include "component.h"

#define MAX_COMPONENTS 16894

typedef int CN_Rigidbody2D_Index;

typedef struct CN_Rigidbody2D
{
    Component base;            // 5 bytes
    Vector2 velocity;          // 8 bytes
    Vector2 force_accumulator; // 8 bytes

    float gravity_scale; // 4 bytes

    CN_Bool use_gravity;                 // 1 byte
    CN_Rigidbody2D_Index internal_index; // 2 bytes

    float mass;         // 4 bytes
    float inverse_mass; // 4 bytes
    float linear_drag;  // 4 bytes
} CN_Rigidbody2D;

extern CN_Rigidbody2D g_rigidbodys[MAX_COMPONENTS];

extern int g_rigidbody_count;

extern int rigidbody_free_list[MAX_COMPONENTS];
extern int rigidbody_free_count;

CN_Rigidbody2D_Index CN_Rigidbody2D_Create();
void CN_Rigidbody2D_Destroy(CN_Rigidbody2D_Index index);
void CN_Rigidbody2D_Update(Component *self, float dt);

void CN_Rigidbody2D_AddForce(CN_Rigidbody2D_Index index, Vector2 force);
void CN_Rigidbody2D_SetMass(CN_Rigidbody2D_Index index, float mass);
void CN_Rigidbody2D_SetVelocity(CN_Rigidbody2D_Index index, Vector2 velocity);
Vector2 CN_Rigidbody2D_GetVelocity(CN_Rigidbody2D_Index index);
void CN_Rigidbody2D_SetGravityScale(CN_Rigidbody2D_Index index, float scale);
void CN_Rigidbody2D_UseGravity(CN_Rigidbody2D_Index index, int use);
void CN_Rigidbody2D_SetLinearDrag(CN_Rigidbody2D_Index index, float drag);

CN_Rigidbody2D *CN_INTERN_Rigidbody2D_Get(CN_Rigidbody2D_Index index);