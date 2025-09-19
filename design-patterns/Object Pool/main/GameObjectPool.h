#pragma once
#include "GameObject.h"
#include <string>
#include <unordered_map>
#include <vector>
#include <memory>
#include <algorithm>

using GameObjectPtr = std::shared_ptr<GameObject>;

class GameObjectPool {
    private:
    inline static std::unordered_map< std::string, std::vector< GameObjectPtr > > m_pool;
    static GameObjectPtr InternalCreate(const std::string& key);
    GameObjectPool()= default;

    public:
    static GameObjectPtr AcquireGameObject(const std::string& key);
    static void ReleaseGameObject(const std::string& key, const GameObjectPtr& object);
    static void RegisterCreator(const std::string& key, const std::string& creator);
};