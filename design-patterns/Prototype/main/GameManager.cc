#include "GameManager.h"

VehiclePtr GetGreenCar() {
    auto vehicle = VehiclePrototypes::GetPrototype("car") ;
    vehicle->setColor("Green") ;
    vehicle->setName("Car");
    vehicle->setHitPoints(15);
    vehicle->setSpeed(30) ;
    vehicle->setPos({0,0});
    Animation anim("green.anim") ;
    vehicle->setAnimationData(anim.GetAnimationData());
    return vehicle;
}

VehiclePtr GetRedCar() {
    auto vehicle = VehiclePrototypes::GetPrototype("car") ;
    vehicle->setColor("Red") ;
    vehicle->setName("Car");
    vehicle->setHitPoints(10);
    vehicle->setSpeed(30) ;
    vehicle->setPos({10,0});
    Animation anim("red.anim") ;
    vehicle->setAnimationData(anim.GetAnimationData());
    return vehicle;
}

VehiclePtr GetYellowBus() {
    auto vehicle = VehiclePrototypes::GetPrototype("bus") ;
    vehicle->setColor("Yellow") ;
    vehicle->setName("Bus");
    vehicle->setHitPoints(100);
    vehicle->setSpeed(10) ;
    vehicle->setPos({100,20});
    Animation anim("ybus.anim") ;
    vehicle->setAnimationData(anim.GetAnimationData());
    return vehicle;
}

VehiclePtr GetBlueBus() {
    auto vehicle = VehiclePrototypes::GetPrototype("bus") ;
    vehicle->setColor("Blue") ;
    vehicle->setName("Bus");
    vehicle->setHitPoints(200);
    vehicle->setSpeed(40) ;
    vehicle->setPos({90,80});
    Animation anim("bbus.anim") ;
    vehicle->setAnimationData(anim.GetAnimationData());
    return vehicle;
}

void GameManager::Run()
{
    m_Vehicles.push_back(GetRedCar());
    m_Vehicles.push_back(GetGreenCar());
    m_Vehicles.push_back(GetYellowBus()) ;
    m_Vehicles.push_back(GetBlueBus()) ;
    int count{5} ;
    using namespace std ;
    while(count !=0) {
        std::this_thread::sleep_for(1s) ;
        system("clear") ;
        for (auto vehicle : m_Vehicles)
            vehicle->Update() ;

        if(count == 2) 
        {
            auto vehicle = m_Vehicles[0]->Clone() ;
            vehicle->setPos({50, 50}) ;
            vehicle->setSpeed(15);
            m_Vehicles.push_back(vehicle);
        }

        if(count == 3) 
        {
            auto vehicle = m_Vehicles[2]->Clone() ;
            vehicle->setPos({10, 50}) ;
            vehicle->setSpeed(45);
            m_Vehicles.push_back(vehicle);
        }

        count--;
    }
    
}
  