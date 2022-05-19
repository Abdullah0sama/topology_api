#if !defined(COMPONENT)
#define COMPONENT


#include <vector>
#include <memory>
#include "Range.h"
#include "./JSONify.h"

class Component : JSONify
{
private:
    std::string id;
    std::string rangeName;
    std::unique_ptr<Range> valueRange;

public:
    typedef std::vector<Component> ComponentList; 
    
    // Get range of allowed values of component
    virtual Range getRange() = 0;
    // Get component Id
    std::string getId() const;
};

#endif // COMPONENT

