#include "transform.h"
#include "vector2.h"

#include <stdio.h>

Transform Transform_Create()
{
    Transform new_transform = (Transform){Vector2_Zero(), Vector2_Zero(), Vector2_Zero()};
    return new_transform;
}