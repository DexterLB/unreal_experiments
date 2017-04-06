#include "object.h"

#include <iostream>
using std::cout;
using std::endl;

FObject::FObject(FClass* klass, const string& name) {
    this->klass = klass;
    this->name = name;
}

const FClass& FObject::Class() const {
    return *(this->klass);
}

const string& FObject::Name() const {
    return this->name;
}

void FObject::Update(float deltaMs) {
    this->klass->Update(deltaMs, *this);
    cout << this->klass->Name() << " " << this->Name() << " updated for " << deltaMs << "ms." << endl;
}
