
add_library(topology_api_lib)

target_sources(topology_api_lib
    PUBLIC
        ./Components/Component.h
        ./Components/Component.cpp
        ./Components/Resistor.h
        ./Components/Resistor.cpp
        ./Components/Nmos.h
        ./Components/Nmos.cpp
        JSONify.h
        Netlist.h
        Netlist.cpp
        Range.h
        Range.cpp
        Topology.h
        Topology.cpp
        TopologyManager.h
        TopologyManager.cpp
    )

target_include_directories(topology_api_lib
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
    )