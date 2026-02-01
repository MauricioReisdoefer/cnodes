#ifndef NODE_H
#define NODE_H

#define MAX_COMPONENTS 32
#define MAX_TAG_SIZE 64
#define MAX_CHILDREN_NODES 32

#include "feature.h"

typedef struct Node
{
    Feature *components[MAX_COMPONENTS];
    int active;
    int componentCount;
    char tag[MAX_TAG_SIZE];
} Node;

Node *Node_Create();
void Node_Destroy(Node *node);

#endif