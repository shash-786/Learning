#include "Bus.h"

void Bus::Update()
{    
    std::cout << '[' << getName() << ']' << "\n" << "\tColor: " << getColor() <<"\n"
              <<  "\tAnimation: " << getAnimationData() << '\n' ;
    
    if (m_Dist(m_Engine)) {
        std::cout << "\tMoving out of the Way" << '\n' ;
    }

    std::cout << "\tSpeed: " << getSpeed() << '\n' ;
    std::cout << "\tPostion: " << getPos() << '\n' ;
    std::cout << "\tHitpoints: " << getHitPoints() << "\n\n" ;
}

VehiclePtr Bus::Clone() {
    std::cout << "🤖🤖 [Cloning] ->" << getName() << "\n\n" ;
    return std::make_shared<Bus>(*this) ;
}
