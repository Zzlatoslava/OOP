#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <conio.h>
#include "CreateField.h"



enum Move {
    move_up,
    move_left,
    move_down,
    move_right,
    Default
};

class InputReader {
public:
    InputReader(const std::string& filename);
    Move readInput();
    ~InputReader();

    

private:
    std::ifstream inputFile;
    std::map<char, Move> keyToCommand;
};