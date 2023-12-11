#pragma once
#include "IMessage.h"

class PlayerLoseMessage : public IMessage {
public:
    PlayerLoseMessage(const std::string& playerInfo);

    std::string toString() const override;

private:
    std::string playerInfo;
};