#include "PlayerWinMessage.h"

PlayerWinMessage::PlayerWinMessage(const std::string& playerInfo) : playerInfo(playerInfo) {}

std::string PlayerWinMessage::toString() const {
    return "Player Win: " + playerInfo;
}