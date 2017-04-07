#pragma once

#include "../component.h"

class FJumpableComponent : public IComponent {
public:
    FJumpableComponent(float height, float time, float delay);
    void Update(float deltaMs, FObject& object);

    static shared_ptr<FJumpableComponent> Make(const string& argument);
private:
    float height;
    float time;
    float delay;
};
