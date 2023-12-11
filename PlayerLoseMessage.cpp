#include "PlayerLoseMessage.h"

PlayerLoseMessage::PlayerLoseMessage(const std::string& playerInfo) : playerInfo(playerInfo) {}

std::string PlayerLoseMessage::toString() const {
    return "Player Lose: " + playerInfo ;
}