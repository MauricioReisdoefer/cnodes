#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#define MAX_COMPONENTS 16
#define MAX_TAG_SIZE 32

#include "component.h"

typedef struct GameObject
{
    Component *components[MAX_COMPONENTS];
    int active;
    int componentCount;
    char *tag[MAX_TAG_SIZE];
} GameObject;

GameObject *GameObject_Create();
void GameObject_Destroy(GameObject *gameObject);

#endif