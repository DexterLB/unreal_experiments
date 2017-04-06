#include <iostream>

#include "world.h"

int main(int argc, char *argv[]) {
    IWorld* world = CreateWorld();
    world->ParseTypes(nullptr);
    world->SpawnObject("Mario", "mario1");
    world->SpawnObject("Luigi", "luigi2");
    world->SpawnObject("Luigi", "luigi1");
    world->Update(42);
    world->Destroy();
    return 0;
}
