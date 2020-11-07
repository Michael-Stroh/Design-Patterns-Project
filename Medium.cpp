#include "Medium.h"

Medium::Medium() : Tyre(90, 60, 1.25) {
    setTyreType("Medium");
}

Medium::Medium(int durability, int grip, float pressure) : Tyre(durability, grip, pressure) {

    setTyreType("Medium");
}

Medium::~Medium() {

}

void Medium::usage(float track) {
    setDurability(getDurability() - (int)ceil(track));
    setGrip(getGrip() - 2);
    if (getDurability() <= 0) {
        //dead 
    }
}

string Medium::getTyreType() {
    return type;
}

void Medium::setTyreType(string str) {
    this->type = str;
}
