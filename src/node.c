#include "node.h"
#include "component.h"
#include "bool.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int CN_Node_Create(const char *tag)
{
    int index;
    if (gamenode_free_count > 0)
    {
        index = gamenode_free_list[--gamenode_free_count];
    }
    else
    {
        if (g_node_count >= MAX_NODES)
            return -1;
        index = g_node_count++;
    }

    Node *node = &g_nodes[index];
    memset(node, 0, sizeof(Node));

    memset(node->children, -1, sizeof(node->children));
    memset(node->components, -1, sizeof(node->components));

    strncpy(node->tag, tag, MAX_TAG_SIZE - 1);
    node->tag[MAX_TAG_SIZE - 1] = '\0';

    node->alive = CN_TRUE;
    node->transform = Transform_Create();

    return index;
}

int CN_Node_Destroy(int index)
{
    if (index < 0 || index >= MAX_NODES)
        return 0;

    Node *node = &g_nodes[index];
    if (!node->alive)
        return 0;
    node->alive = CN_FALSE;

    for (int i = 0; i < node->children_count; i++)
    {
        int childIndex = node->children[i];
        if (childIndex >= 0 && childIndex < MAX_NODES)
        {
            Node_Destroy(childIndex);
        }
    }
    for (int i = 0; i < node->component_count; i++)
    {
        int compIndex = node->components[i];
        if (compIndex >= 0 && compIndex < MAX_COMPONENTS)
        {
            Component_Destroy(compIndex);
        }
    }

    Transform_Destroy(node->transform);

    node->tag[0] = '\0';

    if (gamenode_free_count < MAX_NODES)
    {
        gamenode_free_list[gamenode_free_count++] = index;
    }

    return 1;
}

Node *CN_INTERN_Node_Get(CN_Node_Index index)
{
    Node *node = &g_nodes[index];
    if (node->alive == CN_FALSE)
        return NULL;
    return node;
}

CN_Transform_Index CN_Node_GetTransform(CN_Node_Index index)
{
    Node *node = CN_INTERN_Node_Get(index);
    if (node == NULL)
        return -1;
    return node->transform;
}

CN_Bool CN_Node_AddComponent(CN_Node_Index index, int component_index, ComponentType type)
{
}