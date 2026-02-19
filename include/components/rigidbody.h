#pragma once

#include "math/vector2.h"
#include "components/component.h"

#define MAX_COMPONENTS 16894

typedef struct CN_Rigidbody2D
{
    Component base;            // 5 bytes
    Vector2 velocity;          // 8 bytes
    Vector2 force_accumulator; // 8 bytes

    float gravity_scale; // 4 bytes

    CN_Bool use_gravity; // 1 byte
    int internal_index;  // 2 bytes

    float mass;         // 4 bytes
    float inverse_mass; // 4 bytes
    float linear_drag;  // 4 bytes
} CN_Rigidbody2D;

extern CN_Rigidbody2D g_rigidbodys[MAX_COMPONENTS];

extern int g_rigidbody_count;

extern int rigidbody_free_list[MAX_COMPONENTS];
extern int rigidbody_free_count;

void CN_Rigidbody2D_Init(void);
int CN_Rigidbody2D_Create();
void CN_Rigidbody2D_Destroy(int index);
void CN_Rigidbody2D_Update(Component *self, float dt);

void CN_Rigidbody2D_AddForce(int index, Vector2 force);
void CN_Rigidbody2D_SetMass(int index, float mass);
void CN_Rigidbody2D_SetVelocity(int index, Vector2 velocity);
Vector2 CN_Rigidbody2D_GetVelocity(int index);
void CN_Rigidbody2D_SetGravityScale(int index, float scale);
void CN_Rigidbody2D_UseGravity(int index, CN_Bool use);
void CN_Rigidbody2D_SetLinearDrag(int index, float drag);

CN_Rigidbody2D *CN_INTERN_Rigidbody2D_Get(int index);