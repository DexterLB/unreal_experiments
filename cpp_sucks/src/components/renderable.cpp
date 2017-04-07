#include <memory>
using std::shared_ptr;
using std::make_unique;

#include "renderable.h"

void FRenderableComponent::Update(float deltaMs, FWorld& world) {
    world.Log()
        << this->object->Name()
        << " is located at "
        << "("
        << this->object->X()
        << ", "
        << this->object->Y()
        << ")"
        << endl;
}

unique_ptr<FRenderableComponent> FRenderableComponent::Make(const string& argument) {
    return make_unique<FRenderableComponent>();
}

unique_ptr<IComponent> FRenderableComponent::Instantiate(FObject* object) {
    auto instance = make_unique<FRenderableComponent>(*this);
    instance->object = object;
    return instance;
}
