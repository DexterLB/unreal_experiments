#include <sstream>
using std::stringstream;

#include "argument_parser.h"
#include "string_utils.h"

vector<string> ParseStringArguments(const string& argumentList) {
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
