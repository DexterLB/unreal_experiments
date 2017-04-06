#pragma once

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <memory>
using std::shared_ptr;

#include "object.h"
#include "component.h"

class IComponent;
class FObject;

class FClass {
    public:
        FClass();
        FClass(const string& name);
        const string& Name() const;

        void Update(float deltaMs, FObject& object);
    private:
        string name;
        vector< shared_ptr<IComponent> > components;
};
