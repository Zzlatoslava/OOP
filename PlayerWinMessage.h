#pragma once

#include "IMessage.h"

class PlayerWinMessage : public IMessage {
public:
    PlayerWinMessage(const std::string& playerInfo);
    std::string toString() const override;

private:
    std::string playerInfo;
};