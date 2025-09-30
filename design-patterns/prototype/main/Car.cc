#include "Car.h"

void Car::Update()
{
    std::cout << '[' << getName() << ']' << "\n" << "\tColor: " << getColor() <<"\n"
              <<  "\tAnimation: " << getAnimationData() << '\n' ;
    
    if (m_Dist(m_Engine) && getColor() == "Red") {
        std::cout << "\tIncrease Speed Tempararily: " 
                  << getSpeed() * m_SpeedFactor << '\n';
    } else {
        std::cout << "\tSpeed: " << getSpeed() << '\n' ;
    }

    std::cout << "\tPostion: " << getPos() << '\n' ;
    std::cout << "\tHitpoints: " << getHitPoints() << "\n\n" ;
}

VehiclePtr Car::Clone() {
    std::cout << "🤖🤖 [Cloning] ->" << getName() << "\n\n" ;
    return std::make_shared<Car>(*this) ;
}