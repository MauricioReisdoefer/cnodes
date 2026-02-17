#pragma once

typedef enum ComponentType
{
    COMPONENT_DEFAULT,
    COMPONENT_RIGIDBODY,
    COMPONENT_PARTICLE_SYSTEM,
    COMPONENT_COLLIDER
} ComponentType;

typedef struct Component
{
    ComponentType type;
    int owner;
    int active;

    void (*update)(struct Component *self, float dt);
    void (*destroy)(struct Component *self);
} Component;
