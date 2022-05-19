#include "./Resistor.h"


const std::string Resistor::RANGENAME = "resistance";
const std::string Resistor::TYPE = "resistor";
const std::vector<std::string> Resistor::PIN_NAMES = {"t1", "t2"};

Resistor::Resistor(const json& componentData): Component(componentData) {
    setRange(RANGENAME, componentData);
    setNetlist(PIN_NAMES, componentData);
}


json Resistor::getJSON() const {

    json out = {
        {"type", TYPE}, 
        {"id", getId()}, 
        {RANGENAME, getRange().getJSON()}, 
        {"netlist", getNetlist().getJSON()}
    };
    return out;
}

Resistor* Resistor::clone() const {
    return new Resistor(*this);
}