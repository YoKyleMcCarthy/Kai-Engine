#include "pch.hpp"
#include <chrono>
#include <Scene/SceneManager.hpp>
#include <Scene/EntryScene.hpp>
#include <Asset/AssetManager.hpp>
#include <Window/Window.hpp>
#include <Camera/Camera.hpp>
#include <SDL3/SDL.h>
#include <iostream>
#include <Editor/Editor.hpp>

#include <Python/Python.h>
#include <Pybind11/embed.h>

namespace py = pybind11;


int main() {
    py::scoped_interpreter guard{};

    
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
    const int width = 1080;
    const int height = 720;
    Window window("Engine Dev alpha 0.1", Vec2<float>(width, height));
    SDL_Renderer* renderer = SDL_CreateRenderer(window.Get(), NULL);
    if(renderer == NULL) {
        std::cout << "Renderer: " << SDL_GetError() << std::endl; 
    }
    SceneManager::GetInstance()->setRenderer(renderer);
    SceneManager::GetInstance()->setCurrentScene(new EntryScene());
    Camera* camera = new Camera(Vec2<float>(0,0), Vec2<float>(width,height));
    SceneManager::GetInstance()->camera = camera;

    auto lastTime = std::chrono::high_resolution_clock::now();

    
    Editor editor;
    editor.Init();



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
        // Update Everything here
        camera->Update(deltaTime);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255,255);
        SDL_RenderClear(renderer);
            SceneManager::GetInstance()->Update(deltaTime);
            editor.Update(deltaTime);
            SceneManager::GetInstance()->Draw();
            editor.Draw();
        SDL_RenderPresent(renderer);

        }
    }
    SceneManager::GetInstance()->Destroy();
    delete camera;

    return 0;
}