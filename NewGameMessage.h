#pragma once
#include "IMessage.h"

class NewGameMessage : public IMessage {
public:
    NewGameMessage(const std::string& playerInfo);

    std::string toString() const override;

private:
    std::string playerInfo;
};