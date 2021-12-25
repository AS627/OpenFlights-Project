#include "../catch/catch.hpp"
#include "../BFS.h"
#include "../dijkstra.h"

using namespace std;

string airport_file = "./tests/large_airports_dataset.txt";
string route_file = "./tests/large_airports_dataset.txt";
string edge1 = "AAA", edge2 = "ADD", edge3 = "ABA";

TEST_CASE("findDist is working as expected"){
/* Making sure findDist is working as expected */
    std::string point1 = "ABA", point2 = "ABR", point3 = "ABB";
    REQUIRE(std::floor(load.findDist(load.findNode(point1),load.findNode(point3))) == 398);
    REQUIRE(std::floor(load.findDist(load.findNode(point2),load.findNode(point3))) == 723);
    REQUIRE(std::floor(load.findDist(load.findNode(point1),load.findNode(point2))) == 438);
}

TEST_CASE("Dijkstra case finding a route from Wellington to Canberra"){

Dijkstra test;
pair<std::vector<std::string>, double> result = test.Dijkstra_function(load,"ACZ","ABM");
REQUIRE(result.first[0] == "ABR");
REQUIRE(result.first[1] == "ABM");
REQUIRE(result.first.size() == 2);
std::string point1 = "ACZ", point2 = "ABR", point3 = "ABM" ;
REQUIRE(result.second == std::floor(load.findDist(load.findNode(point1),load.findNode(point2)))+ std::floor(load.findDist(load.findNode(point3),load.findNode(point2)))) ;
}
TEST_CASE("Dijkstra case where there's no route"){

   Dijkstra test;
   pair<std::vector<std::string>, double> result = test.Dijkstra_function(load,"ACZ","ABK");
   REQUIRE(result.first.size() == 0);
   REQUIRE(result.second == __INT_MAX__);
}

TEST_CASE("Dijkstra case with competing paths "){
   
    Dijkstra test;
    pair<std::vector<std::string>, double> result = test.dijkstra_function(load,"ACZ","ABI");
    REQUIRE(result.first.size() == 2);
    REQUIRE(result.first[0] == "ABA");
    REQUIRE(result.first[1] == "ABI");
    std::string point1 = "ACZ", point2 = "ABA", point3 = "ABI" ;
    REQUIRE(result.second == std::floor(load.findDist(load.findNode(point1),load.findNode(point2)))+ std::floor(load.findDist(load.findNode(point3),load.findNode(point2)))) ;
}

TEST_CASE("Dijkstra with invalid airport destination"){
   
    Dijkstra test;
    pair<std::vector<std::string>, double> result = test.dijkstra_function(load,"ACZ","AEF");
    REQUIRE(result.first.size() == 0);
    REQUIRE(result.second == __INT_MAX__);
}
