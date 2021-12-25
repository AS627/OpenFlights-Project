#pragma once

#include <utility>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

#include "mapper.h"
#include "Graph.h"
using namespace std;

class Dijkstra {
    public:
        /** 
         * requires object type for data to use 
         */
        pair<vector<string>, double> Dijkstra_function(Graph graph, Mapper map, int destination);
};