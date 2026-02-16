#pragma once

#define MAX_NODES 4096
#define MAX_COMPONENTS 16894
#define MAX_TAG_SIZE 32

#include "component.h"
#include "transform.h"

typedef struct GameNode
{
    char tag[MAX_TAG_SIZE];

    int transform;

    int children[MAX_NODES];
    int children_count;

    int components[MAX_COMPONENTS];
    int component_count;

    int alive;

} GameNode;

extern GameNode g_nodes[MAX_NODES];

extern int g_node_count;

extern int gamenode_free_list[MAX_NODES];
extern int gamenode_free_count;

int GameNode_Create(const char *tag);
int GameNode_Destroy(int index);
