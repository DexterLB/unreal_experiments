#include "event_bus.h"

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

class FooEvent: public IEvent {
public:
    FooEvent(int _foo) : foo(_foo) {};
    int foo;
};

class BarEvent: public IEvent {
public:
    BarEvent(string _bar) : bar(_bar) {};
    string bar;
};

void EventTest() {
    FEventBus eb;

    eb.Register<FooEvent>();
    eb.Subscribe<FooEvent>([](const FooEvent& event) {
        cout << "received event: " << event.foo << endl;
    });

    eb.Register<BarEvent>();
    eb.Subscribe<BarEvent>([](const BarEvent& event) {
        cout << "received bar: " << event.bar << endl;
    });

    eb.Emit<FooEvent>(FooEvent(42));
    eb.Emit<BarEvent>(BarEvent("answer"));

    eb.Subscribe<BarEvent>([](const BarEvent& event) {
        cout << "received barbar: " << event.bar << endl;
    });

    eb.Emit<FooEvent>(FooEvent(50));
    eb.Emit<BarEvent>(BarEvent("answer2"));
}
