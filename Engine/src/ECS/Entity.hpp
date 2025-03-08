#pragma once

#include <iostream>
#include <unordered_map>
#include <Math/Vec2.hpp>
#include <SDL3/SDL.h>
#include <pybind11/pybind11.h>
#include "./Components/Component.hpp"
namespace py = pybind11;

class Entity{
    public:
        unsigned int id;
        Entity(){
            static unsigned int nextId = 0;
            this->id = nextId++;
        }
};

unsigned int getComponentId() {
    static unsigned int nextId = 0;
    return nextId++;
}

template<typename T>
unsigned int componentID() {
    static unsigned int id = getComponentId();
    return id;
}

class EntityManager {
public:
    std::unordered_map<unsigned int, std::unordered_map<unsigned int,Component*>> entities;
public:
    template<typename T, typename... Args>
    void AddComponent(unsigned int id, Args&&... args) {
        entities[id][componentID<T>()] = new T(std::forward<Args>(args)...);
    }

    template<typename T>
    T* GetComponent(unsigned int id) {
        // Retrieve the first component of type T
         if (!HasComponent<T>(id)) {
            return nullptr; // Return nullptr if no component of type T is found
        }
        return static_cast<T*>(entities[id][componentID<T>()]);
    }

    template<typename T>
    bool HasComponent(unsigned int id) {
        return entities[id].find(componentID<T>()) != entities[id].end();
    }
    ~EntityManager() {
        for (auto& entity : entities) {
            for (auto& component : entity.second) {
                delete component.second;
            }
        }
    }
};