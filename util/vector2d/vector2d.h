#pragma once

class Vector2D
{
public:
    Vector2D(const float& _x = 0, const float& _y = 0);
    Vector2D add(const Vector2D& other);
    Vector2D sub(const Vector2D& other);
    Vector2D mult(const Vector2D& other);
    Vector2D divide(const Vector2D& other);
    void Set(const float& x, const float& y);

    float x;
    float y;
};

