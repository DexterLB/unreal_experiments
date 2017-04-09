#pragma once

#include "../component.h"

class FFibonacciWalkComponent : public IComponent, public IBaseComponent {
public:
    FFibonacciWalkComponent(int maxFibIndex, float sleepInterval, float sleepDuration);
    void Update(float deltaMs, FWorld& world);

    static unique_ptr<FFibonacciWalkComponent> Make(const string& argument);
    unique_ptr<IComponent> Instantiate(FObject* object);
private:
    FObject* object;

    // constant values for all instances
    int maxFibIndex;
    float sleepInterval;
    float sleepDuration;

    // precomputed values
    float period;

    // always changing values
    float elapsed_in_period;
    int fib[2];
    int frameIndex;
};
