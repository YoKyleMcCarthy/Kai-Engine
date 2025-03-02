//
//  Camera.hpp
//  2DGame
//
//  Created by Kyle McCarthy on 23/2/2025.
//

#pragma once
#include <iostream>
#include <Math/Vec2.hpp>

class Camera {
public:
    Vec2<float> pos; // Camera's own position
    Vec2<float> size; // Size of Camera screen
    Vec2<float> targetPos;
    float smoothSpeed = 10.f;

    Camera(Vec2<float> pos, Vec2<float> size) : pos(pos), size(size), targetPos(pos) {} // Initialize camera's own position

    void Update(float deltaTime) {
        
//        // Clamp the target position to keep it within the world boundaries
//        if (targetPos.X() < 0) {
//            targetPos.X() = 0; // Camera can't go past left boundary
//        }
//        if (targetPos.Y() < 0) {
//            targetPos.Y() = 0; // Camera can't go past top boundary
//        }
//        if (targetPos.X() + size.X() > worldSize.x) {
//            targetPos.X() = worldSize.x - size.X(); // Camera can't go past right boundary
//        }
//        if (targetPos.Y() + size.Y() > worldSize.y) {
//            targetPos.Y() = worldSize.y - size.Y(); // Camera can't go past bottom boundary
//        }

        // Smoothly move the camera towards the target position
        Vec2<float> diff = targetPos - pos;
        pos += diff * smoothSpeed * deltaTime;

    }

    void CenterOnTarget(Vec2<float> targetEntityPos) {
        Vec2<float> screenCenter = Vec2<float>(size.X() / 2.0f, size.Y() / 2.0f);
        targetPos = targetEntityPos - screenCenter;
    }
};
