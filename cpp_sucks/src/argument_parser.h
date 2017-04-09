#pragma once

#include <vector>
using std::vector;

#include <utility>
using std::pair;

#include <string>
using std::string;

vector<string> ParseStringArguments(const string& argumentList);
vector< pair<float, float> > ParseFloatPairVectorArgument(const string& argument);
