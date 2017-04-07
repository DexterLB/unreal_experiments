#pragma once

#include <functional>
using std::function;

#include <unordered_map>
using std::unordered_map;

#include <vector>
using std::vector;

#include <typeinfo>
using std::type_info;

#include <typeindex>
using std::type_index;

class IEvent {
public:
    virtual ~IEvent() {};
};

// here be dragons

class FEventBus {
public:
    template <typename T>
    void Register() {
        this->shit[type_index(typeid(T))];
    };

    template <typename T>
    void Subscribe(function<void (const T&)> f) {
        auto t = type_index(typeid(T));
        if (this->shit.find(t) != this->shit.end()) {
            this->shit[t].push_back(
                [f](const IEvent& event) {
                    f(dynamic_cast<const T&>(event));
                }
            );
        }
    };

    template <typename T>
    void Emit(const T& event) {
        for (const auto& f :  this->shit[type_index(typeid(T))]) {
            f(dynamic_cast<const IEvent&>(event));
        }
    }
private:
    unordered_map< type_index, vector< function< void (const IEvent&) > > > shit;
};
