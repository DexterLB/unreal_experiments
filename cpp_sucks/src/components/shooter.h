#pragma once

#include "../component.h"

class FShooterComponent : public IComponent {
public:
    FShooterComponent(float height, float time, float delay);
    void Update(float deltaMs, FObject& object, FWorld& world);

    static shared_ptr<FShooterComponent> Make(const string& argument);
private:
    float height;
    float time;
    float delay;
};
