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

#include "world_impl.h"
#include "world.h"

IWorld* CreateWorld() {
    return new FWorld();
}

