#pragma once

#define MAX_NODES 4096
#define MAX_CHILDREN_NODES 16
#define MAX_NODE_COMPONENTS 16
#define MAX_TAG_SIZE 32

#include "component.h"
#include "transform.h"
#include "bool.h"

typedef struct GameNode
{
    char tag[MAX_TAG_SIZE];

    int transform;

    int children[MAX_CHILDREN_NODES];
    int children_count;

    int components[MAX_NODE_COMPONENTS];
    int component_count;

    CNodes_Bool alive;

} GameNode;

extern GameNode g_nodes[MAX_NODES];

extern int g_node_count;

extern int gamenode_free_list[MAX_NODES];
extern int gamenode_free_count;

int GameNode_Create(const char *tag);
int GameNode_Destroy(int index);
