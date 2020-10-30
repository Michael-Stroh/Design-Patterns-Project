#include <iostream>
#include "utilities/Logger.h"
#include "CarBuilder.h"
#include "CarComposite.h"

using namespace std;

//Tim's main
int main()
{
    Logger::magenta("Testing1","");
    CarBuilder* builder = new CarBuilder();
    CarComposite* car = builder->buildCar();

    car->print();

    //add debug logging to the destructors for extra testing
    delete builder;
    delete car;

    return 0;
}