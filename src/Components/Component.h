#if !defined(COMPONENT)
#define COMPONENT


#include <vector>
#include <memory>
#include <stdexcept>
#include "../Range.h"
#include "../JSONify.h"

class Component : JSONify
{
private:
    std::string id;
    std::unique_ptr<Range> valueRange;
protected:
    std::string rangeName;

public:
    typedef std::unique_ptr<Component> ComponentPtr;
    typedef std::vector<ComponentPtr> ComponentList; 
    Component(const json& componentData);
    virtual json getJSON() const = 0;
    // Get component Id
    std::string getId() const;
    // Get range
    Range getRange() const;
    // Set range
    void setRange(const std::string &rangeName, const json &componentData);
};

#endif // COMPONENT

