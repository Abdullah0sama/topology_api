#if !defined(RANGE)
#define RANGE


#include <stdexcept>
#include "./JSONify.h"

class Range : public JSONify
{
private:
    double min;
    double max;
    double default_value;
    void initializeValues(double max, double min, double default_value);
public:
    Range(double max, double min, double default_value);
    Range(const json& rangeData);

    double getMax() const;
    double getMin() const;
    double getDefault() const;
    json getJSON() const;
};

#endif // RANGE


