#pragma once

#include "../component.h"

class FJumpableComponent : public IComponent {
public:
    FJumpableComponent(float height, float time, float delay);
    void Update(float deltaMs, FObject& object, FWorld& world);

    unique_ptr<IComponent> Clone();
    static unique_ptr<FJumpableComponent> Make(const string& argument);
private:
    float height;
    float time;
    float delay;
};
