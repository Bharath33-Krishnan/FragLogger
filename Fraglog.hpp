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


#ifdef _WIN32


    #include <windows.h>
    void PrintColor(std::string line, ErrorCodes code=ErrorCodes::LOG,bool newLine = false) {
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



    void PrintColor(std::string line, ErrorCodes code=ErrorCodes::LOG,bool newLine = false) 
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
        ~FragLog();


    private:
        std::ofstream file;
        const char* logFile = "./logs/EngineLog.log";
    };

enum class ErrorClass 
{
    DirectoryException = -1
};
