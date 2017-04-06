#pragma once

#include <string>
using std::string;

class FClass {
    public:
        FClass();
        FClass(const string& name);
        const string& Name() const;

    private:
        string name;
};
