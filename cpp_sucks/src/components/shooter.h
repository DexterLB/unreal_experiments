#pragma once

#include "../component.h"
#include "../base_object.h"

class FShooterComponent : public IComponent, public IBaseComponent {
public:
    FShooterComponent(const string& projectile, float interval);
    void Update(float deltaMs, FWorld& world);

    static unique_ptr<FShooterComponent> Make(const string& argument);
    unique_ptr<IComponent> Instantiate(FObjectID objectID, FWorld* world);
private:
    FObjectID objectID;
    FWorld* world;

    // constant values for all instances
    string projectile;
    float interval;

    // constant values for this instance
    FClass* projectileClass;

    // always changing values
    float elapsed_in_period;

    void Shoot();
};
