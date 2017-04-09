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
#include "multiplier_event.h"
#include "../argument_parser.h"

FMultiplierComponent::FMultiplierComponent(const vector< pair<float, float> >& _mushroomLocations, float _triggerDistance)
    : mushroomLocations(_mushroomLocations), triggerDistance(_triggerDistance) {

}

unique_ptr<FMultiplierComponent> FMultiplierComponent::Make(const string& argument) {
    auto arguments = ParseStringArguments(argument);
    vector< pair<float, float> > mushroomLocations = ParseFloatPairVectorArgument(arguments[0]);
    float triggerDistance = stof(arguments[1]);

    return make_unique<FMultiplierComponent>(mushroomLocations, triggerDistance);
}

unique_ptr<IComponent> FMultiplierComponent::Instantiate(FObjectID objectID, FWorld* world) {
    auto instance = make_unique<FMultiplierComponentInstance>(objectID, world, &this->mushroomLocations, this->triggerDistance);

    return instance;
}

void FMultiplierComponent::RegisterEvents(FObjectID objectID, FWorld* world) {
    world->Object(objectID).EventBus.Register<FMushroomEvent>();
}


FMultiplierComponentInstance::FMultiplierComponentInstance(FObjectID _objectID, FWorld* _world, vector< pair<float, float> >* _mushroomLocations, float _triggerDistance)
    : objectID(_objectID), world(_world), mushroomLocations(_mushroomLocations), triggerDistance(_triggerDistance) {

    this->explodedMushrooms = vector<bool>(mushroomLocations->size(), false);
}

void FMultiplierComponentInstance::Update(float deltaMs, FWorld& world) {
    auto& object = this->world->Object(this->objectID);

    for (size_t i = 0; i < this->mushroomLocations->size(); i++) {
        auto location = (*(this->mushroomLocations))[i];
        float x = location.first;
        float y = location.second;

        if ((x - object.X()) * (x - object.X()) + (y - object.Y()) * (y - object.Y()) < this->triggerDistance * this->triggerDistance && !this->explodedMushrooms[i]) {
            this->explodedMushrooms[i] = true;
            this->world->Log() << "A mushroom exploded!" << endl;
            object.EventBus.Emit<FMushroomEvent>(FMushroomEvent());
        }
    }
}

