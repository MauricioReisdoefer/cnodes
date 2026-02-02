#include <stdio.h>

#include "node.h"
#include "console.h"
#include "feature.h"

int main()
{
    Struct_Console_Init(STRUCT_CONSOLE_FLAG_DEBUG_MODE);
    Node *firstNode = Node_Create();
    Feature *emptyFeature = Feature_Create(firstNode, FEATURE_UNDEFINED);

    Node_Add_Feature(firstNode, emptyFeature);
    Node_Destroy(firstNode);

    if (firstNode)
    {
        STRUCT_CONSOLE_DEBUG("firstNode was Destroyed");
    }

    if (emptyFeature)
    {
        STRUCT_CONSOLE_DEBUG("emptyFeature was Destroyed");
    }
    return 0;
}