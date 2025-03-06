#include "SceneManager.hpp"

SceneManager* SceneManager::instance = nullptr;

SceneManager::SceneManager() {
    currentScene = nullptr;
    globalScene = nullptr;
}

void SceneManager::Update(float deltaTime) {
    // if(hasGlobalScene && globalScene != nullptr || globalScene != currentScene) {
    //     globalScene->Update(deltaTime);
    // } 
    if(currentScene != nullptr) currentScene->Update(deltaTime); else { ERROR("No Scene to Update"); }
    
}

SceneManager* SceneManager::GetInstance() {
    if(instance == nullptr) {
        instance = new SceneManager();
    }
    return instance;
}

void SceneManager::setRenderer(SDL_Renderer* renderer) {
    this->renderer = renderer;
}

void SceneManager::setCurrentScene(Scene* newScene) {
    if(currentScene != nullptr) {
        currentScene->Destroy();
        delete currentScene;
    }
    currentScene = newScene;
    currentScene->prepare(renderer);
    currentScene->Init();
}

void SceneManager::setGlobalScene(Scene* scene) {
    Scene* oldScene = globalScene;
    globalScene = scene;
    oldScene->Destroy();
    delete oldScene;
    globalScene->Init();
    globalScene = scene;
}

void SceneManager::Destroy() {
    if(currentScene != nullptr) {
        currentScene->Destroy();
        delete currentScene;
    }
    if(globalScene != nullptr) {
        globalScene->Destroy();
        delete globalScene;
    }
    delete instance;
    instance = nullptr;
    currentScene = nullptr;
    globalScene = nullptr;
}

void SceneManager::Draw() {
    currentScene->Draw();
}