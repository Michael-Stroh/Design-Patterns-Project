#ifndef LOGGER_H
#define LOGGER_H

#include <string>
using namespace std;

class Logger
{
public:
    static void log(string, string);
    static void red(string, string);
    static void green(string, string);
    static void yellow(string, string);
    static void blue(string, string);
    static void magenta(string, string);
    static void cyan(string, string);
};

#endif