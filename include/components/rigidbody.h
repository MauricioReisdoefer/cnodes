#pragma once

#include "vector2.h"

#define MAX_COMPONENTS 16894

typedef struct Rigidbody2D
{
    Vector2 speed;
    Vector2 force_accumulator;

    float gravity_scale;
    int use_gravity;

    float mass;
    float linear_drag;
} Rigidbody2D;

extern Rigidbody2D g_rigidbodys[MAX_COMPONENTS];

extern int g_rigidbody_count;

extern int rigidbody_free_list[MAX_COMPONENTS];
extern int rigidbody_free_count;

int Rigidbody2D_Create();
void Rigidbody2D_Destroy(int index);
void Rigidbody2D_AddForce(int index);