#include "./Resistor.h"


Resistor::Resistor(json componentData): Component(componentData) {
    if(!componentData.contains(RANGENAME))
        throw std::invalid_argument("'" + RANGENAME + "' range values are missing");

    valueRange = std::unique_ptr<Range>(new Range(componentData.at(RANGENAME)));
}

Range Resistor::getRange() const {
    return *valueRange;
}

json Resistor::getJSON() const {

    json out = {
        {"type", TYPE}, 
        {"id", getId()}, 
        {RANGENAME, valueRange -> getJSON()}
    };
    return out;
}