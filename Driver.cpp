#include "Driver.h"

Driver::Driver() {
	this->name = "";
	this->aggression = 0;
	this->specialMove = 0;
}

Driver::Driver(string name, int aggr, float move) {
	this->name = name;
	this->aggression = aggr;
	this->specialMove = move;
}

Driver::~Driver(){
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

float Driver::getSpecialMove() {
	return this->specialMove;
}

void Driver::setSpecialMove(float s) {
	this->specialMove = s;
}

