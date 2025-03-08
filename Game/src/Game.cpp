
#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3/SDL_image.h>
#include <Scene/EntryScene.hpp>
#include <Asset/AssetManager.hpp>
#include <Asset/Texture.hpp>
#include <Util/Timer.hpp>
#include "world/World.hpp"
#include <ECS/Entity.hpp>
#include <Pybind11/embed.h>
#include <ECS/Components/Script.hpp>
#include <ECS/Systems/ScriptSystem.hpp>

Timer timer;
EntityManager manager;
ScriptSystem scriptSystem;

void EntryScene::Init() {
    std::cout << "Game initalized" << std::endl;
    AssetManager::GetInstance()->LoadAsset("./Assets/images/Box.png", AssetType::Texture, "Background");
    auto enemy = Entity();
    manager.AddComponent<Script>(enemy.id, "Enemy");

    auto player = Entity();
    manager.AddComponent<Script>(player.id, "Player");
}

void EntryScene::Update(float deltaTime) {
    //if(timer.GetTimeInSeconds() > 3) {
    //    timer.Stop();
    //    SceneManager::GetInstance()->setCurrentScene(new World());
    //}
    scriptSystem.Update(manager, deltaTime);

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