#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include "flight.h"

using namespace std;

class Airport {
    public:
        //constructors
        Airport();
        Airport(string &line);
        Airport(vector<string> airportVector);    
        Airport(int id, string name, string city, string country, double latitude, double longitude);
        
        //getters
        int getAID();
        string getAN();
        string getAC();
        string getACount();
        double get_Alat();
        double get_Along();

        //each airport how has an unordered map that records
        //the ID of each adjacent airport and the corresponding flight
        //it can be used as an adjacency list
        unordered_map<int, Flight> destAPs;

    private:
        int AID;
        string AN;
        string AC;
        string ACount;
        double A_lat;
        double A_long;
        
};
