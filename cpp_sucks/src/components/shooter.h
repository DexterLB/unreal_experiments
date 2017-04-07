#pragma once

#include "../component.h"

class FShooterComponent : public IComponent {
public:
    FShooterComponent(float height, float time, float delay);
    void Update(float deltaMs, FObject& object, FWorld& world);

    unique_ptr<IComponent> Clone();
    static unique_ptr<FShooterComponent> Make(const string& argument);
private:
    float height;
    float time;
    float delay;
};
