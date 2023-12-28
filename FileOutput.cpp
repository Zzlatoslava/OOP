#include "FileOutput.h"


FileOutput::FileOutput(const std::string& mfilename)  {
    
    file.open(mfilename);
        
}

void FileOutput::outputMessage(const IMessage& message)  {
    
    if (file.is_open()) {
        file << message.toString() << "\n";
        
    }
}

FileOutput::~FileOutput()
{
    file.close();
}
