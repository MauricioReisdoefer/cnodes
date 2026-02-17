#include <stdio.h>
#include <stdlib.h>

#include "rigidbody.h"
#include "vector2.h"

CNodes_Rigidbody2D_Index CNodes_Rigidbody2D_Create()
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

    CNodes_Rigidbody2D *t = &g_rigidbodys[index];

    t->velocity = Vector2_Zero();
    t->force_accumulator = Vector2_Zero();
    t->gravity_scale = 1.0f;
    t->use_gravity = 1;
    t->linear_drag = 0.0f;
    t->mass = 1.0f;
    t->inverse_mass = 1.0f;

    t->internal_index = index;

    t->base.active = 1;
    t->base.owner = NULL;
    t->base.type = COMPONENT_RIGIDBODY;
    t->base.destroy = CNodes_Rigidbody2D_Destroy;
    t->base.update = CNodes_Rigidbody2D_Update;

    return index;
}

void CNodes_Rigidbody2D_Destroy(Component *self)
{
    CNodes_Rigidbody2D *rb = (CNodes_Rigidbody2D *)self;
    rb->base.active = 0;
    int index = rb->internal_index;

    if (index < 0 || index >= MAX_COMPONENTS)
        return;

    if (rigidbody_free_count < MAX_COMPONENTS)
    {
        rigidbody_free_list[rigidbody_free_count++] = index;
    }
}

void CNodes_Rigidbody2D_Update(Component *self, float dt)
{
}