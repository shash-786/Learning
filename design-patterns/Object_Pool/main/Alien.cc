#include "Alien.h"

Alien::Alien() {
    std::cout << "Alien Constructed" << std::endl;
}

Alien::~Alien() {
    std::cout << "Alien Destructed" << std::endl;
}

void Alien::Update() {
    std::cout << "@ ";
}