//
// Created by sou30 on 2021/12/02.
//

#ifndef CS225FLIGHT_BFS_H
#define CS225FLIGHT_BFS_H

#pragma once
// This is the header file about graph name subject to other members
#include "Graph.h"
// This is the header file about airport
#include "Airport.h"

#include <algorithm>
#include <vector>

using std::string;
using std::vector;

class BFS {
    public:
            vector <Mapper> traverseBFS(Mapper & airport, Graph & graph);

};



#endif //CS225FLIGHT_BFS_H
