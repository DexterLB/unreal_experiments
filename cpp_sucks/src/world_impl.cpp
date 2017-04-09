#include <memory>
using std::unique_ptr;
using std::make_unique;

#include "world_impl.h"



void FWorld::Update(float deltaMs) {
    this->frameIndex++;
    this->Log() << "--- Starting frame " << this->frameIndex << " ---" << endl;

    for (size_t i = 0; i < this->objects.size(); i++) {
        this->Object(i).Update(deltaMs, *this);
    }
}

void FWorld::ParseTypes(const char* file) {
    if (!file || file[0] == '\0' ) {
        ParseClasses(cin, this->classes);
    } else {
        string filename(file);

        ifstream f;
        f.open(filename);
        ParseClasses(f, this->classes);
        f.close();

        string out_filename = filename.substr(0, filename.size() - 2) + "out";
        this->log = make_unique<ofstream>(out_filename);
    }

    for (auto& kv: this->classes) {
        kv.second->Initialise();
    }
}

void FWorld::SpawnObject(const char* objectType, const char* objectName) {
    this->SpawnObject(string(objectType), string(objectName));
}

void FWorld::SpawnObject(const string& objectType, const string& objectName) {
    auto klass = this->GetClass(objectType);
    this->SpawnObject(klass, objectName);
}

FObject& FWorld::Object(FObjectID id) {
    return *(this->objects[id]);
}

void FWorld::SpawnObject(FClass* klass, const string& objectName) {
    FObjectID id = this->objects.size();
    this->objects.push_back(make_unique<FObject>());

    this->objects[id]->Initialise(
        this,
        klass,  // maybe there's a better way than passing a bare pointer?
        id,
        objectName
    );
}

FClass* FWorld::GetClass(const string& objectType) {
    return this->classes[string(objectType)].get();   // a dangerous game, this is
}

void FWorld::Destroy() {
    this->log->close();
    delete this;    // this is evil.
}

ostream& FWorld::Log() {
    if (this->log) {
        return *(this->log);
    } else {
        return cout;
    }
}
