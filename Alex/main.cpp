#include "../utilities/Logger.h"

int main()
{
    // Testing the logger
    Logger::blue("Test", "This is a test message");
    Logger::setDebug(false);
    Logger::debug("Test", "This is a test debug");
    Logger::debug("Another Test", "This is another test debug");
    return 0;
}