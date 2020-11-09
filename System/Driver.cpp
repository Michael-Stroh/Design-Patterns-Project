#include "Driver.h"

Driver::Driver() {
	this->name = "";
	this->aggression = 0;
	this->error = 0;
}

Driver::Driver(string name, int aggr, float error) {
	this->name = name;
	this->aggression = aggr;
	this->error = error;
}

Driver::~Driver() {
}

string Driver::getName() {
	return this->name;
}

void Driver::setName(string name) {
	this->name = name;
}

int Driver::getAggression() {
	return this->aggression;
}

void Driver::setAggression(int a) {
	this->aggression = a;
}

void Driver::setErrorProne(float error) {
	this->error = error;
}

float Driver::getErrorProne() {
	return error;
}

