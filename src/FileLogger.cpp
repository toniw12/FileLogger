#include "Arduino.h"
#include "FileLogger.h"

using namespace std;



FileLogger::FileLogger(String folder)
{
    folderName=folder;

}


void FileLogger::begin()
{

}

void FileLogger::end()
{
    logFile.close();
}

void FileLogger::flush()
{
    logFile.flush();
}

int FileLogger::available(void)
{
    return 0;
}

int FileLogger::peek(void)
{

    return 0;
}
int FileLogger::read(void)
{

    return 0;

}

size_t FileLogger::write(uint8_t val)
{
	char mychar=val;
    if (!logFile.is_open()){
        logFile.open(folderName.c_str(), std::ofstream::out | std::ofstream::app);
        logFile << "<date> ";
    }
    logFile << mychar;
    if(mychar=='\n'){
        logFile.close();
    }
	return 1;
}

size_t FileLogger::write(const uint8_t *buffer, size_t size)
{
    for(size_t i=0;i<size;i++){
        write(buffer[i]);
    }
	return size;
}

