#include <memory>
using std::shared_ptr;
using std::make_unique;

#include "renderable.h"

void FRenderableComponent::Update(float deltaMs) {
    auto& object = this->world->Object(this->objectID);
    this->world->Log()
        << object.Name()
        << " is located at "
        << "("
        << object.X()
        << ", "
        << object.Y()
        << ")"
        << endl;
}

unique_ptr<FRenderableComponent> FRenderableComponent::Make(const string& argument) {
    return make_unique<FRenderableComponent>();
}

unique_ptr<IComponent> FRenderableComponent::Instantiate(FObjectID objectID, FWorld* world) {
    auto instance = make_unique<FRenderableComponent>(*this);
    instance->objectID = objectID;
    instance->world = world;
    return instance;
}

int FRenderableComponent::Priority() {
    return 5;
}
