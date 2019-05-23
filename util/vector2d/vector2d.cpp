#include "util/vector2d/vector2d.h"

Vector2D::Vector2D(const float& _x, const float& _y)
    : x(_x), y(_y)
{
}

Vector2D Vector2D::add(const Vector2D& other)
{
    return { this->x + other.x, this->y + other.y };
}

Vector2D Vector2D::sub(const Vector2D& other)
{
    return { this->x - other.x, this->y - other.y };
}

Vector2D Vector2D::mult(const Vector2D& other)
{
    return { this->x * other.x, this->y * other.y };
}

Vector2D Vector2D::divide(const Vector2D& other)
{
    return { this->x / other.x , this->y / other.y };
}

void Vector2D::Set(const float &x, const float &y)
{
    this->x = x;
    this->y = y;
}
