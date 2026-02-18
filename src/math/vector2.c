#include <stdio.h>
#include <math.h>
#include "math/vector2.h"

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

Vector2 Vector2_Normalize(Vector2 v)
{
    float length = sqrtf(v.x * v.x + v.y * v.y);

    if (length == 0.0f)
        return (Vector2){0.0f, 0.0f};

    return (Vector2){v.x / length, v.y / length};
}

float Vector2_Dot(Vector2 a, Vector2 b)
{
    return a.x * b.x + a.y * b.y;
}

float Vector2_Length(Vector2 v)
{
    return sqrtf(v.x * v.x + v.y * v.y);
}

float Vector2_LengthSquared(Vector2 v)
{
    return v.x * v.x + v.y * v.y;
}

float Vector2_Distance(Vector2 a, Vector2 b)
{
    float dx = b.x - a.x;
    float dy = b.y - a.y;
    return sqrtf(dx * dx + dy * dy);
}

float Vector2_DistanceSquared(Vector2 a, Vector2 b)
{
    float dx = b.x - a.x;
    float dy = b.y - a.y;
    return dx * dx + dy * dy;
}

Vector2 Vector2_Lerp(Vector2 a, Vector2 b, float t)
{
    return (Vector2){
        a.x + (b.x - a.x) * t,
        a.y + (b.y - a.y) * t};
}

Vector2 Vector2_Scale(Vector2 a, float b)
{
    return (Vector2){
        a.x * b,
        a.y * b};
}