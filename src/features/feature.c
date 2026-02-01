#include <stdio.h>
#include <stdlib.h>

#include "node.h"
#include "feature.h"

const char *_feature_type_to_string(FeatureType type)
{
    switch (type)
    {
    case FEATURE_TRANSFORM:
        return "FEATURE_TRANSFORM";
    case FEATURE_RIGIDBODY:
        return "FEATURE_RIGIDBODY";
    case FEATURE_SPRITE:
        return "FEATURE_SPRITE";
    case FEATURE_COLLIDER:
        return "FEATURE_COLLIDER";
    default:
        return "UNKNOWN_FEATURE";
    }
}

Feature *Feature_Create(Node *owner, FeatureType type)
{
    Feature *feature = (Feature *)malloc(sizeof(Feature));
    if (feature == NULL)
    {
        printf("Feature of type %s was not initialized!\n", _feature_type_to_string(type));
        return NULL;
    }

    feature->owner = owner;
    feature->type = type;
}

void Feature_Destroy(Feature *feature)
{
    free(feature);
}
