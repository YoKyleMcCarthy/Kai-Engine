#pragma once
#include "Scene.hpp"
#include "../Camera/Camera.hpp"
class SceneManager {
private:
    static SceneManager* instance;
    Scene* currentScene;
    Scene* globalScene;
    SDL_Renderer* renderer;
protected:
    SceneManager();
public:
    Camera* camera;
    bool hasGlobalScene = false;
    SceneManager(const SceneManager&) = delete;
    SceneManager& operator=(const SceneManager&) = delete;
    static SceneManager* GetInstance();

    void setCurrentScene(Scene* scene);
    void setGlobalScene(Scene* scene);
    void setRenderer(SDL_Renderer* renderer);
    KAI_INLINE Scene* getCurrentScene() { return currentScene; }
    KAI_INLINE Scene* getGlobalScene() { return globalScene; }
    KAI_INLINE SDL_Renderer* getRenderer() { return renderer; }

    void Update(float deltaTime);
    void Destroy();
    void Draw();
};