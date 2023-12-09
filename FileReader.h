#pragma once
#include <map>
#include "ICommandReader.h"
#include <vector>

class FileReader : public ICommandReader {
public:
    FileReader() = default;
    void InputSettingsReader(const std::string& filename) override;
    bool commandSearch(std::string command);
    bool isCommand(std::string command);
    std::map<int, std::string>* getKeyList();
    ~FileReader();

private:
    std::ifstream inputFile;
    std::map<int, std::string> keyMap;
    std::vector<std::string> commands{ "move_up", "move_left", "move_right", "move_down" };
};