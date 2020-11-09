#include "Soft.h"

Soft::Soft() : Tyre(60, 90, 1.2) {
    setTyreType("Soft");
}

Soft::Soft(int durability, int grip, float pressure) : Tyre(durability, grip, pressure) {
    setTyreType("Soft");
}

string Soft::getTyreType() {
    return type;
}

Soft::~Soft() {

}

void Soft::usage(float track) {
    setDurability(getDurability() - (int)ceil(track));
    setGrip(getGrip() - 3);
    if (getDurability() <= 0) {
        //dead 
    }
}

void Soft::setTyreType(string str) {
    this->type = str;
}
