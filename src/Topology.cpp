#include "./Topology.h"

Topology::Topology(const json& topologyData) {

    if(!topologyData.contains("id"))
        throw std::invalid_argument("'id' is missing");
    id = topologyData.at("id");

    if(topologyData.contains("components")) {
        for(const auto &componentJSON: topologyData.at("components")) {
            componentsContainer.push_back(makeComponent(componentJSON));
        }
    }
}
std::string Topology::getId() const {
    return id;
}

json Topology::getJSON() const {
    json out = {
        {"id", getId()}
    };
    
    for(const auto &componet: componentsContainer)
        out["components"].push_back(componet -> getJSON());

    return out;
}

Component::ComponentList Topology::getComponents() const {
    Component::ComponentList out;
    for(const auto &component: componentsContainer) {
        out.push_back(std::unique_ptr<Component>(component -> clone()));
    }
    return out;
}

Component::ComponentPtr Topology::makeComponent(const json& componentData) {
    if(!componentData.contains("type"))
        throw std::invalid_argument("'type' of component is missing");
        
    std::string type = componentData.at("type");
    if(type == Resistor::TYPE) 
        return std::make_unique<Resistor>(componentData);
    else if(type == Nmos::TYPE)
        return std::make_unique<Nmos>(componentData);    
    return Component::ComponentPtr();
}

