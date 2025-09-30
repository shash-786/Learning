#pragma once
#include "Vehicle.h"
#include <random>

class Car : public Vehicle {
    using Vehicle::Vehicle ;
    float m_SpeedFactor{1.5f} ;
    std::default_random_engine m_Engine{500};
    std::bernoulli_distribution m_Dist{.5};

public:
    void SetSpeedFactor (float speed) {
        m_SpeedFactor = speed ;
    }

    void Update() override ;
    VehiclePtr Clone() ;
};