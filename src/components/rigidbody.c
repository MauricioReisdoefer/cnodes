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

void CNodes_Rigidbody2D_AddForce(CNodes_Rigidbody2D_Index index, Vector2 force)
{
    CNodes_Rigidbody2D *rb = CNodes_INTERN_Rigidbody2D_Get(index);
    if (rb == NULL)
        return;
    rb->force_accumulator = Vector2_Add(rb->force_accumulator, force);
}
void CNodes_Rigidbody2D_SetMass(CNodes_Rigidbody2D_Index index, float mass)
{
    CNodes_Rigidbody2D *rb = CNodes_INTERN_Rigidbody2D_Get(index);
    if (rb == NULL)
        return;
    rb->mass = mass;
    rb->inverse_mass = 1.0f / mass;
}
void CNodes_Rigidbody2D_SetVelocity(CNodes_Rigidbody2D_Index index, Vector2 velocity)
{
    CNodes_Rigidbody2D *rb = CNodes_INTERN_Rigidbody2D_Get(index);
    if (rb == NULL)
        return;

    rb->velocity = velocity;
}
Vector2 CNodes_Rigidbody2D_GetVelocity(CNodes_Rigidbody2D_Index index)
{
    CNodes_Rigidbody2D *rb = CNodes_INTERN_Rigidbody2D_Get(index);
    if (rb == NULL)
        return;

    return rb->velocity;
}
void CNodes_Rigidbody2D_SetGravityScale(CNodes_Rigidbody2D_Index index, float scale)
{
    CNodes_Rigidbody2D *rb = CNodes_INTERN_Rigidbody2D_Get(index);
    if (rb == NULL)
        return;

    rb->gravity_scale = scale;
}
void CNodes_Rigidbody2D_UseGravity(CNodes_Rigidbody2D_Index index, CNodes_Bool use)
{
    CNodes_Rigidbody2D *rb = CNodes_INTERN_Rigidbody2D_Get(index);
    if (rb == NULL)
        return;

    rb->use_gravity = use;
}
void CNodes_Rigidbody2D_SetLinearDrag(CNodes_Rigidbody2D_Index index, float drag)
{
    CNodes_Rigidbody2D *rb = CNodes_INTERN_Rigidbody2D_Get(index);
    if (rb == NULL)
        return;

    rb->linear_drag = drag;
}

CNodes_Rigidbody2D *CNodes_INTERN_Rigidbody2D_Get(CNodes_Rigidbody2D_Index index)
{
    CNodes_Rigidbody2D *rb = &g_rigidbodys[index];
    if (rb->base.active == CNODES_FALSE)
        return NULL;
    return rb;
}