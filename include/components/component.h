#ifndef COMPONENT_H
#define COMPONENT_H

typedef struct GameObject;

typedef enum
{
    COMPONENT_TRANSFORM,
    COMPONENT_RIGIDBODY,
    COMPONENT_SPRITE,
    COMPONENT_COLLIDER

} ComponentType;

typedef struct Component
{
    ComponentType type;
    GameObject *owner;
} Component;

Component *Component_Create(GameObject *owner, ComponentType type);
void Component_Destroy(Component *component);

#endif