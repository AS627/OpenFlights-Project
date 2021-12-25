#include "../catch/catch.hpp"
#include "../dijkstra.h"
#include "../mapper.h"
#include "../dataExtract.h"
#include <string>
#include <iostream>
#include <math.h>

using namespace std;

std::string airport_file = "./tests/small_airports_dataset.txt";
std::string route_file = "./tests/small_routs_dataset.txt";
std::string a = "AAA", b = "BBB", c = "CCC", d = "DDD" ;

TEST_CASE("Dijkstra base test"){
    Dijkstra test;
    
    pair<std::vector<std::string>, double> result = test.Dijkstra_function(/**airport */, "DDD","CCC");
    REQUIRE(result.first.size() == 2);
    REQUIRE(result.first[0] == "AAA");
    REQUIRE(result.first[1] == "CCC");
    REQUIRE(result.second == 174);
}

TEST_CASE("Dijkstra choosing shortest path"){
    Dijkstra test;
    pair<std::vector<std::string>, double> result = test.Dijkstra_function(/**airport*/,"BBB","CCC");
    REQUIRE(result.first.size() == 2);
    REQUIRE(result.first[0] == "AAA");
    REQUIRE(result.first[1] == "CCC");
    std::string point1 = "BBB", point2 = "AAA",point3 = "CCC";
    REQUIRE(result.second == std::floor(load.findDist(load.findNode(point1),load.findNode(point2))) + std::floor(load.findDist(load.findNode(point3),load.findNode(point2)))); 
}

TEST_CASE("Dijkstra where no path is available"){
    Dijkstra test;
    pair<std::vector<std::string>, double> result = test.Dijkstra_function(/**airport*/,"CCC","AAA");
    REQUIRE(result.first.size() == 0);
    REQUIRE(result.second == __INT_MAX__);
}

TEST_CASE("testing findDist function"){
  
}