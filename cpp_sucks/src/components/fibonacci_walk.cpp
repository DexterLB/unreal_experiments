#include <iostream>
using std::cout;
using std::endl;

#include <memory>
using std::shared_ptr;
using std::make_unique;

#include <cmath>

#include "fibonacci_walk.h"
#include "../argument_parser.h"
#include "multiplier_event.h"

FFibonacciWalkComponent::FFibonacciWalkComponent(int _maxFibIndex, float _sleepInterval, float _sleepDuration)
    : maxFibIndex(_maxFibIndex), sleepInterval(_sleepInterval * 1000), sleepDuration(_sleepDuration * 1000) {

    this->period = this->sleepInterval + this->sleepDuration;
    this->elapsed_in_period = 0;
    this->fib[0] = 1;
    this->fib[1] = 1;
    this->frameIndex = 0;
}

void FFibonacciWalkComponent::Update(float deltaMs) {

    if (this->frameIndex >= this->maxFibIndex) {
        this->frameIndex = 0;
        this->fib[0] = 1;
        this->fib[1] = 1;
    }
    this->frameIndex++;

    float currentFib = this->fib[0];
    this->fib[0] = this->fib[1];
    this->fib[1] += currentFib;

    // calculate sleep
    this->elapsed_in_period = fmod(this->elapsed_in_period + deltaMs, this->period);

    if (this->elapsed_in_period > this->sleepInterval) {
        return;
    }

    this->world->Object(this->objectID).MoveX(currentFib);
}

unique_ptr<FFibonacciWalkComponent> FFibonacciWalkComponent::Make(const string& argument) {
    auto arguments = ParseStringArguments(argument);

    float maxFibIndex = stoi(arguments[0]);
    float sleepInterval = stof(arguments[1]);
    float sleepDuration = stof(arguments[2]);
    // segfault on wrong number of arguments, wooooo

    return make_unique<FFibonacciWalkComponent>(maxFibIndex, sleepInterval, sleepDuration);
}

unique_ptr<IComponent> FFibonacciWalkComponent::Instantiate(FObjectID objectID, FWorld* world) {
    auto instance = make_unique<FFibonacciWalkComponent>(*this);
    instance->objectID = objectID;
    instance->world = world;
    auto& object = world->Object(objectID);

    auto instance_p = instance.get();

    object.EventBus.Subscribe<FMushroomEvent>([instance_p](auto& event) {
        instance_p->maxFibIndex *= 2;
    });

    return instance;
}
