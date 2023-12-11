#pragma once
#include "IMessage.h"

class CommandExecutedMessage : public IMessage {
public:
    CommandExecutedMessage(int key, const std::string& command);

    std::string toString() const override;

private:
    int key;
    std::string command;
};
