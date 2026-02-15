#include <stdio.h>
#include "vector2.h"

Vector2 Vector2_Zero()
{
    Vector2 result;
    result.x = 0.0f;
    result.y = 0.0f;
    return result;
}

Vector2 Vector2_Multiply(Vector2 a, Vector2 b)
{
    Vector2 result;
    result.x = a.x * b.x;
    result.y = a.y * b.y;
    return result;
}

Vector2 Vector2_Add(Vector2 a, Vector2 b)
{
    Vector2 result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    return result;
}

Vector2 Vector2_Divide(Vector2 a, Vector2 b)
{
    Vector2 result;

    result.x = (b.x != 0.0f) ? a.x / b.x : 0.0f;
    result.y = (b.y != 0.0f) ? a.y / b.y : 0.0f;

    return result;
}

Vector2 Vector2_Subtract(Vector2 a, Vector2 b)
{
    Vector2 result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    return result;
}

Vector2 Vector2_Normalize(Vector2 v);
float Vector2_Dot(Vector2 a, Vector2 b);

float Vector2_Length(Vector2 v);
float Vector2_LengthSquared(Vector2 v);

float Vector2_Distance(Vector2 a, Vector2 b);
float Vector2_DistanceSquared(Vector2 a, Vector2 b);

Vector2 Vector2_Lerp(Vector2 a, Vector2 b, float t);
Vector2 Vector2_Scale(Vector2 a, float b);