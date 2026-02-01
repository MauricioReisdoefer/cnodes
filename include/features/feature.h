#ifndef FEATURE_H
#define FEATURE_H

#include <stdlib.h>

typedef enum
{
    FEATURE_TRANSFORM,
    FEATURE_RIGIDBODY,
    FEATURE_SPRITE,
    FEATURE_COLLIDER
} FeatureType;

// Forward Declaration
struct Node;

typedef struct
{
    struct Node *owner;
    FeatureType type;
} Feature;

Feature *Feature_Create(struct Node *owner, FeatureType type);
void Feature_Destroy(Feature *component);

#endif