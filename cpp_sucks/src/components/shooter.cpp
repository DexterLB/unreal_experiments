#include <iostream>
using std::cout;
using std::endl;

#include <memory>
using std::shared_ptr;
using std::make_unique;

#include "shooter.h"
#include "../argument_parser.h"

FShooterComponent::FShooterComponent(float _height, float _time, float _delay)
    : height(_height), time(_time), delay(_delay) {
}

void FShooterComponent::Update(float deltaMs, FObject& object, FWorld& world) {
    cout << "update jump: " << this->height << " " << this->time << " " << this->delay << endl;
}

unique_ptr<FShooterComponent> FShooterComponent::Make(const string& argument) {
    auto arguments = ParseStringArguments(argument);

    float height = stof(arguments[0]);
    float time = stof(arguments[1]);
    float delay = stof(arguments[2]);
    // segfault on wrong number of arguments, wooooo

    cout << "create shooter" << endl;
    return make_unique<FShooterComponent>(height, time, delay);
}

unique_ptr<IComponent> FShooterComponent::Clone() {
    return make_unique<FShooterComponent>(*this);
}
