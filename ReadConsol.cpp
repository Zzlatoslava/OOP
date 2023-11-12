#include "ReadConsol.h"


    void InputReader::setupKeys(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw "Error opening file\n";
        }

        std::string line;
        while (std::getline(file, line)) {
            if (line.length() > 0) {
                char key = line[0];
                std::string command = line.substr(2);
                if (command == "move_up") keyToCommand[key] = move_up;
                if (command == "move_left") keyToCommand[key] = move_left;
                if (command == "move_right") keyToCommand[key] = move_right;
                if (command == "move_down") keyToCommand[key] = move_down;
        
                
            }
        }
        std::cout << "File open or close\n";
        file.close();
    }

    Direction InputReader::readInput() {
        char key;       
        std::cout << "Press to key:\n";
        
            key = _getch();
            auto it = keyToCommand.find(key);
            if (it != keyToCommand.end()) {
                Move command = it->second;
                return executeCommand(command);
            }
            else {
                return NONE;
            }
        
    }

    Direction InputReader::executeCommand(Move command)
    {
        switch (command) {
        case move_up:
            std::cout << "^\n";
            return UP;
            break;
        case move_left:
            std::cout << "<\n";
            return LEFT;
            break;
        case move_right:
            std::cout << ">\n";
            return RIGHT;
            break;
        case move_down:
            std::cout << "v\n";
            return DOWN;
            break;

        
        }
    }

    
