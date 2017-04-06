#pragma once

class IWorld
{
    public:
        /// Reads the file specified by file
        /// and prepares the system for later calls to SpawnObject.
        /// All types described in the file must be spawnable.
        virtual void ParseTypes(const char* file) = 0;
        /// Spawns a new object of the given type with the given name.
        virtual void SpawnObject(const char* objectType, const char* objectName) = 0;
        /// Updates the world and all of its objects.
        /// Logs any information to the output file.
        virtual void Update(float deltaMs) = 0;
        /// Destroys the world and all internal types, freeing all the memory.
        /// In its simplest form, it’s just Destroy() { delete this; }
        virtual void Destroy() = 0;
};

// This shit ain't called "PIMPL". It's way simpler and superior to PIMPL.
extern "C" IWorld* CreateWorld();
