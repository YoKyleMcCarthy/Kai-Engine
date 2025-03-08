#include "pch.hpp"
#include <Python/Python.h>
#include <Pybind11/embed.h>
#include <Pybind11/pybind11.h>
#include <Math/Math.hpp>

#include <iostream>
#include <chrono>

#include <Scene/SceneManager.hpp>
#include <Scene/EntryScene.hpp>
#include <Asset/AssetManager.hpp>
#include <Window/Window.hpp>
#include <Camera/Camera.hpp>
#include <SDL3/SDL.h>
#include <Editor/Editor.hpp>
#include <enet/enet.h>

namespace py = pybind11;

#include "Entry.hpp"

void Entry::Init() {
    // Init all Script modules
    InitModules();    
}

// Intializes all Embeded Modules needed for Scripting languages
void Entry::InitModules() {
    Math::InitVec2(); // Inits Vec2 modules for python ** In Future Lua as well **

}


void Entry::Run() {

    py::scoped_interpreter guard{};
    py::print("[Python] Hello, C++!");
    Init();


    
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
    const int width = 1080;
    const int height = 720;
    window = new Window("Engine Dev alpha 0.1", Vec2<float>(width, height));
    SDL_Renderer* renderer = SDL_CreateRenderer(window->Get(), NULL);
    if(renderer == NULL) {
        std::cout << "Renderer: " << SDL_GetError() << std::endl; 
    }
    SceneManager::GetInstance()->setRenderer(renderer);
    SceneManager::GetInstance()->setCurrentScene(new EntryScene());
    Camera* camera = new Camera(Vec2<float>(0,0), Vec2<float>(width,height));
    SceneManager::GetInstance()->camera = camera;

    lastTime = std::chrono::high_resolution_clock::now();

    editor.Init();

    

    while(window->isOpen) {
        currentTime = std::chrono::high_resolution_clock::now();
        deltaTime = std::chrono::duration<float, std::chrono::seconds::period>(currentTime - lastTime).count();
        lastTime = currentTime;

        EventManager(event);
        Update(deltaTime);
        Render();
    }

}

void Entry::EventManager(SDL_Event& event) {
    while(SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_EVENT_QUIT:
                window->Close();
                break;
            case SDL_EVENT_WINDOW_RESIZED:
                window->resize();
                SceneManager::GetInstance()->camera->size = window->windowSize;
        }
    }
}


void Entry::Update(float deltaTime) {
    // Update Everything here
    SceneManager::GetInstance()->camera->Update(deltaTime);
    SDL_SetRenderDrawColor(SceneManager::GetInstance()->getRenderer(), 255, 255, 255,255);
    SDL_RenderClear(SceneManager::GetInstance()->getRenderer());
        SceneManager::GetInstance()->Update(deltaTime);
        editor.Update(deltaTime);
}

void Entry::Render() {
    SceneManager::GetInstance()->Draw();
    editor.Draw();
    SDL_RenderPresent(SceneManager::GetInstance()->getRenderer());
}

Entry::~Entry() {
    SceneManager::GetInstance()->Destroy();
    delete SceneManager::GetInstance()->camera;
    delete window;
}





int main() {
    Entry* entry = new Entry();
    entry->Run();
    delete entry;
    return 0;
}