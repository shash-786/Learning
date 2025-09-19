#pragma once

#include "GameObject.h"

class Alien : public GameObject {
    public:
    Alien();
    ~Alien();
    void Update() override;
};