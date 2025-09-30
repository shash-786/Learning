#include "Creator.h"

Vehicle *Create(
    std::string_view type, 
    int HitPoints, 
    int Speed, 
    const std::string &Name, 
    std::string_view animFile, 
    const Position &Pos, 
    const std::string &Color)
{
    if(type == "redcar" ) {
        return new Car(Speed, HitPoints, Name, animFile, Pos, Color) ;
    } else if(type == "greencar") {
        return new Car(Speed, HitPoints, Name, animFile, Pos, Color) ;
    } else if(type == "yellowbus") {
        return new Bus(Speed, HitPoints, Name, animFile, Pos, Color) ;
    } else if(type == "bluebus" ) {
        return new Bus(Speed, HitPoints, Name, animFile, Pos, Color) ;
    }
    return nullptr;
}
