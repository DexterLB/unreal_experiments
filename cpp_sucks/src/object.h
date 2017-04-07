#pragma once

#include <string>
using std::string;

class FClass;
class FWorld;

#include "base_object.h"
#include "world_impl.h"

class FObject {
    public:
        FObject(FClass* klass, const string& name);
        const FClass& Class() const;
        const string& Name() const;

        void Update(float deltaMs, FWorld& world);
    private:
        FClass* klass;  // maybe some kind of smart pointer?
        string name;
};
