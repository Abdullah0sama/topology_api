#if !defined(RESISTOR_COMP)
#define RESISTOR_COMP

#include "Component.h"

class Resistor : public Component
{
private:
    static const std::string RANGENAME;
    static const std::vector<std::string> PIN_NAMES;
public:
    static const std::string TYPE;
    Resistor(const json& componentData);
    virtual json getJSON() const;
};

#endif // RESISTOR_COMP

