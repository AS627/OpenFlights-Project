#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include "Route.h"
#include "Airport.h"
#include "dataExtract.h"

using namespace std;

class Graph{
    public:
        Graph();
        Graph(vector<Mapper> & airports, const string & routes);
        Graph(const Graph& other);
        ~Graph();

        int getNumAirports();
        vector<Mapper> & getAirports();

        /**
         * Check the iterator and index of the input airport
         * Then see if the current airport and other airports is nextby by isNextBy boolean set in constructor
         * @param airport where we are. represented as here in other functions
         * @return the nextby airports which is true in isNextBy[index][i]
         */
        vector<Mapper> getNextAirports(Mapper airport);

    private:
        bool** isNextBy;
        vector<Mapper> airports_;
        int numAirports_;
        vector<Route> route_;


};
