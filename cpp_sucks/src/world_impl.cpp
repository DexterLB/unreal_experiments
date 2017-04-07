#include "world_impl.h"

void FWorld::Update(float deltaMs) {
    for (auto object : this->objects) {
        object.Update(deltaMs);
    }

    cout << "FWorld updated with " << deltaMs << " ms." << endl;
}

void FWorld::ParseTypes(const char* file) {
    if (!file || file[0] == '\0' ) {
        ParseClasses(cin, this->classes);
    } else {
        ifstream f;
        f.open(file);
        ParseClasses(f, this->classes);
        f.close();
    }

    for (auto& kv: this->classes) {
        kv.second.Initialise();
    }
}

void FWorld::SpawnObject(const char* objectType, const char* objectName) {
    FClass& klass = this->classes[string(objectType)];

    this->objects.push_back(FObject(
        &klass,
        string(objectName)
    ));
}

void FWorld::Destroy() {
    delete this;    // this is evil.
}
