#pragma once

#include <cmath>

namespace RB
{
    class Vector2
    {
    public:
        float x, y;

        // Default constructor
        Vector2(float x = 0.0f, float y = 0.0f) : x(x), y(y)
        {

        }

        // Additional constructor with int parameters
        Vector2(int x, int y) : x(static_cast<float>(std::round(x))), y(static_cast<float>(std::round(y)))
        {

        }

        // Addition
        Vector2 operator+(const Vector2& other) const 
        {
            return Vector2(x + other.x, y + other.y);
        }

        // Subtraction
        Vector2 operator-(const Vector2& other) const
        {
            return Vector2(x - other.x, y - other.y);
        }

        // Scalar multiplication
        Vector2 operator*(float scalar) const
        {
            return Vector2(x * scalar, y * scalar);
        }

        // Scalar division
        Vector2 operator/(float scalar) const
        {
            return Vector2(x / scalar, y / scalar);
        }

        // Dot product
        float Dot(const Vector2& other) const
        {
            return x * other.x + y * other.y;
        }

        // Magnitude (length)
        float Magnitude() const
        {
            return std::sqrt(x * x + y * y);
        }

        // Normalize
        Vector2 Normalize() const
        {
            float magnitude = Magnitude();
            return Vector2(x / magnitude, y / magnitude);
        }

        int GetIntX()
        {
            return static_cast<int>(std::round(x));
        }

        int GetIntY()
        {
            return static_cast<int>(std::round(y));
        }
    };
}
