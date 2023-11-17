#pragma once
#include <string>
#include <fstream>

class ICommandReader {
public:
    virtual void InputSettingsReader(const std::string& inputConfig) = 0;

    virtual ~ICommandReader() = default;
};
