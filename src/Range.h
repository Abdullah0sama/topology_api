#if !defined(RANGE)
#define RANGE


#include <stdexcept>
#include "./JSONify.h"

class Range : public JSONify
{
private:
    int min;
    int max;
    int default_value;
    void initializeValues(int max, int min, int default_value);
public:
    Range(int max, int min, int default_value);
    Range(const json& rangeData);

    int getMax() const;
    int getMin() const;
    int getDefault() const;
    json getJSON() const;
};

#endif // RANGE


