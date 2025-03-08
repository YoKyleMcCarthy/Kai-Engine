#pragma once

#include <iostream>
#include <Scene/Scene.hpp>
#include <SDL3/SDL.h>
#include <Util/Timer.hpp>
#include <Pybind11/pybind11.h>

namespace py = pybind11;

class World: public Scene {
private:
    py::module script;
public:
    void Init() override;
    void Update(float deltaTime) override;
    void Draw() override;
    void Destroy() override;
};