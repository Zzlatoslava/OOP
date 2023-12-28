#include "MessageTracker.h"

MessageTracker::MessageTracker(OutputMode outputMode, const std::string& filename) {
    if (outputMode == OutputMode::File || outputMode == OutputMode::ConsoleAndFile) {
        if (!filename.empty()) {
            outputHandler = std::make_unique<FileOutput>(filename);
        }
        else {
            outputMode = OutputMode::None;
        }
    }

    if (outputMode == OutputMode::Console || outputMode == OutputMode::ConsoleAndFile ) {
        outputHandler = std::make_unique<ConsoleOutput>();
    }

    
    this->outputMode = outputMode;
}

void MessageTracker::sendMessage(const IMessage& message) const {
    if (outputMode != OutputMode::None) {
        outputHandler->outputMessage(message);
    }
}
