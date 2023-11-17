#include "FileReader.h"

void FileReader::InputSettingsReader(const std::string& filename) {
    inputFile.open(filename);
    if (!inputFile.is_open()) {
        throw "Error opening file\n";
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        if (line.length() > 0) {
            char key = line[0];
            std::string command = line.substr(2);
            keyMap[key] = command;


        }
    }
    
}
    



FileReader::~FileReader() {
    if (inputFile.is_open())
        inputFile.close();
}

std::map<int, std::string>* FileReader::getKeyList() {
    return &keyMap;
}
