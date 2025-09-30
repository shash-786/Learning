#include "Animation.h"
#include <thread>
#include <chrono>

Animation::Animation(std::string_view animFile)
{
    std::cout << "[Animation] Loading:" << animFile <<  ' ';
    for (int i = 0; i < 10; i++) 
    {
        std::cout << '.' ;
        std::this_thread::sleep_for(std::chrono::milliseconds(100)) ;
    }
    std::cout << '\n' ;
    m_AnimationData.assign("^^^^") ;
}
