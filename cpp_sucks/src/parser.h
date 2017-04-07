#pragma once

#include <unordered_map>
using std::unordered_map;

#include <memory>
using std::shared_ptr;
using std::unique_ptr;

#include <iostream>
using std::istream;

#include "component.h"
#include "base_object.h"

class FClass;

void ParseClasses(istream& stream, unordered_map<string, unique_ptr<FClass> >& components);
