#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gameobject.h"

GameObject *GameObject_Create()
{
    GameObject *gameObject = (GameObject *)malloc(sizeof(GameObject));

    if (gameObject == NULL)
    {
        printf("GameObject was not initialized!");
        return NULL;
    }

    gameObject->active = 1;
    gameObject->componentCount = 0;
    snprintf(gameObject->tag, sizeof(gameObject->tag), "Default");

    return gameObject;
}
void GameObject_Destroy(GameObject *gameObject)
{
    if (gameObject->componentCount > 0)
    {
        for (int i = 0; i < gameObject->componentCount; i++)
        {
            Component_Destroy(gameObject->components[i]);
        }
    }
    free(gameObject);
}