#include <iostream>
#include "utilities/Logger.h"
#include "CarBuilder.h"
#include "CarComposite.h"

#include "ChassisDepartment.h"
#include "EngineDepartment.h"
#include "ElectronicsDepartment.h"
#include "AerodynamicsDepartment.h"

using namespace std;

void printCarStatistics(CarComposite * car);

//Tim's main
int main()
{
    //Testing of The Car Hierarchy and all related functions
    /*
           Test 0: -Create a new car
                   -print it
                   - if all goe well we can be sure that the builder and factory participants are doing their jobs
                   -we will also know that the car and all of its parts have a working print function
    */
    Logger::magenta("Testing1","");
    CarBuilder* builder = new CarBuilder();
    CarComposite* car = builder->buildCar();
    //car->print();
       
    /*
        Test 1:- Clone the car. Print and compare values.
               -delete cloned car
               -ensure original car still prints
               -If all this works we can be sure that all the copy constructors are working as needed
               -we can also be sure that all values of each car part are set correctly
    */
   
    CarComposite* car2 = (CarComposite * ) car->clone();
    cout << "Car1 statistics" << endl;
    printCarStatistics(car);
    cout << "Car2 statistics" << endl;
    printCarStatistics(car2);
    //Need to make sure the body and cooling system extra variables are set properly
    cout << "Car 1 coolingRate:" << ((CoolingSystem*)(car->getPart(COOLINGSYSTEM)))->getCoolingRate() << endl;
    cout << "Car 2 coolingRate:" << ((CoolingSystem*)(car2->getPart(COOLINGSYSTEM)))->getCoolingRate() << endl;
    cout << "Car 1 aeroDynamic Multiplier:" << ((Body *)(car->getPart(BODY)))->getAerodynamicMultiplier()<< endl;
    cout << "Car 2 aeroDynamic Multiplier:" << ((Body*)(car2->getPart(BODY)))->getAerodynamicMultiplier() << endl;
    
    delete car2;
    cout << "Car1 statistics post deletion of clone car" << endl;
    printCarStatistics(car);

    /*  
            Test 3: -Ensuring the Car Memento Function works as it should
                    -no formal CareTaker will be used in this test.

    */  
    
    CarMemento* mem = car->createCarMemento();
    cout << "Printing out car1 statistics" << endl;
    printCarStatistics(car);
    cout << "Car 1 coolingRate:" << ((CoolingSystem*)(car->getPart(COOLINGSYSTEM)))->getCoolingRate() << endl;
    cout << "Car 1 aeroDynamic Multiplier:" << ((Body*)(car->getPart(BODY)))->getAerodynamicMultiplier() << endl;

    car->setCarMemento(mem);
    cout << "Printing out car1 statistics post reinstating memento" << endl;
    printCarStatistics(car);
    cout << "Car 1 coolingRate:" << ((CoolingSystem*)(car->getPart(COOLINGSYSTEM)))->getCoolingRate() << endl;
    cout << "Car 1 aeroDynamic Multiplier:" << ((Body*)(car->getPart(BODY)))->getAerodynamicMultiplier() << endl;

    /*
            Test 4: -Testing The Engineering aspects of the System.
                 
    */
    ChassisDepartment* cDep = new ChassisDepartment(new Budget(), 1000);
    cDep->runSimulation(car);
    cDep->runSimulation(car);
    cDep->runSimulation(car);
    cDep->runSimulation(car);

    printCarStatistics(car);

    //add debug logging to the destructors for extra testing
    delete builder;
    delete car;

    return 0;
}

void printCarStatistics(CarComposite* car)
{
    float aggregateH = car->getHandling();
    float aggregateA = car->getAcceleration();
    float aggregateS = car->getSpeed();

    cout << endl;
    cout << "Car total Speed: " << aggregateS << endl;
    cout << "Car total acceleration: " << aggregateA << endl;
    cout << "Car total Handling: " << aggregateH << endl;
    cout << endl;
}