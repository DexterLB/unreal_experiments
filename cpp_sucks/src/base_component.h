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

    virtual unique_ptr<IComponent> Instantiate(FObject* object) = 0;

    virtual ~IBaseComponent() {};
};
