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

class FWorld : public IWorld
{
    public:
        void ParseTypes(const char* file);
        void SpawnObject(const char* objectType, const char* objectName);
        void Update(float deltaMs);
        void Destroy();
    private:
        unordered_map<string, FClass> classes;
        vector<FObject> objects;
};
