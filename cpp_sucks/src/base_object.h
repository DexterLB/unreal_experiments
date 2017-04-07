#pragma once

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <memory>
using std::shared_ptr;

#include "object.h"
#include "component.h"
#include "world_impl.h"

class IComponent;
class FObject;

class FClass {
    public:
        FClass();
        FClass(const string& name);
        const string& Name() const;
        void AddComponent(shared_ptr<IComponent> component);
        void Initialise();

        void Update(float deltaMs, FObject& object, FWorld& world);
    private:
        string name;
        vector< shared_ptr<IComponent> > components;
};
