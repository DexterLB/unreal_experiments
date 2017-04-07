#pragma once

#include "../component.h"

class FMultiplierComponent : public IComponent {
public:
    FMultiplierComponent(float height, float time, float delay);
    void Update(float deltaMs, FObject& object, FWorld& world);

    static shared_ptr<FMultiplierComponent> Make(const string& argument);
private:
    float height;
    float time;
    float delay;
};
