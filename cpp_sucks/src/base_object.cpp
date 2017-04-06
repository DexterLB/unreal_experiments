#include "base_object.h"

FClass::FClass() {
    this->name = "";
}

FClass::FClass(const string& name) {
    this->name = name;
}

const string& FClass::Name() const {
    return this->name;
}

void FClass::Update(float deltaMs, FObject& object) {
    for (auto & component: this->components) {
        component->Update(deltaMs, object);
    }
}
