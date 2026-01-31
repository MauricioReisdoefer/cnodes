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
    strcpy(*gameObject->tag, "Default");

    return gameObject;
}
void GameObject_Destroy(GameObject *gameObject)
{
}