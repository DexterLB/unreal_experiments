#pragma once

#include "../component.h"

class FJumpableComponent : public IComponent, public IBaseComponent {
public:
    FJumpableComponent(float height, float time, float delay);
    void Update(float deltaMs);

    static unique_ptr<FJumpableComponent> Make(const string& argument);
    unique_ptr<IComponent> Instantiate(FObjectID objectID, FWorld* world);
private:
    FObjectID objectID;
    FWorld* world;

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
