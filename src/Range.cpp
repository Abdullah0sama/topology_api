#include "./Range.h"


Range::Range(int max, int min, int default_value) {

    if(min > max) 
        throw std::invalid_argument("minimum value is larger than maximum value");
    if(default_value > max || default_value < min)
        throw std::invalid_argument("default value is out of range");
    this -> max = max;
    this -> min = min;
    this -> default_value = default_value; 
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