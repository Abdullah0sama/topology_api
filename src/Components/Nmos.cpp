#include "./Nmos.h"

const std::string Nmos::RANGENAME = "m(l)";
const std::string Nmos::TYPE = "nmos";


Nmos::Nmos(const json& componentData): Component(componentData) {
    setRange(RANGENAME, componentData);
}


json Nmos::getJSON() const {
    json out = {
        {"type", TYPE}, 
        {"id", getId()},
        {RANGENAME, getRange().getJSON()}
    };
    return out;
}