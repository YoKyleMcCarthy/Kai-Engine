// ScriptSystem.hpp
#pragma once
#include "../Entity.hpp"
#include "System.hpp"
#include "../Components/Script.hpp"

class ScriptSystem : public System {
public:
    void Update(EntityManager& manager, float deltaTime) override {
        for (auto& [id, components] : manager.entities) {
            if (manager.HasComponent<Script>(id)) {
                Script* script = manager.GetComponent<Script>(id);
                if (script) {
                    script->Update(deltaTime);
                }
            }
        }
    }
};
