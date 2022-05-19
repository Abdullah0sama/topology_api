#if !defined(NMOS_COMP)
#define NMOS_COMP

#include "Component.h"

class Nmos : public Component
{
private:
    static const std::string RANGENAME;
    static const std::vector<std::string> PIN_NAMES;
public:
    static const std::string TYPE;

    Nmos(const json &componentData);
    virtual json getJSON() const;
};


#endif // NMOS_COMP
