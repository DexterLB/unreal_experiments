#pragma once

#include "../component.h"

class FFibonacciWalkComponent : public IComponent {
public:
    FFibonacciWalkComponent(float height, float time, float delay);
    void Update(float deltaMs, FObject& object, FWorld& world);

    static shared_ptr<FFibonacciWalkComponent> Make(const string& argument);
private:
    float height;
    float time;
    float delay;
};
