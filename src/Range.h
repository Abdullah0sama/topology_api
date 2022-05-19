
#include <stdexcept>
#include "./JSONify.h"

class Range : public JSONify
{
private:
    int min;
    int max;
    int default_value;
public:
    Range(int max, int min, int default_value);
    int getMax() const;
    int getMin() const;
    int getDefault() const;
    json getJSON() const;
};

