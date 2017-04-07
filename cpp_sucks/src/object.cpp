#include "object.h"

FObject::FObject(FClass* klass, const string& name) {
    this->klass = klass;
    this->name = name;
    this->components = klass->MakeComponents(this);
}

const FClass& FObject::Class() const {
    return *(this->klass);
}

const string& FObject::Name() const {
    return this->name;
}

void FObject::Update(float deltaMs, FWorld& world) {
    for (auto& component: this->components) {
        component->Update(deltaMs, world);
    }
}

void FObject::SetX(float location) {
    this->x = location;
    this->moved();
}

void FObject::MoveX(float locationOffset) {
    this->x += locationOffset;
    this->moved();
}

float FObject::X() {
    return this->x;
}

void FObject::SetY(float height) {
    this->y = height;
    this->moved();
}

void FObject::MoveY(float heightOffset) {
    this->y += heightOffset;
    this->moved();
}

float FObject::Y() {
    return this->y;
}

void FObject::moved() {
    this->EventBus.Emit<FObjectMovedEvent>(FObjectMovedEvent(this->x, this->y));
}
