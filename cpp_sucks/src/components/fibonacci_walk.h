#pragma once

#include "../component.h"

class FFibonacciWalkComponent : public IComponent, public IBaseComponent {
public:
    FFibonacciWalkComponent(int maxFibIndex, float sleepInterval, float sleepDuration);
    void Update(float deltaMs);

    static unique_ptr<FFibonacciWalkComponent> Make(const string& argument);
    unique_ptr<IComponent> Instantiate(FObjectID objectID, FWorld* world);
private:
    FObjectID objectID;
    FWorld* world;

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
