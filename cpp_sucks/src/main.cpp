#include <iostream>


#include <stdio.h>
#include <execinfo.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

#include "world.h"

void handler(int sig) {
    void *array[10];
    size_t size;

    // get void*'s for all entries on the stack
    size = backtrace(array, 10);

    // print out all the frames to stderr
    fprintf(stderr, "Error: signal %d:\n", sig);
    backtrace_symbols_fd(array, size, STDERR_FILENO);
    exit(1);
}

int main(int argc, char *argv[]) {
    signal(SIGSEGV, handler);

    IWorld* world = CreateWorld();
    world->ParseTypes(nullptr);
    world->SpawnObject("Mario", "mario1");
    world->SpawnObject("Luigi", "luigi2");
    world->SpawnObject("Luigi", "luigi1");
    world->Update(42);
    world->Destroy();
    return 0;
}
