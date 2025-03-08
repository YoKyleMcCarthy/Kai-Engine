#pragma once
#include "../Entity.hpp"

class System {
public:
    virtual void Update(EntityManager& manager, float deltaTime) = 0;
};