#include "object.h"

FObject::FObject(FWorld* world, FClass* klass, FObjectID id, const string& name) {
    this->name = name;
    this->id = id;
    this->components = klass->MakeComponents(this->id, world);
    this->EventBus.Register<FObjectMovedEvent>();

    this->x = 0;
    this->y = 0;
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
