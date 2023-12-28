#pragma once
#include "IMessage.h"

class MessageOutput {
public:
    virtual ~MessageOutput() = default;
    virtual void outputMessage(const IMessage& message)  = 0;
};