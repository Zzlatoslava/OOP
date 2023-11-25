#pragma once
#include <map>
#include "ICommandReader.h"

class FileReader : public ICommandReader {
public:
    FileReader() = default;
    void InputSettingsReader(const std::string& filename) override;
    std::map<int, std::string>* getKeyList();
    ~FileReader() ;

private:
    std::ifstream inputFile;
    std::map<int, std::string> keyMap;
};