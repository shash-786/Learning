#pragma once
#include <string>
#include <iostream>
#include <thread>

class Animation {
    std::string m_AnimationData; // Ideally should be an animation object
    public:

    Animation() = default;
    Animation(std::string_view animFile) ;
    const std::string& GetAnimationData() const{
        return m_AnimationData;
    }

    void SetAnimationData(const std::string& AnimationData) {
        this->m_AnimationData = AnimationData ;
    }
};