#include <iostream>
using std::cout;
using std::endl;

#include <memory>
using std::shared_ptr;
using std::make_unique;

#include "renderable.h"

void FRenderableComponent::Update(float deltaMs, FWorld& world) {
    cout << "update render" << endl;
}

unique_ptr<FRenderableComponent> FRenderableComponent::Make(const string& argument) {
    return make_unique<FRenderableComponent>();
}

unique_ptr<IComponent> FRenderableComponent::Instantiate(FObject* object) {
    auto instance = make_unique<FRenderableComponent>(*this);
    instance->object = object;
    return instance;
}
