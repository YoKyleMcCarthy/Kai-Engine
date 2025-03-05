#pragma once
#include <SDL3/SDL.h>
class Scene {
protected:
    SDL_Renderer* renderer;
public:
    Scene() {};
    ~Scene() {};
    void prepare(SDL_Renderer* renderer) {
        this->renderer = renderer;
    }
    virtual void Init() = 0;
    virtual void Update(float deltaTime) = 0;
    virtual void Draw() = 0;
    virtual void Destroy() = 0;
};