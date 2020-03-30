#pragma once
#include <string>

namespace phonetic {
    std::string find(std::string s1, std::string s2);

    bool checkWords(std::string s1 ,std::string s2);

    std::string tolowercase(std::string a);

    std::string removeSpaces(std::string str);

std::bool isOnlySpaces(std::string str);
};