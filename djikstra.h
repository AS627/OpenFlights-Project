#pragma once
#include "graph.h"
#include "flight.h"
#include "airport_mapper.h"

#include <vector>
#include <map>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Djikstras {
    public:
        //
        Djikstras (Graph g, string start_airport, string dest_airport);
        //getters
        double getShortestDistance() const;
        vector<string> getPathVertices() const;
        vector<pair<int, double>> getAdj(string src);
        

    private:
        map<string, double> dist;
        unordered_map<string, string> previous_nodes;
        priority_queue<pair<double, string>, vector<pair<double, string>>,greater<pair<double, string>> > Q;
        unordered_map <string, bool> visited; 
        double path;
        unordered_map<string, unordered_map<int, Flight> > adj_list;
        vector<string> path_vertices;
};