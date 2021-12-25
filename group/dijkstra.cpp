#include "dijkstra.h"

pair<std::vector<std::string>, double> Dijkstra::Dijkstra_function(Graph graph, Mapper mapper, int destination) {    
    //if the start or end location doesn't exist then return empty pair
    if (!graph.existance(mapper)){
        vector<string> empty;
        return make_pair(empty, INT_MAX);
    }

    unsigned int num_ports = graph.getNumAirports();
    // make the possible airport to a queue
    queue<Graph> queue;
    queue.push(mapper);
    vector<Mapper> possible_choice;
    vector<Mapper> airports = graph.getAirports();

    // variable subject to change
    int cur_airport = find(airports.begin(), airports.end(), mapper);

    unordered_map<string, int> distance;
    unordered_map<string, string> loc_crossed;
    unordered_set<string> loc_checks;
    priority_queue<pair<double, string>, vector<pair<double, string>>, greater<pair<double, string>>> dist_aiports;

    distance[cur_airport] = 0;
    loc_crossed[cur_airport] = "";

    while (!dist_aiports.empty()) {
        pair<double, string> min = dist_aiports.top();
        Mapper airport = airports[cur_airport];
        dist_aiports.pop();

        //if our location matches the end_loc then we reached the goal location
        if (airport == airports[destination]) {
            double distance_to_return = distance[destination];
            vector<string> path;
            string current = 

            while (current != ) {
                path.push_back(current);
                current = loc_crossed[current];
            }

            reverse(path.begin(), path.end());
            return make_pair(path, distance_to_return);
        }

        //if loc_checks contains the shortest path continue
        
        //loop through the current locations neighbors
        //if the distance using the neighbor is closer or gets us to the end location then make that
        //the new shortest route to end location
        //update it on the distance map and loc_checks
        vector<string> empty;
        return make_pair(empty, INT_MAX);
    }
}