#include "components/transform.h"
#include "math/vector2.h"

#include <stdio.h>

Transform *CN_Transform_Get(int index);

int CN_Transform_Create()
{
    int index;

    if (transform_free_count > 0)
    {
        index = transform_free_list[--transform_free_count];
    }
    else
    {
        if (g_transform_count >= MAX_COMPONENTS)
            return -1;

        index = g_transform_count++;
    }

    Transform *t = &g_transforms[index];

    t->position = Vector2_Zero();
    t->scale = (Vector2){1.0f, 1.0f};
    t->rotation = Vector2_Zero();

    return index;
}

void CN_Transform_Destroy(int index)
{
    if (index < 0 || index >= MAX_COMPONENTS)
        return;

    if (transform_free_count < MAX_COMPONENTS)
    {
        transform_free_list[transform_free_count++] = index;
    }
}