
#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3/SDL_image.h>
#include <Scene/EntryScene.hpp>
#include <Asset/AssetManager.hpp>
#include <Asset/Texture.hpp>


void EntryScene::Init() {
    std::cout << "Game initalized" << std::endl;
    AssetManager::GetInstance()->LoadAsset("./Assets/images/Box.png", AssetType::Texture, "Background");
}

void EntryScene::Update(float deltaTime) {

}

void EntryScene::Draw() {
    std::cout << "Drawing" << std::endl;
    SDL_RenderTexture(SceneManager::GetInstance()->getRenderer(), static_cast<Texture*>(AssetManager::GetInstance()->asset("Background"))->Get(), NULL, NULL);
}

void EntryScene::Destroy() {
    
}