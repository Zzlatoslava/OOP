#pragma once
#include <map>
//#include "InputList.h"
#include "ICommandReader.h"

class FileReader : public ICommandReader {
public:
    FileReader() = default;
    void InputSettingsReader(const std::string& filename) override;
    std::map<int, std::string>* getKeyList();

    ~FileReader() override;

private:
    std::ifstream inputFile;
    //InputList KeyList;
    std::map<int, std::string> keyMap;
};