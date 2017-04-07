#include <iostream>
using std::cout;
using std::endl;

#include <memory>
using std::shared_ptr;
using std::make_unique;

#include "fibonacci_walk.h"
#include "../argument_parser.h"

FFibonacciWalkComponent::FFibonacciWalkComponent(float _height, float _time, float _delay)
    : height(_height), time(_time), delay(_delay) {
}

void FFibonacciWalkComponent::Update(float deltaMs, FObject& object, FWorld& world) {
    cout << "update jump: " << this->height << " " << this->time << " " << this->delay << endl;
}

unique_ptr<FFibonacciWalkComponent> FFibonacciWalkComponent::Make(const string& argument) {
    auto arguments = ParseStringArguments(argument);

    float height = stof(arguments[0]);
    float time = stof(arguments[1]);
    float delay = stof(arguments[2]);
    // segfault on wrong number of arguments, wooooo

    cout << "create fibonacci_walk" << endl;
    return make_unique<FFibonacciWalkComponent>(height, time, delay);
}

unique_ptr<IComponent> FFibonacciWalkComponent::Clone() {
    return make_unique<FFibonacciWalkComponent>(*this);
}
