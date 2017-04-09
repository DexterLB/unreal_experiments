#pragma once

#include <memory>
using std::shared_ptr;

#include "../component.h"

class FRenderableComponent : public IComponent, public IBaseComponent {
public:
    void Update(float deltaMs);

    unique_ptr<IComponent> Instantiate(FObjectID objectID, FWorld* world);
    static unique_ptr<FRenderableComponent> Make(const string& argument);

    int Priority();
private:
    FObjectID objectID;
    FWorld* world;
};
