#include <iostream>
using std::cout;
using std::endl;

#include <memory>
using std::shared_ptr;
using std::make_unique;

#include "multiplier.h"
#include "../argument_parser.h"

FMultiplierComponent::FMultiplierComponent(float _height, float _time, float _delay)
    : height(_height), time(_time), delay(_delay) {
}

void FMultiplierComponent::Update(float deltaMs, FObject& object, FWorld& world) {
    cout << "update jump: " << this->height << " " << this->time << " " << this->delay << endl;
}

unique_ptr<FMultiplierComponent> FMultiplierComponent::Make(const string& argument) {
    auto arguments = ParseStringArguments(argument);

    float height = stof(arguments[0]);
    float time = stof(arguments[1]);
    float delay = stof(arguments[2]);
    // segfault on wrong number of arguments, wooooo

    cout << "create multiplier" << endl;
    return make_unique<FMultiplierComponent>(height, time, delay);
}

unique_ptr<IComponent> FMultiplierComponent::Clone() {
    return make_unique<FMultiplierComponent>(*this);
}
