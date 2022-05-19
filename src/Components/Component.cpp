#include "./Component.h"


Component::Component(const json& componentData) {
    if(!componentData.contains("id"))
        throw std::invalid_argument("'id' is missing");
    id = componentData["id"];
    
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