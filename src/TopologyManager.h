#if !defined(TOPOLOGY_MANAGER)
#define TOPOLOGY_MANAGER



#include <string>
#include <fstream>
#include <vector>
#include "map"
#include "./Topology.h"
#include "./Components/Component.h"

class TopologyManager
{
private:
    std::map<std::string, Topology> topologyMap;
public:
    // Reading topology json from file
    void readJSON(std::string filename);
    // Writing topology json to file
    void writeJSON(std::string filename, std::string topologyId);
    // Deleting stored topology
    void deleteTopology(std::string topologyId);
    // Checking if topology is stored 
    bool isTopologyExist(std::string topologyId);
    // Get topology from manager
    Topology getTopology(std::string topologyId);
    // Get stored topologies
    Topology::TopologyList queryTopologies() const;
    // Get components of specified topology
    Component::ComponentList queryComponents(std::string topologyId) const;
    // Get components connected to a specified node in topology
    Component::ComponentList queryComponentsWithNetListNode(std::string topologyId, std::string netlistNodeId) const;
};

#endif // TOPOLOGY_MANAGER
