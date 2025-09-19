#include "Missile.h"

Missile::Missile() {
    std::cout << "Missile Constructed" << std::endl;
}

Missile::~Missile() {
    std::cout << "Missile Destructed" << std::endl;
}

void Missile::Update() {
    std::cout << "-> ";
}