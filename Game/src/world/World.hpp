#pragma once

#include <iostream>
#include <Scene/Scene.hpp>
#include <SDL3/SDL.h>

class World: public Scene {
public:
    void Init() override;
    void Update(float deltaTime) override;
    void Draw() override;
    void Destroy() override;
};