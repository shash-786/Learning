#include "Vehicle.h"

Vehicle::Vehicle()
{

    m_Speed = 0;
    m_HitPoints = 0;
    m_Color = "";
    m_Name = "";
    m_Animation = new Animation() ;
    m_Pos = {0, 0};
}

Vehicle::Vehicle(int HitPoints, int Speed, const std::string &Name, std::string_view animFile, const Position &Pos, const std::string &Color)
{
    m_Speed = Speed ;
    m_HitPoints = HitPoints ;
    m_Color = Color ;
    m_Name = Name ;
    m_Animation = new Animation(animFile) ;
    m_Pos = Pos;
}

Vehicle::Vehicle(const Vehicle &other)
{
    m_Name = other.getName() ; 
    m_Color = other.getColor() ;
    m_HitPoints = other.getHitPoints() ;
    m_Pos = other.getPos() ;
    m_Speed = other.getSpeed() ;

    Animation* deep_copy = new Animation() ;
    deep_copy->SetAnimationData(other.getAnimationData()) ;
    m_Animation = deep_copy ;
}

Vehicle &Vehicle::operator=(const Vehicle &other)
{
    if (this != &other) {
        m_Name = other.getName() ; 
        m_Color = other.getColor() ;
        m_HitPoints = other.getHitPoints() ;
        m_Pos = other.getPos() ;
        m_Speed = other.getSpeed() ;

        Animation* deep_copy = new Animation() ;
        deep_copy->SetAnimationData(other.getAnimationData()) ;
        m_Animation = deep_copy ;
    }
    return *this;
}

Vehicle::~Vehicle() {
    delete m_Animation ;
}
