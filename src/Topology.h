#if !defined(TOPOLOGY)
#define TOPOLOGY

#include <vector>
#include <string>
#include <memory>
#include <map>
#include "JSONify.h"
#include "./Components/Resistor.h"
#include "./Components/Nmos.h"

class Topology : public JSONify
{
private:
    std::string id;
    std::map<std::string, std::vector<int>> connectedNodes;
    Component::ComponentList componentsContainer;
    // Make a dynamically allocated component depending on type
    Component::ComponentPtr makeComponent(const json& componentData);
    // Keep track of which components are connected through netlist nodes
    void monitorNetlist(const Netlist& netlist, int componentIndex);
public:
    typedef std::unique_ptr<Topology> TopologyPtr;
    typedef std::vector<Topology> TopologyList;

    Topology(const json& topologyData);
    Topology(const Topology& topology);
    // Get Components in topology
    Component::ComponentList getComponents() const;
    // Get Components connected to node in netlist
    Component::ComponentList getConnectedComponent(std::string nodeName) const;
    // Get topology Id
    std::string getId() const;

    json getJSON() const;
};


#endif // TOPOLOGY

