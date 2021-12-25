#include "Graph.h"
#include <iostream>

using namespace std;

Graph::Graph(){

}

Graph::Graph(vector<Mapper> & airports, vector<Route> & route){
    airports_ = airports;
    numAirports_ = airports_.size();
    route_ = route;

    isNextBy = new bool*[numAirports_];
    for (int i = 0; i < numAirports_; i++){
        isNextBy[i] = new bool[numAirports_];
        for (int j = 0; j < numAirports_; j++) {
            isNextBy[i][j] = false;
        }
    }

    for (unsigned int k = 0; k < route_.size(); k++) {
        Airport here = route_[k].getHereAirport();
        Airport dest = route_[k].getDestinationAirport();

        auto ItrH = find(airports_.begin(), airports_.end(), here);
        auto destItr = find(airports_.begin(), airports_.end(), dest);

        if (ItrH != airports_.end() && destItr != airports_.end()){
            int IdxH = dist(airports_.begin(), ItrH);
            int destIdx = dist(airports_.begin(),destItr);

            isNextBy[IdxH][destIdx] = true;
            isNextBy[destIdx][IdxH] = true;
        }
    }
}

Graph::Graph(const Graph& other){
    isNextBy = new bool*[other.numAirports_];
    for (int i = 0; i < other.numAirports_; i++) {
        isNextBy[i] = new bool[other.numAirports_];
        for (int j = 0; j < other.numAirports_; j++) {
            isNextBy[i][j] = other.isNextBy[i][j];
        }
    }

    airports_ = other.airports_;
    numAirports_ = other.numAirports_;
    route_ = other.route_;
}

Graph::~Graph(){
    for (unsigned int i = 0; i < airports_.size(); i++) {
        delete[] isNextBy[i];
    }
    delete[] isNextBy;
}

int Graph::getNumAirports(){
    return numAirports_;
}
vector<Mapper> & Graph::getAirports(){
    return airports_;
}

vector<Mapper> Graph::getNextAirports(Mapper airport){
    vector<Mapper> contender = vector<Mapper>();

    int iterate = find(airports_.begin(), airports_.end(), airport);

    if (iterate != airports_.end()) {
        int index = dist(airports_.begin(), iterate);
        for (int i = 0; i < numAirports_; i++) {
            if (isNextBy[index][i]) {
                contender.push_back(airports_[i]);
            }
        }
    }

    return contender;
}
