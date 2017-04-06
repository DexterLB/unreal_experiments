#include <iostream>

#include "world.h"

int main(int argc, char *argv[]) {
    IWorld* world = CreateWorld();
    world->SpawnObject("mario", "mario1");
    world->SpawnObject("luigi", "luigi2");
    world->SpawnObject("luigi", "luigi1");
    world->Update(42);
    world->Destroy();
    return 0;
}
