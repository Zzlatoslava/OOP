#pragma once
#include "MessageOutput.h"
#include "FileOutput.h"
#include "ConsoleOutput.h"
#include <memory>


class MessageTracker {
public:
    enum class OutputMode {
        None,
        Console,
        File,
        ConsoleAndFile
    };

    MessageTracker(OutputMode outputMode, const std::string& filename = "");

    void sendMessage(const IMessage& message) const;

private:
    OutputMode outputMode;
    std::unique_ptr<MessageOutput> outputHandler;
};