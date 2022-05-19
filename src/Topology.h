#if !defined(TOPOLOGY)
#define TOPOLOGY

#include <vector>
#include <string>
#include "JSONify.h"
#include "Component.h"
#include "./Components/Resistor.h"

class Topology : public JSONify
{
private:
    std::string id;
    Component::ComponentList componentsContainer;
    Component::ComponentPtr makeComponent(const json& componentData);
public:
    typedef std::vector<Topology> TopologyList;
    Topology(const json& topologyData);
    // Get topology Id
    std::string getId() const;

    json getJSON() const;
};


#endif // TOPOLOGY

