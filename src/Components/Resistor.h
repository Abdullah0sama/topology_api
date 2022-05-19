#if !defined(RESISTOR_COMP)
#define RESISTOR_COMP

#include "../Component.h"

class Resistor : public Component
{
private:
    /* data */
    static const std::string RANGENAME;
public:
    static const std::string TYPE;
    Resistor(const json& componentData);
    Range getRange() const;
    virtual json getJSON() const;
};

#endif // RESISTOR_COMP

