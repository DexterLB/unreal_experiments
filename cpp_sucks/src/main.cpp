#include <iostream>

#include "world.h"

int main(int argc, char *argv[]) {
    IWorld* world = CreateWorld();
    world->Update(42);
    world->Destroy();
    return 0;
}
