#pragma once


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
#include <Pybind11/pybind11.h>


class Entry {
    private:
        SDL_Event event;
        std::chrono::steady_clock::time_point lastTime;
        std::chrono::steady_clock::time_point currentTime;
        float deltaTime;
        Window* window;
        Editor editor;
    public:
        void Init();
        void Update(float deltaTime);
        void Render();
        void EventManager(SDL_Event& event);
        void Run();
        void Close();
        void InitModules();
        Entry() {};
        ~Entry();
};