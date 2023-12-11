#pragma once
#include "IMessage.h"

class CommandNotExecutedMessage : public IMessage {
public:
    CommandNotExecutedMessage(int key);

    std::string toString() const override;

private:
    int key;
};