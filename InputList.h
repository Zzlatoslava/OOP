#pragma once

#include "string"
#include "iostream"
#include "vector"
#include "map"
#include <conio.h>
#include "FileReader.h"


class InputList {
private:
    std::map<int, std::string> keyMap;
    std::vector<std::string> commands{ "move_up", "move_left", "move_right", "move_down" };

public:
    InputList();
    void InputSettingsReaderL();
    std::map<int, std::string>* getKeyList();
};