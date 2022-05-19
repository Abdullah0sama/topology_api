#if !defined(TOPOLOGY_MANAGER)
#define TOPOLOGY_MANAGER



#include <string>
#include <fstream>
#include <vector>
#include "map"
#include "./Topology.h"
#include "./Component.h"

class TopologyManager
{
private:
    std::map<std::string, Topology> topologyMap;
public:
    // Reading topology json from file
    void readJSON(std::string filename);
    // Writing topology json to file
    void writeJSON(std::string filename, std::string topologyId);
    // Topology::TopologyList queryTopologies() const;
    // void deleteTopology(int topologyId);
    // Component::ComponentList queryComponents(int topologyId) const;
    // Component::ComponentList queryComponentsWithNetListNode(int topologyId, std::string netlistNodeId) const;
};

#endif // TOPOLOGY_MANAGER
