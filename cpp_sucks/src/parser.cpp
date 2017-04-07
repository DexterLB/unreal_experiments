#include <iostream>
using std::cout;
using std::endl;

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

#include <regex>
using std::regex;
using std::smatch;
using std::regex_search;

#include <unordered_map>
using std::unordered_map;

#include "parser.h"
#include "components/renderable.h"
#include "components/jumpable.h"

enum class Component {
    None = 0,
    Jumpable,
    Renderable
};

unordered_map<string, Component> componentNames = {
    { "Jumpable", Component::Jumpable },
    { "Renderable", Component::Renderable }
};

shared_ptr<IComponent> MakeComponent(const string& name, const string& argument) {
    switch(componentNames[name]) {
        case Component::Renderable:
            return FRenderableComponent::Make(argument);
        case Component::Jumpable:
            return FJumpableComponent::Make(argument);
        default:
            cout << "no such component: " << name << endl;
            return nullptr;
    }
}

shared_ptr<IComponent> ParseComponent(const string& line) {
    static const regex re("-\\s*([\\w]+)(\\((.*)\\))?");
    smatch match;
    if (regex_search(line, match, re)) {
        return MakeComponent(match.str(1), match.str(3));
    } else {
        return nullptr;
    }
}

FClass ParseClass(const string& line) {
    return FClass(line);
}

void ParseClasses(istream& stream, unordered_map<string, unique_ptr<FClass> >& classes) {
    string line;

    unique_ptr<FClass> klass;

    while (getline(stream, line)) {
        std::cout << "line: " << line << std::endl;
        if (line.size() == 0) {
            continue;   // ignore empty lines just in case
        }

        if (line[0] == '-') {
            klass->AddComponent(ParseComponent(line));
        } else {
            if (klass) {
                classes[klass->Name()] = std::move(klass);
            }
            klass = make_unique<FClass>(ParseClass(line));
        }
    }
    classes[klass->Name()] = std::move(klass);
}
