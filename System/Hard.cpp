#include "Hard.h"

Hard::Hard() : Tyre(120, 30, 1.25) {
    setTyreType("Hard");
}

Hard::Hard(int durability, int grip, float pressure) : Tyre(durability, grip, pressure) {
    setTyreType("Hard");
}

Hard::~Hard() {

}

void Hard::usage(float track) {
    setDurability(getDurability() - (int)ceil(track));
    setGrip(getGrip() - 1);
    if (getDurability() <= 0) {
        //dead 
    }
}

string Hard::getTyreType() {
    return type;
}

void Hard::setTyreType(string str) {
    this->type = str;
}
