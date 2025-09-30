#pragma once

#include <vector>
#include "Creator.h"
#include <cstdlib>
#include "VehiclePrototypes.h"

class GameManager {
    std::vector <VehiclePtr> m_Vehicles ;

    public:
    void Run() ;
    ~GameManager () = default;
};