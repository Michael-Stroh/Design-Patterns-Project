#ifndef LOGGER_CPP
#define LOGGER_CPP

#include "Logger.h"
#include <iostream>
using namespace std;

void Logger::log(string heading, string message)
{
    cout << "--- " << heading << " ---" << endl;
    cout << message << endl;
}

void Logger::red(string heading, string message)
{
    cout << "\e[31m";
    cout << "--- " << heading << " ---" << endl;
    cout << message << endl;
    cout << "\e[39m";
}

void Logger::green(string heading, string message)
{
    cout << "\e[32m";
    cout << "--- " << heading << " ---" << endl;
    cout << message << endl;
    cout << "\e[39m";
}

void Logger::yellow(string heading, string message)
{
    cout << "\e[33m";
    cout << "--- " << heading << " ---" << endl;
    cout << message << endl;
    cout << "\e[39m";
}

void Logger::blue(string heading, string message)
{
    cout << "\e[34m";
    cout << "--- " << heading << " ---" << endl;
    cout << message << endl;
    cout << "\e[39m";
}

void Logger::magenta(string heading, string message)
{
    cout << "\e[35m";
    cout << "--- " << heading << " ---" << endl;
    cout << message << endl;
    cout << "\e[39m";
}

void Logger::cyan(string heading, string message)
{
    cout << "\e[36m";
    cout << "--- " << heading << " ---" << endl;
    cout << message << endl;
    cout << "\e[39m";
}

#endif