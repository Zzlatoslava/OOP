#include "ReadConsol.h"


 InputReader::InputReader(const std::string& filename) {
    inputFile.open(filename);
    if (!inputFile.is_open()) {
        throw "Error opening file\n";
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        if (line.length() > 0) {
            char key = line[0];
            std::string command = line.substr(2);
            if (command == "move_up") keyToCommand[key] = move_up;
            if (command == "move_left") keyToCommand[key] = move_left;
            if (command == "move_right") keyToCommand[key] = move_right;
            if (command == "move_down") keyToCommand[key] = move_down;


        }
    }
    
}

Move InputReader::readInput() {
    char key;
    std::cout << "Press to key:\n";
    key = _getch();
    auto it = keyToCommand.find(key);
    if (it != keyToCommand.end()) {
        return it->second;
    }
    else {
        return Default;
    }

}

InputReader::~InputReader() {
    inputFile.close();
}




