#pragma once

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <memory>
using std::unique_ptr;

#include "object.h"
#include "component.h"
#include "base_component.h"
#include "world_impl.h"

class IComponent;
class IBaseComponent;
class FObject;

class FClass {
    public:
        FClass();
        FClass(const string& name);
        FClass(const FClass&) = delete;
        FClass& operator=(const FClass&) = delete;
        const string& Name() const;
        void AddComponent(unique_ptr<IBaseComponent> component);
        void Initialise();

        vector< unique_ptr<IComponent> > MakeComponents(FObject* object);

    private:
        string name;
        vector< unique_ptr<IBaseComponent> > components;
};
