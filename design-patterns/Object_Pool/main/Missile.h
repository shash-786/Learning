#pragma once

#include "GameObject.h"

class Missile : public GameObject {
    public:
    Missile();
    ~Missile() ;
    void Update() override;
};