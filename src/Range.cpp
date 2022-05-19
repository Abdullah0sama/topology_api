#include "./Range.h"


void Range::initializeValues(double max, double min, double default_value) {
    if(min > max) 
        throw std::invalid_argument("minimum value is larger than maximum value");
    if(default_value > max || default_value < min)
        throw std::invalid_argument("default value is out of range");
    this -> max = max;
    this -> min = min;
    this -> default_value = default_value; 
}
Range::Range(double max, double min, double default_value) {
    initializeValues(max, min, default_value);
}


Range::Range(const json& rangeData) {
    if(!rangeData.contains("max"))
        throw std::invalid_argument("'max' value is missing");
    if(!rangeData.contains("min"))
        throw std::invalid_argument("'min' value is missing");
    if(!rangeData.contains("default"))
        throw std::invalid_argument("'default' value is missing");
    initializeValues(rangeData.at("max"), rangeData.at("min"), rangeData.at("default"));
}
double Range::getMax() const {
    return max;
}

double Range::getMin() const {
    return min;
}

double Range::getDefault() const {
    return default_value;
}

json Range::getJSON() const {
    json out = {
        {"default", getDefault()}, 
        {"max", getMax()}, 
        {"min", getMin()}
    };
    return out;
}