#if !defined(COMPONENT)
#define COMPONENT


#include <vector>
#include <memory>
#include <stdexcept>
#include "../Range.h"
#include "../JSONify.h"
#include "../Netlist.h"

class Component : JSONify
{
private:
    std::string id;
    std::unique_ptr<Range> valueRange;
    std::unique_ptr<Netlist> netlist;
protected:
    std::string rangeName;
    // Set Range
    void setRange(const std::string &rangeName, const json &componentData);
    // set Netlist
    void setNetlist(const std::vector<std::string>& pinNames, const json &componentData);
public:
    typedef std::unique_ptr<Component> ComponentPtr;
    typedef std::vector<ComponentPtr> ComponentList; 
    Component(const json& componentData);
    virtual json getJSON() const = 0;
    // Get component Id
    std::string getId() const;
    // Get Range
    Range getRange() const;
    // Get netlist
    Netlist getNetlist() const;
};

#endif // COMPONENT

