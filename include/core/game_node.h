#pragma once

#define MAX_CHILDREN_NODES 16
#define MAX_NODE_FEATURES 32
#define MAX_TAG_SIZE 32

#include "feature.h"

typedef struct GameNode GameNode;

typedef struct GameNode
{
    char *tag[MAX_TAG_SIZE];
    GameNode *children[MAX_CHILDREN_NODES];
    NodeFeature *features[MAX_NODE_FEATURES];

    int children_count;
    int feature_count;

} GameNode;