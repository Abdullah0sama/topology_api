#if !defined(NETLIST)
#define NETLIST

#include "map"
#include "string"
#include <vector>
#include "./JSONify.h"

class Netlist : JSONify
{
private:
    std::map<std::string, std::string> nodes;
public:
    Netlist(const std::vector<std::string> &pinNames, const std::vector<std::string> &nodeNames);
    // Change nodename connected to pin
    void setNodeName(std::string pinName, std::string nodeName);
    // Get name of all nodes
    std::vector<std::string> getNodes() const;
    // Get name of node connected to the pin
    std::string getNode(std::string pinName) const;
    virtual json getJSON() const;
};


#endif // NETLIST
