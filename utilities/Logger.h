/**
   @file Logger.h
   @class Logger
   @authors Alex
   @version 1.0.0
   @brief A class to provide logging functionality. Static methods are used to allow for logging in 6 different colours allowed by UNIX terminals: Red, Green, Yellow, Blue, Magenta & Cyan.
 */

#ifndef LOGGER_H
#define LOGGER_H

#include <string>
using namespace std;

class Logger
{
    public:
        /**
             @brief Prints a specified heading & message to the console.
             @details All other functions in the Logger class function in the same manner.
             @param[in] heading: Heading of the logged message
             @param[in] message: The message body to be logged
        */
        static void log( string, string );

        /**
             @brief Prints a specified heading & message to the console in red
        */
        static void red( string, string );

        /**
            @brief Prints a specified heading & message to the console in green
        */
        static void green( string, string );

        /**
            @brief Prints a specified heading & message to the console in yellow
        */
        static void yellow( string, string );

        /**
            @brief Prints a specified heading & message to the console in blue
        */
        static void blue( string, string );

        /**
            @brief Prints a specified heading & message to the console in magenta
        */
        static void magenta( string, string );

        /**
            @brief Prints a specified heading & message to the console in cyan
        */
        static void cyan( string, string );
};

#endif