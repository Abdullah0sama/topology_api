#if !defined(TOPOLOGY_MANAGER)
#define TOPOLOGY_MANAGER



#include <string>
#include <vector>
#include "./Topology.h"
#include "./Component.h"

class TopologyManager
{
private:
    Topology::TopologyList topologyContainer;
public:
    TopologyManager();
    void readJSON(std::string filename);
    void writeJSON(std::string filename);
    Topology::TopologyList queryTopologies() const;
    void deleteTopology(int topologyId);
    Component::ComponentList queryComponents(int topologyId) const;
    Component::ComponentList queryComponentsWithNetListNode(int topologyId, std::string netlistNodeId) const;
    ~TopologyManager();
};

#endif // TOPOLOGY_MANAGER
