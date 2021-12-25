#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include "airport_mapper.h"


using namespace std;

class Graph {
    public:
        //default constructor
        Graph();
        //constructor that accepts the airport and routes.dat files
        Graph(string & airportFile, string & routesFile);
        
        //functions to insert vertices
        void insertVertex(int v, Airport ap);
        void insertAllVertices(std::string & fileName);
        
        //functions to create and insert edges
        vector<string> edge_make(string & line);
        Flight createEdge(vector<string> flightVector);     
        void insertEdge(Flight f);
        void insertAllEdge(std::string & fileName);
        
        //functions that return private maps for debugging
        unordered_map<int, Airport> getVertices();
        unordered_map<int, Flight> adjVertWithWeight(int AID);
        string get_Airport_name(int ID);
        
        


    private:
        //functions that calculate the weight of an edge
        double calcWeight(int fromID, int toID);
        double radianConvert(double degree);
        
        //each graph object hosts a map of airports to its corresponding ID
        unordered_map<int, Airport> vertices;
};