
#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3/SDL_image.h>
#include <Scene/EntryScene.hpp>
#include <Asset/AssetManager.hpp>
#include <Asset/Texture.hpp>
#include <Util/Timer.hpp>
#include "world/World.hpp"

Timer timer;

void EntryScene::Init() {
    std::cout << "Game initalized" << std::endl;
    AssetManager::GetInstance()->LoadAsset("./Assets/images/Box.png", AssetType::Texture, "Background");
}

void EntryScene::Update(float deltaTime) {
    if(timer.GetTimeInSeconds() > 3) {
        timer.Stop();
        SceneManager::GetInstance()->setCurrentScene(new World());
    }
}

void EntryScene::Draw() {
    SDL_RenderTexture(SceneManager::GetInstance()->getRenderer(), dynamic_cast<Texture*>(AssetManager::GetInstance()->asset("Background"))->Get(), NULL, NULL);
}

void EntryScene::Destroy() {
    if(AssetManager::GetInstance()->UnloadAsset("Background")) {
        std::cout << "No issues removing asset \n";
    } else {
        std::cout << "Well shit something went wrong" << std::endl;
    }
}