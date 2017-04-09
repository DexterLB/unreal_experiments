#pragma once

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <vector>
using std::vector;

#include <unordered_map>
using std::unordered_map;

typedef int FObjectID;

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
        void SpawnObject(const string& objectType, const string& objectName);
        void SpawnObject(FClass* klass, const string& objectName);
        FClass* GetClass(const string& objectType);

        FObject& Object(FObjectID id);

        void Update(float deltaMs);
        void Destroy();

        ostream& Log();

        virtual ~FWorld() {};
    private:
        unordered_map<string, unique_ptr<FClass> > classes;
        vector< unique_ptr<FObject> > objects;
        int frameIndex;
        unique_ptr<ofstream> log = nullptr;
};
