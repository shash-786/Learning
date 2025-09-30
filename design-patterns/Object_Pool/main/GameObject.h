#pragma once
#include <iostream>

class GameObject {
    bool m_visible;
    public:

    void SetVisibility(bool now);

    bool isVisible() const;
        

    virtual void Update() = 0;
    virtual ~GameObject()= default;
};