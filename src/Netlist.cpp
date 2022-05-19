#include "./Netlist.h"


Netlist::Netlist(const std::vector<std::string> &pinNames, const std::vector<std::string> &nodeNames) {
    if(pinNames.size() != nodeNames.size()) 
        throw std::invalid_argument("Number of pin names is not equal to number of node names");
    for(int i = 0; i < pinNames.size(); ++i) {
        nodes[pinNames[i]] = nodeNames[i];
    }
}
void Netlist::setNodeName(std::string pinName, std::string nodeName) {
    if(nodes.find(pinName) == nodes.end())
        throw std::invalid_argument("pin name: '" + pinName + "' is not present in the netlist");
    nodes[pinName] = nodeName;
}
std::vector<std::string> Netlist::getNodes() const {
    std::vector<std::string> nodeNames;
    for(const auto &pair: nodes)
        nodeNames.push_back(pair.second);
    return nodeNames;
}
std::string Netlist::getNode(std::string pinName) const{
    return nodes.at(pinName);
}
json Netlist::getJSON() const {
    return json(nodes);
}