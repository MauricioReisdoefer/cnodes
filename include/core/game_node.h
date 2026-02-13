#pragma once

#define MAX_CHILDREN_NODES 16
#define MAX_NODE_FEATURES 32

#include "component.h"

typedef struct GameNode GameNode;

typedef struct GameNode
{
    char *tag;
    GameNode *children[MAX_CHILDREN_NODES];
    Component *features[MAX_NODE_FEATURES];

    int children_count;
    int feature_count;

} GameNode;

GameNode *GameNode_Create(char *tag[]);
int GameNode_Destroy(GameNode **self);