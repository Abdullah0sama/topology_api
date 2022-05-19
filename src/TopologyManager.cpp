#include "./TopologyManager.h"

#include <iostream>
void TopologyManager::readJSON(std::string filename) {
    std::ifstream inStream(filename);
    if(inStream.fail()) {
        throw std::invalid_argument("Something went wrong with file: " + filename);
    }
    json topologyData;
    inStream >> topologyData;
    Topology topology(topologyData);
    topologyMap.insert(std::make_pair(topology.getId(),  topologyData));
}

void TopologyManager::writeJSON(std::string filename, std::string topologyId) {
    std::ofstream outStream(filename); 
    outStream << std::setw(1) << topologyMap.at(topologyId).getJSON() << std::endl;
}

void TopologyManager::deleteTopology(std::string topologyId) {
    topologyMap.erase(topologyId);
}

bool TopologyManager::isTopologyExist(std::string topologyId) {
    return topologyMap.find(topologyId) != topologyMap.end();
}

// Topology::TopologyList TopologyManager::queryTopologies() const {
//     Topology::TopologyList list;
    
//     for(const auto &topologyGroup: topologyMap)
//         topologyGroup.second.getComponents();
//     return list;
// }
