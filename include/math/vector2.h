#pragma once

typedef struct Vector2
{
    float x;
    float y;
} Vector2;

Vector2 Vector2_Zero();
Vector2 Vector2_Multiply(Vector2 a, Vector2 b);
Vector2 Vector2_Sum(Vector2 a, Vector2 b);
Vector2 Vector2_Divide(Vector2 a, Vector2 b);
Vector2 Vector2_Subtract(Vector2 a, Vector2 b);

Vector2 Vector2_Normalize(Vector2 v);
float Vector2_Dot(Vector2 a, Vector2 b);

float Vector2_Length(Vector2 v);
float Vector2_LengthSquared(Vector2 v);

float Vector2_Distance(Vector2 a, Vector2 b);
float Vector2_DistanceSquared(Vector2 a, Vector2 b);

Vector2 Vector2_Lerp(Vector2 a, Vector2 b, float t);
Vector2 Vector2_Scale(Vector2 a, float b);