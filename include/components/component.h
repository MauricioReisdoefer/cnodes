#ifndef COMPONENT_H
#define COMPONENT_H

#include <stdlib.h>

typedef enum
{
    COMPONENT_TRANSFORM,
    COMPONENT_RIGIDBODY,
    COMPONENT_SPRITE,
    COMPONENT_COLLIDER
} ComponentType;

// Forward Declaration
struct GameObject;

typedef struct
{
    struct GameObject *owner;
    ComponentType type;
} Component;

Component *Component_Create(struct GameObject *owner, ComponentType type);
void Component_Destroy(Component *component);

#endif