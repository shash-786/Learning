#pragma once

#include "Vehicle.h"
#include "Bus.h"
#include "Car.h"

Vehicle* Create(
    std::string_view type, 
    int HitPoints,
    int Speed,
    const std::string& Name,
    std::string_view animFile,
    const Position& Pos,
    const std::string& Color
) ;