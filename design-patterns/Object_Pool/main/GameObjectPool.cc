#include "GameObjectPool.h"
#include "Missile.h"
#include "Alien.h"

GameObjectPtr GameObjectPool::InternalCreate(const std::string& key) {
    if (key == "missile") {
        return std::make_shared<Missile>();
    } else if (key == "alien") {
        return std::make_shared<Alien>();
    } else {
        throw std::runtime_error("undefined gameobject type");
    }
}

GameObjectPtr GameObjectPool::AcquireGameObject(const std::string& key) {
    GameObjectPtr object = nullptr;
    if (m_pool.find(key) == m_pool.end()) {
        object = InternalCreate(key);
        m_pool[key].push_back(object);
        std::cout << "[POOL] Creating a New "<< key << " Object" << std::endl;
        return object;
    }

    auto objects = m_pool[key];
    auto object_ptr = std::find_if(begin(objects), end(objects), [](const auto& OBJECT){
        return !OBJECT->isVisible();
    });

    if (object_ptr != end(objects)) {
        object = *object_ptr;
        object->SetVisibility(true);
        std::cout << "[POOL] Reusing an Existing "<< key << " Object" << std::endl;
        return object;
    }

    object = InternalCreate(key);
    m_pool[key].push_back(object);
    std::cout << "[POOL] Creating a New "<< key << " Object" << std::endl;
    return object;
}

void GameObjectPool::ReleaseGameObject(const std::string& key, const GameObjectPtr& object) {
    if (m_pool.find(key) == m_pool.end()) {
        throw std::runtime_error("undefined gameobject type");
    }

    auto objects = m_pool[key];
    for (auto& obj: objects) {
        if (obj == object) {
            // RESET STATE
            obj->SetVisibility(false);
            return;
        }
    }

    throw std::runtime_error("Object Not found");
}
