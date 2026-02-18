#include <stdio.h>
#include <stdlib.h>

#include "components/rigidbody.h"
#include "math/vector2.h"
#include "node.h"
#include "components/transform.h"

CN_Rigidbody2D_Index CN_Rigidbody2D_Create()
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

    CN_Rigidbody2D *t = &g_rigidbodys[index];

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
    t->base.destroy = CN_Rigidbody2D_Destroy;
    t->base.update = CN_Rigidbody2D_Update;

    return index;
}

void CN_Rigidbody2D_Destroy(Component *self)
{
    CN_Rigidbody2D *rb = (CN_Rigidbody2D *)self;
    rb->base.active = 0;
    int index = rb->internal_index;

    if (index < 0 || index >= MAX_COMPONENTS)
        return;

    if (rigidbody_free_count < MAX_COMPONENTS)
    {
        rigidbody_free_list[rigidbody_free_count++] = index;
    }
}

void CN_Rigidbody2D_Update(Component *self, float dt)
{
    CN_Rigidbody2D *rb = (CN_Rigidbody2D *)self;
    if (rb == NULL)
        return;

    Vector2 force = rb->force_accumulator;
    force = Vector2_Subtract(force, Vector2_Scale(rb->velocity, rb->linear_drag));

    Vector2 acceleration = Vector2_Scale(force, rb->inverse_mass);
    rb->velocity = Vector2_Add(rb->velocity, Vector2_Scale(acceleration, dt));

    CN_Transform_Index index = CN_GameNode_GetTransform(rb->base.owner);
    Transform *transform = CN_Transform_Get(index);

    transform->position = Vector2_Add(Vector2_Scale(rb->velocity, dt), transform->position);

    rb->force_accumulator = Vector2_Zero();
}

void CN_Rigidbody2D_AddForce(CN_Rigidbody2D_Index index, Vector2 force)
{
    CN_Rigidbody2D *rb = CN_INTERN_Rigidbody2D_Get(index);
    if (rb == NULL)
        return;
    rb->force_accumulator = Vector2_Add(rb->force_accumulator, force);
}
void CN_Rigidbody2D_SetMass(CN_Rigidbody2D_Index index, float mass)
{
    CN_Rigidbody2D *rb = CN_INTERN_Rigidbody2D_Get(index);
    if (rb == NULL)
        return;
    rb->mass = mass;
    rb->inverse_mass = 1.0f / mass;
}
void CN_Rigidbody2D_SetVelocity(CN_Rigidbody2D_Index index, Vector2 velocity)
{
    CN_Rigidbody2D *rb = CN_INTERN_Rigidbody2D_Get(index);
    if (rb == NULL)
        return;

    rb->velocity = velocity;
}
Vector2 CN_Rigidbody2D_GetVelocity(CN_Rigidbody2D_Index index)
{
    CN_Rigidbody2D *rb = CN_INTERN_Rigidbody2D_Get(index);
    if (rb == NULL)
        return;

    return rb->velocity;
}
void CN_Rigidbody2D_SetGravityScale(CN_Rigidbody2D_Index index, float scale)
{
    CN_Rigidbody2D *rb = CN_INTERN_Rigidbody2D_Get(index);
    if (rb == NULL)
        return;

    rb->gravity_scale = scale;
}
void CN_Rigidbody2D_UseGravity(CN_Rigidbody2D_Index index, CN_Bool use)
{
    CN_Rigidbody2D *rb = CN_INTERN_Rigidbody2D_Get(index);
    if (rb == NULL)
        return;

    rb->use_gravity = use;
}
void CN_Rigidbody2D_SetLinearDrag(CN_Rigidbody2D_Index index, float drag)
{
    CN_Rigidbody2D *rb = CN_INTERN_Rigidbody2D_Get(index);
    if (rb == NULL)
        return;

    rb->linear_drag = drag;
}

CN_Rigidbody2D *CN_INTERN_Rigidbody2D_Get(CN_Rigidbody2D_Index index)
{
    CN_Rigidbody2D *rb = &g_rigidbodys[index];
    if (rb->base.active == CN_FALSE)
        return NULL;
    return rb;
}