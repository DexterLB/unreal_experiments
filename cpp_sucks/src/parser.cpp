#include <sstream>
using std::stringstream;

#include <string>
using std::string;
using std::getline;

#include <memory>
using std::unique_ptr;
using std::make_unique;
using std::shared_ptr;
using std::make_shared;

#include <iostream>
using std::cerr;
using std::endl;

#include <regex>
using std::regex;
using std::smatch;
using std::regex_search;

#include <unordered_map>
using std::unordered_map;

#include "parser.h"
#include "components/renderable.h"
#include "components/jumpable.h"
#include "components/fibonacci_walk.h"
#include "components/shooter.h"
/*
#include "components/multiplier.h"
*/

enum class Component {
    None = 0,
    Jumpable,
    Renderable,
    FibonacciWalk,
    Shooter,
    Multiplier
};

unordered_map<string, Component> componentNames = {
    { "Jumpable",       Component::Jumpable         },
    { "Renderable",     Component::Renderable       },
    { "FibonacciWalk",  Component::FibonacciWalk    },
    { "Shooter",        Component::Shooter          },
    { "Multiplier",     Component::Multiplier       }
};

unique_ptr<IBaseComponent> MakeComponent(const string& name, const string& argument) {
    switch(componentNames[name]) {
        case Component::Renderable:
            return FRenderableComponent::Make(argument);
        case Component::Jumpable:
            return FJumpableComponent::Make(argument);
        case Component::FibonacciWalk:
            return FFibonacciWalkComponent::Make(argument);
        case Component::Shooter:
            return FShooterComponent::Make(argument);
        /*
        case Component::Multiplier:
            return FMultiplierComponent::Make(argument);
        */
        default:
            cerr << "No such component: " << name << endl;
            return nullptr;
    }
}

unique_ptr<IBaseComponent> ParseComponent(const string& line) {
    static const regex re("-\\s*([\\w]+)(\\((.*)\\))?");
    smatch match;
    if (regex_search(line, match, re)) {
        return MakeComponent(match.str(1), match.str(3));
    } else {
        return nullptr;
    }
}

unique_ptr<FClass> ParseClass(const string& line) {
    return make_unique<FClass>(line);
}

void ParseClasses(istream& stream, unordered_map<string, unique_ptr<FClass> >& classes) {
    string line;

    unique_ptr<FClass> klass;

    while (getline(stream, line)) {
        if (line.size() == 0) {
            continue;   // ignore empty lines just in case
        }

        if (line[0] == '-') {
            klass->AddComponent(ParseComponent(line));
        } else {
            if (klass) {
                classes[klass->Name()] = std::move(klass);
            }
            klass = ParseClass(line);
        }
    }
    classes[klass->Name()] = std::move(klass);
}
