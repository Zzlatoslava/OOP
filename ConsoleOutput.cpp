#include "ConsoleOutput.h"
#include <iostream>

void ConsoleOutput::outputMessage(const IMessage& message) const {
    std::cout << message.toString() << std::endl;
}
