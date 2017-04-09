#pragma once

#include <memory>
using std::unique_ptr;

#include "object.h"
#include "world_impl.h"
#include "component.h"

class FObject;
class IComponent;

class IBaseComponent {
public:
    virtual int Priority();

    virtual unique_ptr<IComponent> Instantiate(FObjectID objectID, FWorld* world) = 0;
    virtual void RegisterEvents(FObjectID objectID, FWorld* world) {};

    virtual ~IBaseComponent() {};
};
