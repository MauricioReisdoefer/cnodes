#include <stdio.h>
#include <stdlib.h>

#include "gameobject.h"
#include "component.h"

Component *Component_Create(GameObject *owner, ComponentType type);