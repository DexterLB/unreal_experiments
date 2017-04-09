#include <sstream>
using std::stringstream;

#include <string>
using std::stof;

#include "argument_parser.h"
#include "string_utils.h"

#include <iostream>
vector<string> ParseStringArguments(const string& argumentList) {
    stringstream ss(argumentList);
    vector<string> arguments;

    size_t begin = 0;
    int arrayDepth = 0;
    string argument;

    for (size_t i = 0; i < argumentList.size(); i++) {
        if (argumentList[i] == '[') {
            arrayDepth++;
        } else if (argumentList[i] == ']') {
            arrayDepth--;
        }

        if (arrayDepth == 0 && argumentList[i] == ',') {
            argument = argumentList.substr(begin, i - begin);
            begin = i + 1;

            trim(argument);
            if (argument.size() != 0) {
                arguments.push_back(argument);
            }
        }
    }
    if (begin != argumentList.size()) {
        argument = argumentList.substr(begin);
        trim(argument);
        if (argument.size() != 0) {
            arguments.push_back(argument);
        }
    }

    return arguments;
}

vector< pair<float, float> > ParseFloatPairVectorArgument(const string& argument) {
    // caution: don't read this function. This is a very lazy hack,
    // and these things should never, ever, EVER be done this way.

    stringstream ss(argument);
    vector< pair<float, float> > pairs;

    int i = 0;
    pair<float, float> p;

    while (ss.good()) {
        string token;
        getline(ss, token, ',');

        remove_char(token, '[');
        remove_char(token, ')');
        remove_char(token, '(');
        remove_char(token, ']');
        trim(token);

        if (token.size() == 0) {
            continue;
        }

        float value = stof(token);

        if (i % 2 == 0) {
            p.first = value;
        } else {
            p.second = value;
            pairs.push_back(p);
        }

        i++;
    }


    return pairs;
}
