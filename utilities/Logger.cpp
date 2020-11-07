#ifndef LOGGER_CPP
#define LOGGER_CPP

#include "Logger.h"
#include <iostream>
using namespace std;

bool Logger::isDebug = false;

void Logger::log(string heading, string message)
{
    cout << "--- " << heading << " ---" << endl;
    cout << message << endl;
}

void Logger::red(string heading, string message)
{
    cout << "\033[31m";
    cout << "--- " << heading << " ---" << endl;
    cout << message << endl;
    cout << "\033[39m";
}

void Logger::green(string heading, string message)
{
    cout << "\033[32m";
    cout << "--- " << heading << " ---" << endl;
    cout << message << endl;
    cout << "\033[39m";
}

void Logger::yellow(string heading, string message)
{
    cout << "\033[33m";
    cout << "--- " << heading << " ---" << endl;
    cout << message << endl;
    cout << "\033[39m";
}

void Logger::blue(string heading, string message)
{
    cout << "\033[34m";
    cout << "--- " << heading << " ---" << endl;
    cout << message << endl;
    cout << "\033[39m";
}

void Logger::magenta(string heading, string message)
{
    cout << "\033[1;35m";
    cout << "--- " << heading << " ---" << endl;
    cout << message << endl;
    cout << "\033[1;39m";
}

void Logger::cyan(string heading, string message)
{
    cout << "\033[36m";
    cout << "--- " << heading << " ---" << endl;
    cout << message << endl;
    cout << "\033[39m";
}

void Logger::debug(string heading, string message)
{
    if (Logger::isDebug)
    {
        cout << "[debug] --- " << heading << " ---" << endl;
        cout << "[debug] " << message << endl;
    }
}

void Logger::setDebug(bool debug)
{
    Logger::isDebug = debug;
}


void Logger::customDebug(string s)
{
   // cout << "\033[37m [CDebug]--" << s << "---\033[39m" << endl;
}


#endif