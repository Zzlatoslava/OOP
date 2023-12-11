#pragma once

#include "Tracking.h"
#include "MessageTracker.h"
#include "PlayerWinMessage.h"
#include "PlayerLoseMessage.h"
#include "NewGameMessage.h"
#include "CommandExecutedMessage.h"
#include "CommandNotExecutedMessage.h"


class Message {
public:
    Message(Tracking* track, MessageTracker::OutputMode outputMode, const std::string& filename = "");

    void playerWins();
    void playerLoses();
    void newGame();
    void commandExecuted(std::string command);
    void commandNotExecuted();

private:
    MessageTracker messageTracker;
    Tracking* tracking;
};