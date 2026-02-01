#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node.h"
#include "feature.h"

Node *Node_Create()
{
    Node *node = (Node *)malloc(sizeof(Node));

    if (node == NULL)
    {
        printf("Node was not initialized!");
        return NULL;
    }

    node->active = 1;
    node->componentCount = 0;
    snprintf(node->tag, sizeof(node->tag), "Default");

    return node;
}
void Node_Destroy(Node *node)
{
    if (node->componentCount > 0)
    {
        for (int i = 0; i < node->componentCount; i++)
        {
            Feature_Destroy(node->components[i]);
        }
    }
    free(node);
}