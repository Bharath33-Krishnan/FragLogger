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

#ifdef _WIN32


    #include <windows.h>
    void FragLog::PrintColor(std::string line, ErrorCodes code,bool newLine) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        int col = 7;

        switch(code)
        {
            case ErrorCodes::ERROR:
                col = 4;
                break;
            case ErrorCodes::WARNING:
                col = 6;
                break;
            case ErrorCodes::LOG:
                col = 3;
                break;
            default:
                col = 3;
                break;
        }

        SetConsoleTextAttribute(hConsole, col);
        std::cout << line;
        if (newLine) {
            std::cout << std::endl;
        }
        SetConsoleTextAttribute(hConsole, 7);
    }


#else



    void FragLog::PrintColor(std::string line, ErrorCodes code,bool newLine) 
    {
        std::string col = "\033[0m";

        switch(code)
        {
            case ErrorCodes::ERROR:
                col = "\033[0;31m";
                break;
            case ErrorCodes::WARNING:
                col = "\033[0;32m";
                break;
            case ErrorCodes::LOG:
                col = "\033[0;36m";
                break;
            default:
                col = "\033[0;36m";
                break;
        }


        std::cout << col << line << "\033[0m";
        if (newLine) {
            std::cout << std::endl;
        }
    }


#endif

