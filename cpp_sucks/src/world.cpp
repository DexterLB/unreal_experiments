#include <iostream>

using std::cout;
using std::endl;

#include "world.h"


class World : public IWorld
{
    public:
        void ParseTypes(const char* file);
        void SpawnObject(const char* objectType, const char* objectName);
        void Update(float deltaMs);
        void Destroy();
};

IWorld* CreateWorld() {
    return new World();
}

void World::Update(float deltaMs) {
    cout << "World updated with " << deltaMs << " ms." << endl;
}

void World::ParseTypes(const char* file) {

}

void World::SpawnObject(const char* objectType, const char* objectName) {

}

void World::Destroy() {
    delete this;    // this is evil.
}
