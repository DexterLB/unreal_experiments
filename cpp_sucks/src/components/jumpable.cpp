#include <iostream>
using std::cout;
using std::endl;

#include <memory>
using std::shared_ptr;
using std::make_unique;

#include <cmath>

#include "jumpable.h"
#include "../argument_parser.h"

FJumpableComponent::FJumpableComponent(float _height, float _time, float _delay)
    : height(_height), time(_time * 1000), delay(_delay * 1000) {

    this->jump_speed = this->height / this->time;
    this->period = 2 * this->time + this->delay;
    this->elapsed_in_period = 0;
}

void FJumpableComponent::Update(float deltaMs, FWorld& world) {
    this->elapsed_in_period = fmod(this->elapsed_in_period + deltaMs, this->period);

    if (this->elapsed_in_period > 2 * this->time) {
        // sleeping between two jumps
        this->object->SetY(0);
        return;
    }

    if (this->elapsed_in_period < this->time) {
        // going up
        this->object->SetY(this->elapsed_in_period * this->jump_speed);
    } else {
        // going down
        float time_since_peak = this->elapsed_in_period - this->time;
        this->object->SetY(this->height - (this->jump_speed * time_since_peak));
    }
}

unique_ptr<FJumpableComponent> FJumpableComponent::Make(const string& argument) {
    auto arguments = ParseStringArguments(argument);

    float height = stof(arguments[0]);
    float time = stof(arguments[1]);
    float delay = stof(arguments[2]);
    // segfault on wrong number of arguments, wooooo

    return make_unique<FJumpableComponent>(height, time, delay);
}

unique_ptr<IComponent> FJumpableComponent::Instantiate(FObject* object) {
    auto instance = make_unique<FJumpableComponent>(*this);
    instance->object = object;
    return instance;
}
