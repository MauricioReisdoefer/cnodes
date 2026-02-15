#pragma once

#define MAX_CHILDREN_NODES 16
#define MAX_NODE_COMPONENT 32

#include "component.h"
#include "transform.h"

typedef struct GameNode GameNode;

typedef struct GameNode
{
    char *tag;

    Transform transform;

    struct GameNode *children[MAX_CHILDREN_NODES];
    int children_count;

    Component *components[MAX_NODE_COMPONENT];
    int component_count;

} GameNode;

GameNode *GameNode_Create(char *tag);
int GameNode_Destroy(GameNode **self);