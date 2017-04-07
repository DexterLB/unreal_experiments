#include <iostream>
using std::cout;
using std::endl;

#include <memory>
using std::shared_ptr;
using std::make_shared;

#include "renderable.h"

void FRenderableComponent::Update(float deltaMs, FObject& object, FWorld& world) {
    cout << "update render" << endl;
}

shared_ptr<FRenderableComponent> FRenderableComponent::Make(const string& argument) {
    return make_shared<FRenderableComponent>();
}
