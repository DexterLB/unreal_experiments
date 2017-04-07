#pragma once

#include "object.h"

class FObject;

class IComponent {
public:
    virtual void Update(float deltaMs, FObject& object) = 0;
    virtual int Priority();

    ~IComponent() {};
};
