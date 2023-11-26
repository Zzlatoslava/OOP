#include "FileReader.h"

void FileReader::InputSettingsReader(const std::string& filename) {
    inputFile.open(filename);
    if (!inputFile.is_open()) {
        throw "Error opening file\n";
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        if (line.length() > 0) {
            if (keyMap.find(line[0]) != keyMap.end()) {
                throw "Repeating a character in a file\n";
            }
            if (commandSearch(line.substr(2))) {
                throw "Repeating a command in a file\n";
            }
            if (!isCommand(line.substr(2))) {
                throw "A repeated character is entered\n";
            }
            
            char key = line[0];
            std::string command = line.substr(2);
            keyMap[key] = command;
        }
    }
}

bool FileReader::commandSearch(std::string command)
{
    for (auto& it : keyMap) {
        if (it.second == command) {
            return true;
        }
    }
    return false;
}

bool FileReader::isCommand(std::string command)
{
    for (auto start{ commands.begin() }; start != commands.end(); start++) {
        if (command == *start) {
            return true;
        }
    }
    return false;
}
    



FileReader::~FileReader() {
    if (inputFile.is_open())
        inputFile.close();
}

std::map<int, std::string>* FileReader::getKeyList() {
    return &keyMap;
}
