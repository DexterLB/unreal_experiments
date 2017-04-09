#pragma once

#include <vector>
using std::vector;

#include <utility>
using std::pair;

#include "../component.h"
#include "../base_object.h"

// this is the proper way to make components (the rest are lazy)

class FMultiplierComponent : public IBaseComponent {
public:
    FMultiplierComponent(const vector< pair<float, float> >& mushroomLocations, float triggerDistance);

    static unique_ptr<FMultiplierComponent> Make(const string& argument);
    unique_ptr<IComponent> Instantiate(FObjectID objectID, FWorld* world);
    void RegisterEvents(FObjectID objectID, FWorld* world);

    int Priority() { return 4; }
private:
    vector< pair<float, float> > mushroomLocations;
    float triggerDistance;
};

class FMultiplierComponentInstance : public IComponent {
public:
    FMultiplierComponentInstance(FObjectID objectID, FWorld* world, vector< pair<float, float> >* mushroomLocations, float triggerDistance);
    void Update(float deltaMs);

private:
    FObjectID objectID;
    FWorld* world;

    vector< pair<float, float> >* mushroomLocations;
    vector<bool> explodedMushrooms;

    float triggerDistance;
};
