#pragma once

#include "../component.h"

class FJumpableComponent : public IComponent, public IBaseComponent {
public:
    FJumpableComponent(float height, float time, float delay);
    void Update(float deltaMs, FWorld& world);

    static unique_ptr<FJumpableComponent> Make(const string& argument);
    unique_ptr<IComponent> Instantiate(FObject* object);
private:
    float height;
    float time;
    float delay;
    FObject* object;
};
