#include <iostream>
#include <thread>
#include "GameObjectPool.h"
#include "GameObject.h"

std::vector< std::pair< std::string, std::shared_ptr<GameObject> > > objects; 

void Fire() {
    objects.push_back({"missile", GameObjectPool::AcquireGameObject("missile")});
    objects.push_back({"alien", GameObjectPool::AcquireGameObject("alien")});
}

void Animate() {
    for (auto& object: objects) {
        object.second->Update();
    }
}

void Explode() {
    std::cout << " X "; 
    for (auto& object: objects) {
        GameObjectPool::ReleaseGameObject(object.first, object.second);
    }
    objects.clear();
    std::cout << "\n\n" ;
}

void GameLoop() {
    int counter{}, rotations{};
    while(true) {
        ++counter ;
        if(counter == 1) {
            Fire();
           // std::cout << objects.size() << std::endl;
        }

        if(counter >=1 && counter <= 5) {
            Animate();
        }

        if(counter > 5) {
            Explode();
            counter = 0;
            rotations++;

            if (rotations == 3) {
                return;
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    GameLoop();
    return 0;
}
