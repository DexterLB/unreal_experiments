#include <iostream>


#include "world.h"
#include "event_bus.h"

void EventTest();
int main(int argc, char *argv[]) {

    IWorld* world = CreateWorld();
    world->ParseTypes("/tmp/test.in");
    world->SpawnObject("Mario", "mario1");
    world->SpawnObject("Luigi", "luigi2");

    world->Update(1000);
    world->Update(500);
    world->Update(500);
    world->Update(500);
    world->Update(100);
    world->Update(600);
    world->Update(1000);

    world->Destroy();

    EventTest();
    return 0;
}
