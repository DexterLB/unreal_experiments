#include <iostream>

#include <string>
using std::string;
using std::getline;

#include <memory>
using std::unique_ptr;
using std::make_unique;
using std::shared_ptr;
using std::make_shared;

#include "parser.h"
#include "components/renderable.h"

shared_ptr<IComponent> ParseComponent(const string& line) {
    return make_shared<FRenderableComponent>();
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
