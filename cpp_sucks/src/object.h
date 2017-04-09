#pragma once

#include <string>
using std::string;

class FClass;
class FWorld;

#include "base_object.h"
#include "world_impl.h"
#include "component.h"
#include "event_bus.h"

struct FObjectMovedEvent : public IEvent {
    FObjectMovedEvent(float _x, float _y) : x(_x), y(_y) {};
    float x;
    float y;
};

class FObject {
public:
    FObject(FWorld* world, FClass* klass, FObjectID id, const string& name);
    FObject(const FObject&) = delete;
    FObject& operator=(const FObject&) = delete;

    const FClass& Class() const;
    const string& Name() const;

    void Update(float deltaMs, FWorld& world);

    void SetX(float location);
    void MoveX(float locationOffset);
    float X();

    void SetY(float height);
    void MoveY(float locationOffset);
    float Y();

    void SetLocation(float x, float y);

    FEventBus EventBus;
private:
    string name;
    FObjectID id;
    vector< unique_ptr<IComponent> > components;

    float x;
    float y;

    void moved();
};
