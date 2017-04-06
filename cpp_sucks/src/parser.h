#pragma once

#include <unordered_map>
using std::unordered_map;

#include <memory>
using std::shared_ptr;

#include <iostream>
using std::istream;

#include "component.h"

void ParseClasses(istream& stream, unordered_map<string, FClass>& components);
