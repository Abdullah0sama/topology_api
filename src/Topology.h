#if !defined(TOPOLOGY)
#define TOPOLOGY

#include <vector>
#include <string>
#include <memory>
#include "JSONify.h"
#include "./Components/Resistor.h"
#include "./Components/Nmos.h"

class Topology : public JSONify
{
private:
    std::string id;
    Component::ComponentList componentsContainer;
    Component::ComponentPtr makeComponent(const json& componentData);
public:
    typedef std::unique_ptr<Topology> TopologyPtr;
    typedef std::vector<Topology> TopologyList;

    Topology(const json& topologyData);
    // Get Components in topology
    Component::ComponentList getComponents() const;
    // Get Components connected to node in netlist
    // Component::ComponentList getConnectedComponent(std::string nodeName);
    // Get topology Id
    std::string getId() const;

    json getJSON() const;
};


#endif // TOPOLOGY

