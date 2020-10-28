#include "CateringEquipment.h"

CateringEquipment::CateringEquipment(): Container() {
	cout << "Cater equipment has been packed into a container" << endl;
}

CateringEquipment::CateringEquipment( string details ): Container( details ) {

}

CateringEquipment::~CateringEquipment() {
}

string CateringEquipment::getFood() {

	return this->stored;
}
