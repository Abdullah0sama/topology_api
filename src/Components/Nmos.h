#if !defined(NMOS_COMP)
#define NMOS_COMP

#include "Component.h"

class Nmos : public Component
{
private:
    static const std::string RANGENAME;
public:
    static const std::string TYPE;

    Nmos(const json &componentData);
    virtual json getJSON() const;
};


#endif // NMOS_COMP
