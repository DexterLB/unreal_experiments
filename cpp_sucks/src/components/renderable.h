#pragma once

#include "../component.h"

class FRenderableComponent : public IComponent {
    void Update(float deltaMs, FObject& object);
};
