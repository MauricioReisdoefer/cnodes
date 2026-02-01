#include <stdio.h>
#include <stdlib.h>

#include "gameobject.h"
#include "component.h"

const char *_component_type_to_string(ComponentType type)
{
    switch (type)
    {
    case COMPONENT_TRANSFORM:
        return "COMPONENT_TRANSFORM";
    case COMPONENT_RIGIDBODY:
        return "COMPONENT_RIGIDBODY";
    case COMPONENT_SPRITE:
        return "COMPONENT_SPRITE";
    case COMPONENT_COLLIDER:
        return "COMPONENT_COLLIDER";
    default:
        return "UNKNOWN_COMPONENT";
    }
}

Component *Component_Create(GameObject *owner, ComponentType type)
{
    Component *component = (Component *)malloc(sizeof(Component));
    if (component == NULL)
    {
        printf("Component of type %s was not initialized!\n", _component_type_to_string(type));
        return NULL;
    }

    component->owner = owner;
    component->type = type;
}

void Component_Destroy(Component *component)
{
    free(component);
}
