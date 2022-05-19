#include "./Resistor.h"


const std::string Resistor::RANGENAME = "resistance";
const std::string Resistor::TYPE = "resistor";

Resistor::Resistor(const json& componentData): Component(componentData) {
    setRange(RANGENAME, componentData);
}


json Resistor::getJSON() const {

    json out = {
        {"type", TYPE}, 
        {"id", getId()}, 
        {RANGENAME, getRange().getJSON()}
    };
    return out;
}