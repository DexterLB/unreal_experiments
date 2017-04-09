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

#include "shooter.h"
#include "../argument_parser.h"

FShooterComponent::FShooterComponent(const string& _projectile, float _interval)
    : projectile(_projectile), interval(_interval * 1000) {

    this->elapsed_in_period = 0;
}

void FShooterComponent::Update(float deltaMs, FWorld& world) {
    int times_shot = int((this->elapsed_in_period + deltaMs) / this->interval);
    this->elapsed_in_period = fmod(this->elapsed_in_period + deltaMs, this->interval);

    for (int i = 0; i < times_shot; i++) {
        this->Shoot();
    }
}

void FShooterComponent::Shoot() {
    // this is kinda evil (to make it properly it should be somehow tied
    // to the FWorld instance). Also the string key is inefficient, should
    // be something smarter.
    static unordered_map<string, int> projectileCounters;

    projectileCounters[this->projectile]++;

    string name = this->projectile + to_string(projectileCounters[this->projectile]);

    this->world->SpawnObject(this->projectile, name);
}

unique_ptr<FShooterComponent> FShooterComponent::Make(const string& argument) {
    auto arguments = ParseStringArguments(argument);

    string projectile = arguments[0];
    float interval = stof(arguments[1]);
    // segfault on wrong number of arguments, wooooo

    return make_unique<FShooterComponent>(projectile, interval);
}

unique_ptr<IComponent> FShooterComponent::Instantiate(FObjectID objectID, FWorld* world) {
    auto instance = make_unique<FShooterComponent>(*this);
    instance->objectID = objectID;
    instance->projectileClass = world->GetClass(this->projectile);
    instance->world = world;

    return instance;
}
