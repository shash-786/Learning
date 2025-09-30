#include "VehiclePrototypes.h"

std::vector<std::string> VehiclePrototypes::GetKeys()
{
    std::vector< std::string > keys ;
    keys.reserve(m_Prototypes.size()) ;
    for (const auto& kv: m_Prototypes) {
        keys.push_back(kv.first) ;
    }
    return keys ;
}

void VehiclePrototypes::RegisterPrototype(const std::string &key, VehiclePtr prototype)
{
    if (m_Prototypes.find(key) != m_Prototypes.end()) {
        std::cout << "Prototype Already exists" << std::endl;
        return ;
    }
    m_Prototypes[key] = prototype ;
}

VehiclePtr VehiclePrototypes::GetPrototype(const std::string &key)
{
    if (m_Prototypes.find(key) == m_Prototypes.end()) {
        throw std::runtime_error("Prototype Doesn't exist") ;
    }
    return m_Prototypes[key]->Clone();
}

VehiclePtr VehiclePrototypes::DeregisterPrototype(const std::string &key)
{
    if (m_Prototypes.find(key) == m_Prototypes.end()) {
        throw std::runtime_error("Prototype Doesn't exist") ;
    }
    auto pvehicle = m_Prototypes[key];
    m_Prototypes.erase (key) ;
    return pvehicle;
}
