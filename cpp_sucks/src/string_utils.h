#pragma once

#include <string>
#include <functional>
#include <algorithm>

// shameless copy-paste from stackoverflow (I like his style)
// http://stackoverflow.com/a/217605

// trim from start
static inline std::string &ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(),
            std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
static inline std::string &rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(),
            std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
}

// trim from both ends
static inline std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}

static inline std::string& remove_char(std::string& s, char c) {
    s.erase(std::remove(s.begin(), s.end(), c), s.end());
    return s;
}
