#pragma once

#include "../component.h"

class FJumpableComponent : public IComponent {
public:
    FJumpableComponent(float height, float time, float delay);
    void Update(float deltaMs, FObject& object);

private:
    float height;
    float time;
    float delay;
};
