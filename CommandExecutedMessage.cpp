#include "CommandExecutedMessage.h"

CommandExecutedMessage::CommandExecutedMessage(int key, const std::string& command)
    : key(key), command(command) {}

std::string CommandExecutedMessage::toString() const {
    return "Command Executed: \n\t\tkey: " + std::to_string(key) + "\n\t\tcommand: " + command;
}
