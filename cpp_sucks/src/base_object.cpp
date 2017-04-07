#include <algorithm>
using std::remove_if;

#include <iostream>
#include <memory>
using std::make_unique;

#include "component.h"
#include "base_object.h"

FClass::FClass() {
    this->name = "";
}

FClass::FClass(const string& name) {
    this->name = name;
}

const string& FClass::Name() const {
    return this->name;
}

vector< unique_ptr<IComponent> > FClass::MakeComponents(FObject* object) {
    vector< unique_ptr<IComponent> > components;
    for (auto& component: this->components) {
        // copying seems to be the most straight-forward way to construct
        // "instances" of components
        components.push_back(move(component->Instantiate(object)));
    }
    return components;
}

void FClass::AddComponent(unique_ptr<IBaseComponent> component) {
    this->components.push_back(move(component));
}

void FClass::Initialise() {
    // sort components by priority
    sort(
        this->components.begin(),
        this->components.end(),
        [](const auto& a, const auto& b) { return a->Priority() < b->Priority(); }
    );
}
