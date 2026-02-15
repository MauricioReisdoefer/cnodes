#include <stdio.h>
#include <stdlib.h>

#include "node.h"
#include "component.h"

GameNode *GameNode_Create(const char *tag)
{
    GameNode *self = calloc(1, sizeof(GameNode));
    if (!self)
        return NULL;

    self->tag = strdup(tag);
    if (!self->tag)
    {
        free(self);
        return NULL;
    }

    self->transform = Transform_Create();

    return self;
}

int GameNode_Destroy(GameNode **self)
{
    if (self == NULL || *self == NULL)
        return 0;
    free((*self)->tag);

    for (int i = 0; i < (*self)->children_count; i++)
    {
        GameNode_Destroy(&(*self)->children[i]);
    }

    for (int i = 0; i < (*self)->component_count; i++)
    {
        Component_Destroy(&(*self)->components[i]);
    }

    free(*self);
    *self = NULL;

    return 1;
}
