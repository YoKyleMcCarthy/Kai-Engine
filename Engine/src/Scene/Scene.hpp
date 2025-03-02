#pragma once

class Scene {
public:
    Scene() {};
    ~Scene() {};
    virtual void Init() = 0;
    virtual void Update(float deltaTime) = 0;
    virtual void Draw() = 0;
    virtual void Destroy() = 0;
};