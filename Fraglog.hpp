#pragma once

#include <fstream>
#include <cstring>
#include <ctime>
class FragLog 
    {
    public:
        FragLog();
        void getStackTrace(unsigned int);
        std::tm* getCurrentTime();
        inline void write(const char* log)
        {
            // auto now = getCurrentTime();
            const auto t = std::time(0);
            file << std::ctime(&t);
            file << "********************"<< std::endl;
            file << log << std::endl;   
        }
        ~FragLog();


    private:
        std::ofstream file;
        const char* logFile = "./logs/EngineLog.log";
    };

enum class ErrorClass 
{
    DirectoryException = -1
};
