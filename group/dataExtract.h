#pragma once
#include <unordered_map>
#include <fstream>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <tuple>
#include "mapper.h"
#include "dijkstra.h"
using namespace std;

enum airlineRef {
    AL_ID,
    AL_NAME,
    AL_ALIAS,
    AL_IATA,
    AL_ICAO
};

class OpenFlights {
    public:
        OpenFlights(const string &airportFile, const string &routeFile);
        tuple<vector<string>,double> landmark(string start, string landmark, string destination);
    
    private:
        
        
        void insertAirports();
        void insertFlights();
        string airport_;
        string route_;
        FlightMap map_;

        vector<string> parser(const string &line);
};
