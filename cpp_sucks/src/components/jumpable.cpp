#include <iostream>
using std::cout;
using std::endl;

#include "jumpable.h"

FJumpableComponent::FJumpableComponent(float _height, float _time, float _delay)
    : height(_height), time(_time), delay(_delay) {
}

void FJumpableComponent::Update(float deltaMs, FObject& object) {
    cout << "update jump: " << this->height << " " << this->time << " " << this->delay << endl;
}
