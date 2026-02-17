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
    char tag[MAX_TAG_SIZE]; // 4 bytes

    CNodes_Transform_Index transform; // 2 bytes

    int children[MAX_CHILDREN_NODES]; // 32 bytes
    int children_count;               // 2 bytes

    int components[MAX_NODE_COMPONENTS]; // 32 bytes
    int component_count;                 // 2 bytes

    CNodes_Bool alive; // 1 byte

} GameNode;

extern GameNode g_nodes[MAX_NODES];

extern int g_node_count;

extern int gamenode_free_list[MAX_NODES];
extern int gamenode_free_count;

CNodes_GameNode_Index CNodes_GameNode_Create(const char *tag);
int CNodes_GameNode_Destroy(int index);

GameNode *CNodes_INTERN_GameNode_Get(CNodes_GameNode_Index index);
CNodes_Transform_Index CNodes_GameNode_GetTransform(CNodes_GameNode_Index index);