#include "World.hpp"

void World::Init() {
    std::cout << "World Initialized" << std::endl;
}

void World::Update(float deltaTime) {
    std::cout << "World Updated" << std::endl;
}

void World::Draw() {
    std::cout << "World Drawn" << std::endl;
}

void World::Destroy() {
    std::cout << "World Destroyed" << std::endl;
}

// Compare this snippet from Game/src/world/World.cpp: