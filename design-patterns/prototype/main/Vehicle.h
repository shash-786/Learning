#pragma once
#include "Animation.h"
#include <vector>
#include <memory>



struct Position
{
    int x, y;

    friend std::ostream& operator<<(std::ostream& out, const Position p) {
        return out << '(' << p.x << ',' << p.y << ')' ;
    }
};


class Vehicle ;
using VehiclePtr = std::shared_ptr< Vehicle >;

class Vehicle 
{
    int m_Speed;
    int m_HitPoints;
    std::string m_Color;
    std::string m_Name;
    Animation* m_Animation;
    Position m_Pos;

    public:
    Vehicle() ;

    Vehicle(
        int HitPoints,
        int Speed,
        const std::string& Name,
        std::string_view animFile,
        const Position& Pos,
        const std::string& Color
    );

    Vehicle(const Vehicle& other) ;
    Vehicle& operator=(const Vehicle& other) ;

    virtual ~Vehicle();

    Position getPos () const {
        return m_Pos ;
    }

    const std::string & getName() const {
        return m_Name ;
    }

    const std::string & getColor() const {
        return m_Color ;
    }

    int getHitPoints() const {
        return m_HitPoints ;
    }

    int getSpeed() const {
        return m_Speed ;
    }

    void setPos (Position p)  {
        m_Pos = p ;
    }

    void setSpeed (int speed) {
        m_Speed = speed ;
    }

    void setName (const std::string& name) {
        m_Name = name ;
    }

    void setColor (const std::string& color) {
        m_Color = color;
    }

    void setHitPoints (int hp) {
        m_HitPoints = hp ;
    }

    void setAnimationData (const std::string& animData) {
        m_Animation->SetAnimationData(animData) ;
    }

    const std::string& getAnimationData () const {
        return m_Animation->GetAnimationData() ;
    }


    virtual void Update() = 0 ;
    virtual VehiclePtr Clone() = 0 ;
};

