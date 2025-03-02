#pragma once
#include "Scene.hpp"
#include "../Camera/Camera.hpp"
class SceneManager {
private:
    static SceneManager* instance;
    Scene* currentScene;
    Scene* globalScene;
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

    void Update(float deltaTime);
    void Destroy();
    void Draw();
};