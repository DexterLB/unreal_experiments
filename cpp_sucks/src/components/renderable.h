#pragma once

#include <memory>
using std::shared_ptr;

#include "../component.h"

class FRenderableComponent : public IComponent, public IBaseComponent {
public:
    void Update(float deltaMs, FWorld& world);

    unique_ptr<IComponent> Instantiate(FObject* object);
    static unique_ptr<FRenderableComponent> Make(const string& argument);

    int Priority();
private:
    FObject* object;
};
