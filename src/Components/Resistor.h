#if !defined(RESISTOR_COMP)
#define RESISTOR_COMP

#include "../Component.h"

class Resistor : public Component
{
private:
    /* data */
    const std::string TYPE = "resistor";
    const std::string RANGENAME = "resistance";
public:
    Resistor(json componentData);
    Range getRange() const;
    virtual json getJSON() const;
};


#endif // RESISTOR_COMP

