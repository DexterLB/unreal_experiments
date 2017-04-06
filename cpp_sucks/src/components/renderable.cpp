#include <iostream>
using std::cout;
using std::endl;

#include "renderable.h"

void FRenderableComponent::Update(float deltaMs, FObject& object) {
    cout << "update render" << endl;
}
