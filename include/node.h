#pragma once

#define MAX_NODES 4096
#define MAX_CHILDREN_NODES 16
#define MAX_NODE_COMPONENTS 16
#define MAX_TAG_SIZE 32

#include "component.h"
#include "transform.h"
#include "bool.h"

typedef int CN_Node_Index;

typedef struct Node
{
    char tag[MAX_TAG_SIZE]; // 4 bytes

    CN_Transform_Index transform; // 2 bytes

    int children[MAX_CHILDREN_NODES]; // 32 bytes
    int children_count;               // 2 bytes

    int components[MAX_NODE_COMPONENTS]; // 32 bytes
    int component_count;                 // 2 bytes

    CN_Bool alive; // 1 byte

} Node;

extern Node g_nodes[MAX_NODES];

extern int g_node_count;

extern int gamenode_free_list[MAX_NODES];
extern int gamenode_free_count;

CN_Node_Index CN_Node_Create(const char *tag);
int CN_Node_Destroy(int index);

Node *CN_INTERN_Node_Get(CN_Node_Index index);
CN_Transform_Index CN_Node_GetTransform(CN_Node_Index index);
CN_Bool CN_Node_AddComponent(CN_Node_Index index, int component_index, ComponentType type);