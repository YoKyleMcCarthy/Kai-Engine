#pragma once

#include <iostream>
#include <Scene/SceneManager.hpp>
#include <Math/Vec2.hpp>
#include <SDL3/SDL.h>


class Editor {
    private:
        SceneManager* sceneManager;
        Scene* currentScene;
        Vec2<float> mousePos;
        bool showMouseGridOnly = true;
public:
    Editor() = default;
    void Init();
    void Show();
    void Update(float deltaTime);
    void DrawMouseGrid();
    void DrawGrid();
    void Draw();

    void Destroy();
};
