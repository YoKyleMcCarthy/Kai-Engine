#pragma once

#include "Component.hpp"
#include <Math/Vec2.hpp>
#include <Pybind11/pybind11.h>

class Transform : public Component {
public:
    Vec2<float> position;
    Vec2<float> scale;
    float rotation;
    Transform() : position(Vec2<float>(0,0)), scale(Vec2<float>(1,1)), rotation(0) {}
    Transform(Vec2<float> position, Vec2<float> scale, float rotation) : position(position), scale(scale), rotation(rotation) {}
    void Update(float deltaTime) override {
        // Update the transform

    }
};
