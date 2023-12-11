#pragma once
#include "MessageOutput.h"

class ConsoleOutput : public MessageOutput {
public:
    void outputMessage(const IMessage& message) const override;
};