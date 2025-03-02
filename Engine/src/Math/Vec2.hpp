//
//  Vec2.hpp
//  2DGame
//
//  Created by Kyle McCarthy on 23/2/2025.
//
#ifndef __VEC2__
#define __VEC2__

#include <cmath>  // For std::sqrt and std::pow


template <typename T>
class Vec2 {
public:
    T x;
    T y;

    Vec2(T x = 0, T y = 0) : x(x), y(y) {}
    
    T& X() { return this->x; }
    T& Y() { return this->y; }
    
    // Length function to calculate distance between this vector and another
    T length(const Vec2& other) const {
        T dx = this->x - other.x;
        T dy = this->y - other.y;
        return std::sqrt(dx * dx + dy * dy);  // Pythagorean theorem
    }
    
    
    
    Vec2 operator+(const Vec2& vec2) const {
        return Vec2(this->x + vec2.x, this->y + vec2.y);
    }
    
    Vec2& operator=(const Vec2& vec2) {
        if (this != &vec2) {  // Prevent self-assignment
            this->x = vec2.x;
            this->y = vec2.y;
        }
        return *this;
    }
    
    Vec2 operator+=(Vec2 const& vec2) {
        this->x += vec2.x;
        this->y += vec2.y;
        return *this;
    }
    
    Vec2 operator-(const Vec2& vec2) const {
        return Vec2(this->x - vec2.x, this->y - vec2.y);
    }
    
    Vec2 operator-=(Vec2 const& vec2) {
        this->x -= vec2.x;
        this->y -= vec2.y;
        return *this;
    }

    // Scalar multiplication
    Vec2 operator*(T scalar) const {
        return Vec2(this->x * scalar, this->y * scalar);
    }

    Vec2& operator*=(T scalar) {
        this->x *= scalar;
        this->y *= scalar;
        return *this;
    }

    // Scalar division
    Vec2 operator/(T scalar) const {
        return Vec2(this->x / scalar, this->y / scalar);
    }

    Vec2& operator/=(T scalar) {
        this->x /= scalar;
        this->y /= scalar;
        return *this;
    }

    // Component-wise multiplication
    Vec2 operator*(Vec2 const& vec2) const {
        return Vec2(this->x * vec2.x, this->y * vec2.y);
    }

    Vec2 operator/=(Vec2 const& vec2) {
        this->x /= vec2.x;
        this->y /= vec2.y;
        return *this;
    }
    
    friend std::ostream& operator<<(std::ostream& os, const Vec2& vec2) {
        os << "[x]: " << vec2.x << " [y]: " << vec2.y;
        return os;
    }
};

#endif
