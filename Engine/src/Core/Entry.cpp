#include "pch.hpp"
#include <chrono>
#include <Scene/SceneManager.hpp>
#include <Scene/EntryScene.hpp>
#include <Window/Window.hpp>
#include <Camera/Camera.hpp>
#include <SDL3/SDL.h>
#include <Math/Vec2.hpp>

int main() {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
    const int width = 1080;
    const int height = 720;
    Window window("Engine Dev alpha 0.1", Vec2<float>(width, height));
    SDL_Renderer* renderer = SDL_CreateRenderer(window.Get(), NULL);
    SceneManager::GetInstance()->setCurrentScene(new EntryScene());
    Camera* camera = new Camera(Vec2<float>(0,0), Vec2<float>(width,height));
    SceneManager::GetInstance()->camera = camera;

    auto lastTime = std::chrono::high_resolution_clock::now();

    SDL_Event event;
    while(window.isOpen) {
        auto currentTime = std::chrono::high_resolution_clock::now();
        float deltaTime = std::chrono::duration<float, std::chrono::seconds::period>(currentTime - lastTime).count();
        lastTime = currentTime;

        while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_EVENT_QUIT:
                    window.Close();
                    break;
                case SDL_EVENT_WINDOW_RESIZED:
                    window.resize();
                    camera->size = window.windowSize;
            }
        }

        // Update Everything here
        camera->Update(deltaTime);
        SceneManager::GetInstance()->Update(deltaTime);
        SceneManager::GetInstance()->Draw();

    }

    delete camera;

    return 0;
}