#include "GameManager.h"
#include "VehiclePrototypes.h"
#include <memory>

int main(int argc, char const *argv[])
{
    VehiclePrototypes::RegisterPrototype("car", std::make_shared<Car>());
    VehiclePrototypes::RegisterPrototype("bus", std::make_shared<Bus>());
    for (auto& prototype: VehiclePrototypes::GetKeys()) {
        std::cout << prototype << std::endl ;
    }
    GameManager mgr ;
    mgr.Run() ;
    return 0 ;
}
