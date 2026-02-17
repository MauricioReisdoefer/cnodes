#pragma once

#define MAX_NODES 4096
#define MAX_CHILDREN_NODES 16
#define MAX_NODE_COMPONENTS 16
#define MAX_TAG_SIZE 32

#include "component.h"
#include "transform.h"
#include "bool.h"

typedef int CNodes_GameNode_Index;

typedef struct GameNode
{
    char tag[MAX_TAG_SIZE];

    CNodes_Transform_Index transform;

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

CNodes_GameNode_Index CNodes_GameNode_Create(const char *tag);
int CNodes_GameNode_Destroy(int index);

GameNode *CNodes_INTERN_GameNode_Get(CNodes_GameNode_Index index);
CNodes_Transform_Index CNodes_GameNode_GetTransform(CNodes_GameNode_Index index);