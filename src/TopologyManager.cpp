#include "./TopologyManager.h"

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