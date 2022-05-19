#if !defined(TOPOLOGY)
#define TOPOLOGY

#include <vector>
#include <string>
#include "JSONify.h"
#include "./Components/Resistor.h"
class Topology : public JSONify
{
private:
    std::string id;
    Component::ComponentList componentsContainer;
    Component::ComponentPtr makeComponent(json componentData);
public:
    typedef std::vector<Topology> TopologyList;
    Topology(json topologyData);
    // Get topology Id
    std::string getId() const;

    json getJSON() const;
};


#endif // TOPOLOGY

