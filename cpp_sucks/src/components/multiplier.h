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
    FMultiplierComponent(const vector< pair<int, int> >& mushroomLocations);

    static unique_ptr<FMultiplierComponent> Make(const string& argument);
    unique_ptr<IComponent> Instantiate(FObjectID objectID, FWorld* world);
private:
    vector< pair<int, int> > mushroomLocations;
};

class FMultiplierComponentInstance : public IComponent {
public:
    FMultiplierComponentInstance(FObjectID objectID, FWorld* world, vector< pair<int, int> >* mushroomLocations);
    void Update(float deltaMs, FWorld& world);

private:
    FObjectID objectID;
    FWorld* world;

    vector< pair<int, int> >* mushroomLocations;
};
