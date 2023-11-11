#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <conio.h>
#include "CreateField.h"
#include <SFML/Window/Keyboard.hpp>


enum Move {
    move_up,
    move_left,
    move_down,
    move_right,
    esc
};

class InputReader {
public:
    InputReader() {}

    void setupKeys(const std::string& filename);

    void readInput();

    Direction executeCommand(Move command);

private:
    std::map<char, Move> keyToCommand;
};