#include <iostream>


#include "world.h"
#include "event_bus.h"

void EventTest();
int main(int argc, char *argv[]) {

    IWorld* world = CreateWorld();
    world->ParseTypes(nullptr);
    world->SpawnObject("Mario", "mario1");
    world->SpawnObject("Luigi", "luigi2");
    world->SpawnObject("Luigi", "luigi1");
    world->Update(42);
    world->Update(1000);
    world->Destroy();

    EventTest();
    return 0;
}
