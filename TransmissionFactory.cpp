#include "TransmissionFactory.h"

TransmissionFactory::TransmissionFactory(): CarPartFactory() {

}

TransmissionFactory::~TransmissionFactory() {

}

CarPart* TransmissionFactory::createPart() {

	string brand = generateBrandName();
	float s = Transmission::INITIAL_SPEED + (rand()/10)*Transmission::INITIAL_SPEED_VARIANCE;
	float a = Transmission::INITIAL_ACCELERATION + (rand()/10)*Transmission::INITIAL_ACCELERATION_VARIANCE;
	float h = Transmission::INITIAL_HANDLING + (rand()/10)*Transmission::INITIAL_HANDLING_VARIANCE;
	CarPart * part = new Transmission(s,h,a, brand);
	return part;
}
