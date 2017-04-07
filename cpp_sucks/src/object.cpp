#include "object.h"

#include <iostream>
using std::cout;
using std::endl;

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
        cout << component.get() << endl;
        component->Update(deltaMs, world);
    }
}
