#include "Message.h"

Message::Message(Tracking* track, const MessageTracker::OutputMode outputMode, const std::string& filename)
    : messageTracker( outputMode, filename) , tracking(track) {}

void Message::playerWins() {
    PlayerWinMessage playerWinMessage(tracking->printIndicators());
    messageTracker.sendMessage(playerWinMessage);
}

void Message::playerLoses() {
    PlayerLoseMessage playerLoseMessage(tracking->printCoords());
    messageTracker.sendMessage(playerLoseMessage);
}

void Message::newGame() {
    NewGameMessage newGameMessage(tracking->printForNewGame());
    messageTracker.sendMessage(newGameMessage);
}

void Message::commandExecuted( std::string command) {
    CommandExecutedMessage commandExecutedMessage(tracking->getKeyRead(), command);
    messageTracker.sendMessage(commandExecutedMessage);
}

void Message::commandNotExecuted() {
    CommandNotExecutedMessage commandNotExecutedMessage(tracking->getKeyRead());
    messageTracker.sendMessage(commandNotExecutedMessage);
}
