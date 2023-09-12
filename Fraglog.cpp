#include "Fraglog.hpp"


#define LOG_FILE "./logs/EngineLog.log"


std::tm* FragLog::getCurrentTime()
{
    std::time_t t = std::time(0); 
    return std::localtime(&t);
}


FragLog::FragLog()
{
    try
    {
        file.open(LOG_FILE,std::ios::app);
        if(!file)
        {
            throw ErrorClass::DirectoryException; 
        } 
    }
    catch (ErrorClass error)
    {
        file.open("./Error.log",std::ios::out);
        switch (error) {
            case (ErrorClass::DirectoryException):
                file << LOG_FILE << " : directory does not exist" << std::endl;
                break;
            default:
                file << "Exception Occured" << std::endl;
        } 
        file.close();
    }
}



FragLog::~FragLog()
{
    file << std::endl;
    file << std::endl;
    file.close();
}
