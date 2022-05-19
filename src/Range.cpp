#include "./Range.h"


void Range::initializeValues(int max, int min, int default_value) {
    if(min > max) 
        throw std::invalid_argument("minimum value is larger than maximum value");
    if(default_value > max || default_value < min)
        throw std::invalid_argument("default value is out of range");
    this -> max = max;
    this -> min = min;
    this -> default_value = default_value; 
}
Range::Range(int max, int min, int default_value) {
    initializeValues(max, min, default_value);
}


Range::Range(json rangeData) {
    if(!rangeData.contains("max"))
        throw std::invalid_argument("'max' value is missing");
    if(!rangeData.contains("min"))
        throw std::invalid_argument("'min' value is missing");
    if(!rangeData.contains("default"))
        throw std::invalid_argument("'default' value is missing");

    initializeValues(rangeData.at("max"), rangeData.at("min"), rangeData.at("default"));
}
int Range::getMax() const {
    return max;
}

int Range::getMin() const {
    return min;
}

int Range::getDefault() const {
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