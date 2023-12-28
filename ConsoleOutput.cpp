#include "ConsoleOutput.h"
#include <iostream>

void ConsoleOutput::outputMessage(const IMessage& message)  {
    std::cout << message.toString() << std::endl;
}
