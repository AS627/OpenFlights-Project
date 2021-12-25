#pragma once
#include <string>
#include <unordered_map>
#include <map>
#include <vector>
#include <cmath>
#include <cctype>
#include <algorithm>
#include "edge.h"

using namespace std;
# define M_PI  3.14159265358979323846 
enum airportRef {
    A_ID, 
    A_NAME,
    A_CITY,
    A_COUNTRY,
    A_IATA,
    A_ICAO,
    A_LAT,
    A_LONG
};

//  struct for airports in graph
struct node {
    int id;
    double latitude;
    double longitude;
    string code;
    string city;
    unordered_map<int, Edge> departures; //  destination airport, edge between nodes
};

//  graph class connecting airports with flights
class FlightMap {
    public:
        map<int, node> airportMap;
        unordered_map<int, string> idToCodeMap; //  converts airport ID to aiport IATA code
        unordered_map<string, int> codeToIdMap; //  converts airport IATA code to ID
        
        void insertNode(vector<string> line);
        void insertEdge(vector<string> line);

    private:
        double findDist(int start, int dest);
};
