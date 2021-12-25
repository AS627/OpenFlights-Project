//
// Created by sou30 on 2021/12/02.
//

#include "BFS.h"
#include <cmath>

#include <list>
#include <queue>
#include <stack>
#include <vector>

using std::string;
using std::vector;

vector<Mapper> BFS::traverseBFS(Mapper& here, Graph& graph){
    if (!Graph.existance(here)){
        // if the airport doesn't exist from here
        return vector<Mapper>();
    }

    // if pass, then get the number of airports from here
    unsigned int num_ports = graph.getNumAirports();
    // make the possible airport to a queue
    queue<Airport> queue;
    queue.push(here);
    vector<Mapper> possible_choice;
    vector<Mapper> airports = graph.getAirports();

    // variable subject to change
    int iterateH = find(airports.begin(), airports.end(), here);
    int indexH = dist(airports.begin(), iterateH);

    vector<bool> history(num_ports);
    for (unsigned int i = 0; i < V; i++){
        history[i] = false;
    }
    history[indexH] = true;



    while (!queue.empty()){
        // check from front
        Mapper curr_port = queue.front();
        possible_choice.push_back(curr_port);
        //pop it
        port_queue.pop();

        vector<Mapper> next_ports = graph.getNextAirports(curr_port);
        unsigned int size = next_ports.size();
        int default_dist = 0;

        for (unsigned int i = 0; i < size; i++) {
            // get the distance from here to the next airport
            // variable subject to change
            int iterateP = find(airports.begin(), airports.end(), next_ports[i]);
            // This is for check the index of that airport
            int indexP = dist(airports.begin(), iterateP);
            // This is for check the actual distance in km
            int dist = findDist(here.id, indexP);

            if (!history[indexP] && dist > default_dist) {
                // if the distance is shortest then add to the vector of next_airport
                history[indexP] = true;
                queue.push(next_ports[i]);
            }
            // This loop is just for check which airport is the shortest path
            // Will not affect the function unless you change the return var as short_port
            if (dist > default_dist){
                Mapper short_port = num_ports[i];
            }
            default_dist = dist;
        }
    }
    return next_ports;
    // If we want to get the shortest path directly instead of return the nextby airports
    // We need to return the short_port.
    // However I didn't change like that because I don't know the person who doesn't respond will perform this portion
}
