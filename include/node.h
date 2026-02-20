#pragma once

#define MAX_NODES 4096
#define MAX_CHILDREN_NODES 16
#define MAX_NODE_COMPONENTS 16
#define MAX_TAG_SIZE 32

#include "components/component.h"
#include "components/transform.h"
#include "core/bool.h"

typedef struct Node
{
    char tag[MAX_TAG_SIZE]; // 4 bytes

    int transform; // 2 bytes

    int children[MAX_CHILDREN_NODES]; // 32 bytes
    int children_count;               // 2 bytes

    Component *components[MAX_NODE_COMPONENTS];
    int component_count; // 2 bytes

    CN_Bool alive; // 1 byte

} Node;

extern Node g_nodes[MAX_NODES];

extern int g_node_count;

extern int gamenode_free_list[MAX_NODES];
extern int gamenode_free_count;

int CN_Node_Create(const char *tag);
int CN_Node_Destroy(int index);

Node *CN_INTERN_Node_Get(int index);
int CN_Node_GetTransform(int index);
CN_Bool CN_Node_AddComponent(int index, Component *component);