#include <iostream>
using std::cout;
using std::endl;

#include <memory>
using std::shared_ptr;
using std::make_shared;

#include "jumpable.h"
#include "../argument_parser.h"

FJumpableComponent::FJumpableComponent(float _height, float _time, float _delay)
    : height(_height), time(_time), delay(_delay) {
}

void FJumpableComponent::Update(float deltaMs, FObject& object, FWorld& world) {
    cout << "update jump: " << this->height << " " << this->time << " " << this->delay << endl;
}

shared_ptr<FJumpableComponent> FJumpableComponent::Make(const string& argument) {
    auto arguments = ParseStringArguments(argument);

    float height = stof(arguments[0]);
    float time = stof(arguments[1]);
    float delay = stof(arguments[2]);
    // segfault on wrong number of arguments, wooooo

    cout << "create jumpable" << endl;
    return make_shared<FJumpableComponent>(height, time, delay);
}
