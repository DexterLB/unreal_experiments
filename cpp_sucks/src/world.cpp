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


class World : public IWorld
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

IWorld* CreateWorld() {
    return new World();
}

void World::Update(float deltaMs) {
    for (auto object : this->objects) {
        object.Update(deltaMs);
    }

    cout << "World updated with " << deltaMs << " ms." << endl;
}

void World::ParseTypes(const char* file) {
    if (!file || file[0] == '\0' ) {
        ParseClasses(cin, this->classes);
    } else {
        ifstream f;
        f.open(file);
        ParseClasses(f, this->classes);
        f.close();
    }

    for (const auto& kv: this->classes) {
        kv.second.Initialise();
    }
}

void World::SpawnObject(const char* objectType, const char* objectName) {
    FClass& klass = this->classes[string(objectType)];

    this->objects.push_back(FObject(
        &klass,
        string(objectName)
    ));
}

void World::Destroy() {
    delete this;    // this is evil.
}
