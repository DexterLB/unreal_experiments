#include <iostream>
using std::cout;
using std::endl;

#include <memory>
using std::shared_ptr;
using std::make_unique;

#include "renderable.h"

void FRenderableComponent::Update(float deltaMs, FObject& object, FWorld& world) {
    cout << "update render" << endl;
}

unique_ptr<FRenderableComponent> FRenderableComponent::Make(const string& argument) {
    return make_unique<FRenderableComponent>();
}

unique_ptr<IComponent> FRenderableComponent::Clone() {
    return make_unique<FRenderableComponent>(*this);
}
