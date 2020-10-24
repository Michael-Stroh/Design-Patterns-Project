#include "CarPart.h"

//To be safe, allocates default values to the part so
//that everything else should function.
CarPart::CarPart() {
	brand = "Volvo";	//wont be used elsewhere so if we see a volvo branded part we know there is
						//a problem
	name = "GearBox";	//same reasoning as the brand
	handling = 10;
	speed = 1;
	acceleration = 0;
}

CarPart::CarPart(float s, float h, float a, string n, string b)
{
	speed = s;
	handling = h;
	acceleration = a;
	name = n;
	brand = b;
}

CarPart::CarPart(Car& part) {
	speed = part.speed;
	handling = part.handling;
	acceleration = part.acceleration;
	name = part.name;
	brand = part.brand;
}

CarPart *  CarPart::clone() {
	return new CarPart(*this)
}

//is subject to change should we decide to use a logger
void CarPart::print()
{
	cout<<"Part: "<<name<<endl;
	cout<<"Brand: "<<brand<endl;
	cout<<"Speed Score: "<<speed<<endl;
	cout<<"Acceleration Score: "<<acceleration<<endl;
	cout<<"Handling Score: "<<handling<<endl;
	
}

string CarPart::getBrand() {
	return brand;
}

//realistically speaking this function will never be used.
//A new part of a different brand would be created.
void CarPart::setBrand(string newBrand) {
	brand = newBrand;
}
