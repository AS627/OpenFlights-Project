#include "djikstra.h"
#include <map>
#include <climits>
#include <stack>

using namespace std;



vector<pair<int, double>> Djikstras::getAdj(string src) {
    vector<string> res;
    auto seeker = adj_list.find(src);
    bool check = seeker == adj_list.end(); 
    if (check){
        return vector<pair<int,double>>();
    }

    else {
        vector<pair<int,double>> vert_lst;
        unordered_map<int, Flight> &map = adj_list.at(src);
        auto it = map.begin();

        while (it != map.end())
        {
            vert_lst.push_back(make_pair(it->first, it->second.getWeight()));
            it++;
        }
        return vert_lst;
    }
}

Djikstras::Djikstras(Graph g, string start_airport, string dest_airport) {
    vector<string> vertices;  
    unordered_map<int, Airport> airMap = g.getVertices();
    path_vertices.clear();
    
    auto it = airMap.begin();
    while ( it != airMap.end()) {
        
        vertices.push_back(it->second.getAN());
        bool check =  it->second.getAN() == start_airport;
        if(!check) {
            dist.insert(make_pair(it->second.getAN(), INT_MAX));
            previous_nodes.insert(make_pair(it->second.getAN(), ""));
            visited.insert(make_pair(it->second.getAN(), false));
        }
        else {
            dist.insert(make_pair(it->second.getAN(), 0.0));
            previous_nodes.insert(make_pair(it->second.getAN(), ""));
            visited.insert(make_pair(it->second.getAN(), false));
        }
        it++;
    }
    pair<double,string> init = make_pair(0.0, start_airport);
    Q.push(init);

    it = airMap.begin(); 
    while(it != airMap.end()) {
        adj_list.insert(make_pair(it->second.getAN(), it->second.destAPs));
        it++;
    }
    double weight;
    for(;Q.top().second != dest_airport;) {
        pair<double, string> currentNode = Q.top();
        Q.pop();
        vector<pair<int , double>> neighbors = getAdj(currentNode.second);
        vector<pair<string, double>> neighborNames;
        for (auto each : neighbors) {
            it = airMap.begin(); 
            while (it != airMap.end()) {
                if (each.first == it->first) {
                    neighborNames.push_back(make_pair(it->second.getAN(), each.second));
                }
                it++;
            }
        }
        for (auto neighbor : neighborNames) {
            bool check2 = visited[neighbor.first] == false;
            bool check3 = visited[currentNode.second] == false;
            if (check2 && check3) {
                weight = neighbor.second;
                if(weight + dist[currentNode.second] < dist[neighbor.first]) {
                    dist[neighbor.first] = weight + dist[currentNode.second];
                    previous_nodes[neighbor.first] = currentNode.second;
                    Q.push(make_pair(dist[neighbor.first], neighbor.first)); 
                }
            }
        }
        visited[currentNode.second] = true;
    }
 
    path = dist[dest_airport];

    string key = dest_airport;
    path_vertices.push_back(dest_airport);
    while(key != start_airport) {
        path_vertices.push_back(previous_nodes[key]);
        key = previous_nodes[key];
    }
    std::reverse(path_vertices.begin(), path_vertices.end());
}

double Djikstras::getShortestDistance() const {
  return path;
}


vector<string> Djikstras::getPathVertices() const {
  return path_vertices;
}