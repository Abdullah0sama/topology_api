#include "./Component.h"


Component::Component(const json& componentData) {
    if(!componentData.contains("id"))
        throw std::invalid_argument("'id' is missing");
    id = componentData["id"];
    
}
Component::Component(const Component &component) {
    this -> id = component.id;
    valueRange = std::make_unique<Range>(*component.valueRange);
    netlist = std::make_unique<Netlist>(*component.netlist);
}
std::string Component::getId() const {
    return id;
}

void Component::setRange(const std::string &rangeName, const json &componentData) {
    if(!componentData.contains(rangeName))
        throw std::invalid_argument("'" + rangeName + "' range values are missing");

    valueRange = std::unique_ptr<Range>(new Range(componentData.at(rangeName)));
}

Range Component::getRange() const {
    return *valueRange;
}

Netlist Component::getNetlist() const {
    return *netlist;
}

void Component::setNetlist(const std::vector<std::string>& pinNames, const json &componentData) {
    std::vector<std::string> nodeNames;
    if(!componentData.contains("netlist"))
        throw std::invalid_argument("netlist is missing from component");
    json netlistData = componentData["netlist"];
    for(const auto &pin: pinNames) 
        if(netlistData.contains(pin)) {
            nodeNames.push_back(netlistData.at(pin));
        } else {
            throw std::invalid_argument("netlist pin: '" + pin + "' is missing");
        }
        
    netlist = std::make_unique<Netlist>(pinNames, nodeNames);
}