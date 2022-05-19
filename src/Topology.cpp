#include "./Topology.h"

#include"iostream"
using namespace std;
Topology::Topology(json topologyData) {

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


Component::ComponentPtr Topology::makeComponent(json componentData) {
    if(!componentData.contains("type"))
        throw invalid_argument("'type' of component is missing");
    std::string type = componentData.at("type");
    if(type == Resistor::TYPE) 
        return std::make_unique<Resistor>(componentData);
    return Component::ComponentPtr();
}

