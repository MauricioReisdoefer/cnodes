#include <stdio.h>
#include <stdlib.h>

#include "rigidbody.h"
#include "vector2.h"

int Rigidbody2D_Create()
{
    int index;

    if (rigidbody_free_count > 0)
    {
        index = rigidbody_free_list[--rigidbody_free_count];
    }
    else
    {
        if (g_rigidbody_count >= MAX_COMPONENTS)
            return -1;

        index = g_rigidbody_count++;
    }

    Rigidbody2D *t = &g_rigidbodys[index];

    t->velocity = Vector2_Zero();
    t->force_accumulator = (Vector2){1.0f, 1.0f};
    t->gravity_scale = 1.0f;
    t->use_gravity = 1;
    t->linear_drag = 0.0f;
    t->mass = 1.0f;

    return index;
}

void Rigidbody2D_Destroy(int index)
{
    if (index < 0 || index >= MAX_COMPONENTS)
        return;

    if (rigidbody_free_count < MAX_COMPONENTS)
    {
        rigidbody_free_list[rigidbody_free_count++] = index;
    }
}