#pragma once

#include <memory>
using std::unique_ptr;

#include "object.h"
#include "world_impl.h"

class FObject;

class IComponent {
public:
    virtual void Update(float deltaMs) = 0;

    virtual ~IComponent() {};
};
