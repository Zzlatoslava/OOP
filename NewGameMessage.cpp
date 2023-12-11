#include "NewGameMessage.h"

NewGameMessage::NewGameMessage(const std::string& playerInfo)
    : playerInfo(playerInfo) {}

std::string NewGameMessage::toString() const {
    return "New Game: " + playerInfo;
}
