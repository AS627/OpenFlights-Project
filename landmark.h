#pragma once
#include "airport_mapper.h"
#include "djikstra.h"
#include "flight.h"
#include "graph.h"
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Landmark{
    public:
        Landmark(Graph& g, string start_airport, string Landmark, string dest_airport);
        vector<string> getPath();
        double getDist();

    private:
        vector<string> path;
        double dist;
};