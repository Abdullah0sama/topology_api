#if !defined(COMPONENT)
#define COMPONENT


#include <vector>
#include <memory>
#include <stdexcept>
#include "Range.h"
#include "./JSONify.h"

class Component : JSONify
{
private:
    std::string id;
protected:
    std::string rangeName;
    std::unique_ptr<Range> valueRange;

public:
    typedef std::unique_ptr<Component> ComponentPtr;
    typedef std::vector<ComponentPtr> ComponentList; 
    Component(json componentData);
    virtual json getJSON() const = 0;
    // Get range of allowed values of component
    virtual Range getRange() const = 0;
    // Get component Id
    std::string getId() const;
    // Get type
    // virtual std::string getType() const = 0;
};

#endif // COMPONENT

