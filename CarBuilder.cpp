#include "CarBuilder.h"

CarBuilder::CarBuilder() {
	factories.push_back(new EngineFactory());
	factories.push_back(new ChassisFactory());
	factories.push_back(new TransmissionFactory());
	factories.push_back(new SteeringFactory());
	factories.push_back(new CoolingFactory());
	factories.push_back(new BodyFactory());
	factories.push_back(new SuspensionFactory());
	factories.push_back(new BrakesFactory());
	factories.push_back(new ElectronicFactory());

	//Logger::setDebug(true);
	Logger::debug("CarBuilder::Construcotr Vector of factories.length", to_string(factories.size()));
	//Logger::setDebug(false);
}

CarBuilder::~CarBuilder()
{
	for(int i=0; i<factories.size(); ++i)
		delete factories[i];
}

CarComposite * CarBuilder::buildCar()
{
	CarComposite * car = new CarComposite();
	Logger::debug("CarBuilder::build car", "adding parts to the created car");
	car->add(ENGINE, factories[ENGINE]->createPart());
	car->add(CHASSIS, factories[CHASSIS]->createPart());
	car->add(TRANSMISSION, factories[TRANSMISSION]->createPart());
	car->add(STEERINGWHEEL, factories[STEERINGWHEEL]->createPart());
	car->add(COOLINGSYSTEM, factories[COOLINGSYSTEM]->createPart());
	car->add(BODY, factories[BODY]->createPart());
	car->add(SUSPENSION, factories[SUSPENSION]->createPart());
	car->add(BRAKES, factories[BRAKES]->createPart());
	car->add(ELECTRONICS, factories[ELECTRONICS]->createPart());
	Logger::debug("CarBuilder::build car", "all parts added");

	return car;
}

