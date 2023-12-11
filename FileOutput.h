#pragma once
#include "MessageOutput.h"
#include <fstream>
#include "iostream"

class FileOutput : public MessageOutput {
public:
    FileOutput(const std::string& filename);
    void outputMessage(const IMessage& message) const override;

private:
    std::ofstream file;
};