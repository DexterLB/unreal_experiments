#pragma once

#include "object.h"
#include "world_impl.h"

class FObject;

class IComponent {
public:
    virtual void Update(float deltaMs, FObject& object, FWorld& world) = 0;
    virtual int Priority();

    ~IComponent() {};
};
