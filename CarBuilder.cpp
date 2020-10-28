#include "CarBuilder.h"

CarBuilder::CarBuilder() {
	factories.push_back(new EngineFactory());
	factories.push_back(new ChassisFactory());
	factories.push_back(new TransmissionFactory());
	factories.push_back(new SteeringWHeelFactory());
	factories.push_back(new CoolingSystemFactory());
	factories.push_back(new BodyFactory());
	factories.push_back(new SuspensionFactory());
	factories.push_back(new BrakesFactory());
	factories.push_back(new ElectronicsFactory());

}

CarBuilder::~CarBuilder()
{
	for(int i=0; i<factories.size(); ++i)
		delete factories[i];
}

CarComposite * CarBuilder::buildCar()
{
	CarComposite * car = new CarComposite();
	carComposite.add(ENGINE, factories[ENGINE]->createPart());
	carComposite.add(CHASSIS, factories[CHASSIS]->createPart());
	carComposite.add(TRANSMISSION, factories[TRANSMISSION]->createPart());
	carComposite.add(STEERINGWHEEL, factories[STEERINGWHEEL]->createPart());
	carComposite.add(COOLINGSYSTEM, factories[COOLINGSYSTEM]->createPart());
	carComposite.add(BODY, factories[BODY]->createPart());
	carComposite.add(SUSPENSION, factories[SUSPENSION]->createPart());
	carComposite.add(BRAKES, factories[BRAKES]->createPart());
	carComposite.add(ELECTRONICS, factories[ELECTRONICS]->createPart());

	return car;
}
