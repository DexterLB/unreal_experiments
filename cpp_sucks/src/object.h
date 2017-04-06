#pragma once

#include <string>
using std::string;

#include "base_object.h"

class FClass;

class FObject {
    public:
        FObject(FClass* klass, const string& name);
        const FClass& Class() const;
        const string& Name() const;

        void Update(float deltaMs);
    private:
        FClass* klass;  // maybe some kind of smart pointer?
        string name;
};
