#pragma once
#include "Move.h"
#include <map>

class InputReaderI {
    virtual Move read(std::map<int, std::string>* KeyConfig) = 0;
};
