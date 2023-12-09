#pragma once

#include <iostream>
#include "InputReaderI.h"
#include "InputList.h"



class InputReader : public InputReaderI {
public:
    Move read(std::map<int, std::string>* KeyConfig) override;
};