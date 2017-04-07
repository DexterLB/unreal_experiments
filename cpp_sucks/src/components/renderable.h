#pragma once

#include <memory>
using std::shared_ptr;

#include "../component.h"

class FRenderableComponent : public IComponent {
public:
    void Update(float deltaMs, FObject& object, FWorld& world);
    static shared_ptr<FRenderableComponent> Make(const string& argument);
};
