#pragma once

#include <fstream>
#include <cstring>
#include <ctime>

#include <iostream>


enum class ErrorCodes
{
    ERROR,
    WARNING,
    LOG
};





class FragLog 
{
    public:
        FragLog();
        void getStackTrace(unsigned int);
        std::tm* getCurrentTime();
        static inline void console(const char* log,ErrorCodes code = ErrorCodes::LOG,bool newLine=true)
        {
            PrintColor(log,code,newLine);
        }
        inline void write(const char* log)
        {
            // auto now = getCurrentTime();
            const auto t = std::time(0);
            file << std::ctime(&t);
            file << "********************"<< std::endl;
            file << log << std::endl;   
        }
        static void PrintColor(std::string line, ErrorCodes code=ErrorCodes::LOG,bool newLine = false);
        ~FragLog();


    private:
        std::ofstream file;
        const char* logFile = "./logs/EngineLog.log";
    };

enum class ErrorClass 
{
    DirectoryException = -1
};
