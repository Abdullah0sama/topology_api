#include "TopologyManager.h"
#include "string"
#include <iostream>
#include <fstream>
#include <gtest/gtest.h>
#include <stdio.h>

void deleteFile(const std::string &filePath) {
  remove(filePath.c_str());
}

const std::string topologies_dir = "./tests/topology_json_examples/";

// Demonstrate some basic assertions.
TEST(TopologyManagerTest, readTopology) {

    TopologyManager manager;
    manager.readJSON(topologies_dir + "topology_1.json");
    EXPECT_TRUE(manager.isTopologyExist("top1"));
    EXPECT_FALSE(manager.isTopologyExist("no"));
}

TEST(TopologyManagerTest, jsonRepresent) {
  std::string topFile1 = topologies_dir + "topology_1.json";
  TopologyManager manager;
  manager.readJSON(topFile1);
  std::fstream inStream(topFile1);
  json topData;
  inStream >> topData;
  EXPECT_EQ(topData, manager.getTopology(topData.at("id")).getJSON());
}
TEST(TopologyManagerTest, writeTopology) {
  std::string topFile1 = topologies_dir + "topology_1.json";;
  std::string topOutFile1 = "topology_1_out.json";
  
  TopologyManager manager;
  manager.readJSON(topFile1);
  manager.writeJSON(topOutFile1, "top1");

  std::fstream inStream(topFile1);
  json orignalData;
  inStream >> orignalData;
  inStream.close();
  json writtenData;
  inStream.open(topOutFile1);
  inStream >> writtenData;
  inStream.close();
  EXPECT_EQ(writtenData, orignalData);
  deleteFile(topOutFile1);
}
TEST(TopologyManagerTest, handleDeletion) {
  std::string topFile1 = topologies_dir + "topology_1.json";;
  TopologyManager manager;
  manager.readJSON(topFile1);
  for(const auto &topology: manager.queryTopologies()) {
    manager.deleteTopology(topology.getId());
    EXPECT_THROW(manager.getTopology(topology.getId()), std::out_of_range);
  }
}
