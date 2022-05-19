#include "./Component.h"


Component::Component(json componentData) {
    if(!componentData.contains("id"))
        throw std::invalid_argument("'id' is missing");
    id = componentData["id"];
    
}
std::string Component::getId() const {
    return id;
}