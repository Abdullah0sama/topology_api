#include "./Nmos.h"

const std::string Nmos::RANGENAME = "m(l)";
const std::string Nmos::TYPE = "nmos";
const std::vector<std::string> Nmos::PIN_NAMES = {"drain", "gate", "source"};


Nmos::Nmos(const json& componentData): Component(componentData) {
    setRange(RANGENAME, componentData);
    setNetlist(PIN_NAMES, componentData);
}


json Nmos::getJSON() const {
    json out = {
        {"type", TYPE}, 
        {"id", getId()},
        {RANGENAME, getRange().getJSON()},
        {"netlist", getNetlist().getJSON()}
    };
    return out;
}