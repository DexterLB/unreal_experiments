#pragma once

#include <string>
using std::string;

class FClass;
class FWorld;

#include "base_object.h"
#include "world_impl.h"
#include "component.h"

class FObject {
    public:
        FObject(FClass* klass, const string& name);
        FObject(const FObject&) = delete;
        FObject& operator=(const FObject&) = delete;

        const FClass& Class() const;
        const string& Name() const;

        void Update(float deltaMs, FWorld& world);

        /*
        void SetX(float location);
        void MoveX(float locationOffset);
        float X();

        void SetY(float height);
        void MoveY(float locationOffset);
        float Y();
        */
    private:
        FClass* klass;  // maybe some kind of smart pointer?
        string name;
        vector< unique_ptr<IComponent> > components;
};
