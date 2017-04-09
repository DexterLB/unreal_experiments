#pragma once

#include "../component.h"

class FJumpableComponent : public IComponent, public IBaseComponent {
public:
    FJumpableComponent(float height, float time, float delay);
    void Update(float deltaMs, FWorld& world);

    static unique_ptr<FJumpableComponent> Make(const string& argument);
    unique_ptr<IComponent> Instantiate(FObject* object);
private:
    FObject* object;

    // constant values for all instances
    float height;
    float time;
    float delay;

    // precomputed values
    float period;
    float jump_speed;

    // always changing values
    float elapsed_in_period;
};
