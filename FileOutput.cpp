#include "FileOutput.h"


FileOutput::FileOutput(const std::string& filename)  {
    file.open(filename);
        
}

void FileOutput::outputMessage(const IMessage& message) const {
   
    if (file.is_open()) {
        //file << message.toString() << "\n";
        std::cout << "!!!!!!!!!!!!!!!\n";
    }
}