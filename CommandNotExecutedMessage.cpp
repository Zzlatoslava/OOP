#include "CommandNotExecutedMessage.h"

CommandNotExecutedMessage::CommandNotExecutedMessage(int key) : key(key) {}

std::string CommandNotExecutedMessage::toString() const {
    return "Command Not Executed: \n\t\tkey: " + std::to_string(key);
}
