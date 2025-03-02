#pragma once
#include "Scene.hpp"
#include "../pch.hpp"

class EntryScene : public Scene {
public:
    EntryScene() {};
    ~EntryScene() {};
    KAI_API void Init() override;
    KAI_API void Update(float deltaTime) override;
    KAI_API void Draw() override;
    KAI_API void Destroy() override;
};