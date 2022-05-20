#include "TopologyManager.h"
#include "string"
#include <iostream>
#include <fstream>
#include <gtest/gtest.h>

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
