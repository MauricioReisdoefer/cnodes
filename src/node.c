#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node.h"
#include "feature.h"
#include "console.h"

Node *Node_Create()
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL)
    {
        STRUCT_CONSOLE_ERROR("Node_Create: Node was not initialized!");
        return NULL;
    }

    node->active = 1;
    node->featureCount = 0;
    snprintf(node->tag, sizeof(node->tag), "Default");

    return node;
}
void Node_Destroy(Node *node)
{
    if (!node)
        return;
    if (node->featureCount > 0)
    {
        for (int i = 0; i < node->featureCount; i++)
        {
            Feature_Destroy(node->features[i]);
            node->features[i] = NULL;
        }
        node->featureCount = 0;
    }
    if (node->childrenCount > 0)
    {
        for (int i = 0; i < node->childrenCount; i++)
        {
            Node_Destroy(node->children[i]);
            node->children[i] = NULL;
        }
        node->childrenCount = 0;
    }
    free(node);
}

void Node_Add_Feature(Node *self, Feature *feature)
{
    if (!self || !feature)
    {
        STRUCT_CONSOLE_WARN("Node_Add_Feature: self or feature is NULL\n");
        return;
    }

    if (self->featureCount >= MAX_COMPONENTS)
    {
        STRUCT_CONSOLE_WARN("Node_Add_Feature: maximum features reached\n");
        return;
    }

    self->features[self->featureCount] = feature;
    self->featureCount++;
}

Feature *Node_Get_Feature(Node *self, FeatureType type)
{
    if (!self)
    {
        STRUCT_CONSOLE_WARN("Node_Get_Feature: self is NULL\n");
        return NULL;
    }

    for (int i = 0; i < self->featureCount; i++)
    {
        if (self->features[i] && self->features[i]->type == type)
        {
            return self->features[i];
        }
    }
    return NULL;
}