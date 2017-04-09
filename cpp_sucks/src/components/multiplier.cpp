#include <iostream>
using std::cout;
using std::endl;

#include <memory>
using std::shared_ptr;
using std::make_unique;

#include <string>
using std::string;
using std::to_string;

#include <unordered_map>
using std::unordered_map;

#include <cmath>

#include "multiplier.h"
#include "../argument_parser.h"

FMultiplierComponent::FMultiplierComponent(const vector< pair<int, int> >& _mushroomLocations)
    : mushroomLocations(_mushroomLocations) {

}

unique_ptr<FMultiplierComponent> FMultiplierComponent::Make(const string& argument) {
    vector< pair<int, int> > mushroomLocations;

    // parse them

    return make_unique<FMultiplierComponent>(mushroomLocations);
}

unique_ptr<IComponent> FMultiplierComponent::Instantiate(FObjectID objectID, FWorld* world) {
    auto instance = make_unique<FMultiplierComponentInstance>(objectID, world, &this->mushroomLocations);

    return instance;
}


FMultiplierComponentInstance::FMultiplierComponentInstance(FObjectID _objectID, FWorld* _world, vector< pair<int, int> >* _mushroomLocations)
    : objectID(_objectID), world(_world), mushroomLocations(_mushroomLocations) {

}

void FMultiplierComponentInstance::Update(float deltaMs, FWorld& world) {
}

