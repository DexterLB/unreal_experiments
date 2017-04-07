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

enum class Component {
    None = 0,
    Jumpable,
    Renderable
};

unordered_map<string, Component> componentNames = {
    { "Jumpable", Component::Jumpable },
    { "Renderable", Component::Renderable }
};

// shameless copy-paste from stackoverflow (I like his style)
// http://stackoverflow.com/a/217605

// trim from start
static inline std::string &ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(),
            std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
static inline std::string &rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(),
            std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
}

// trim from both ends
static inline std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}

shared_ptr<IComponent> MakeComponent(const string& name, const vector<string>& arguments) {
    switch(componentNames[name]) {
        case Component::Renderable:
            return make_shared<FRenderableComponent>();
        default:
            cout << "no such component: " << name << endl;
            return nullptr;
    }
}

vector<string> ParseArguments(const string& argumentList) {
    stringstream ss(argumentList);
    vector<string> arguments;

    while (ss.good()) {
        string argument;
        getline(ss, argument, ',');
        trim(argument);
        arguments.push_back(argument);
    }

    return arguments;
}

shared_ptr<IComponent> ParseComponent(const string& line) {
    static const regex re("-\\s*([\\w]+)(\\((.*)\\))?");
    smatch match;
    if (regex_search(line, match, re)) {
        return MakeComponent(match.str(1), ParseArguments(match.str(3)));
    } else {
        return nullptr;
    }
}

FClass ParseClass(const string& line) {
    return FClass(line);
}

void ParseClasses(istream& stream, unordered_map<string, FClass>& classes) {
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
                classes[klass->Name()] = *klass;
            }
            klass = make_unique<FClass>(ParseClass(line));
        }
    }
    classes[klass->Name()] = *klass;
}
