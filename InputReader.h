#pragma once

#include <iostream>
#include <conio.h>
#include "InputReaderI.h"
#include "FileReader.h"



class InputReader : public InputReaderI {
public:
    Move read(std::map<int, std::string>* KeyConfig) override;
};
