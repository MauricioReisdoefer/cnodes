#pragma once

#include "bool.h"

typedef enum ComponentType
{
    COMPONENT_DEFAULT,
    COMPONENT_RIGIDBODY,
    COMPONENT_PARTICLE_SYSTEM,
    COMPONENT_COLLIDER
} ComponentType;

typedef struct Component
{
    ComponentType type; // 2 bytes
    int owner;          // 2 bytes
    CNodes_Bool active; // 1 byte

    void (*update)(struct Component *self, float dt);
    void (*destroy)(struct Component *self);
} Component;
