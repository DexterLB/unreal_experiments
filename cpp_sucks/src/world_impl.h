#pragma once

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <fstream>
using std::ifstream;

#include <vector>
using std::vector;

#include <unordered_map>
using std::unordered_map;

#include "world.h"
#include "base_object.h"
#include "object.h"
#include "parser.h"

class FObject;

class FWorld : public IWorld
{
    public:
        FWorld() = default;
        FWorld(const FWorld&) = delete;
        FWorld& operator=(const FWorld&) = delete;
        void ParseTypes(const char* file);
        void SpawnObject(const char* objectType, const char* objectName);
        void Update(float deltaMs);
        void Destroy();
    private:
        unordered_map<string, unique_ptr<FClass> > classes;
        vector< unique_ptr<FObject> > objects;
};
