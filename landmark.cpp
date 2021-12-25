#include "landmark.h"
using namespace std;

Landmark::Landmark(Graph& g, string start_airport, string Landmark, string dest_airport){
    
    Djikstras d1(g, start_airport, Landmark);
    Djikstras d2(g, Landmark, dest_airport);
    
    if(d1.getShortestDistance() != 0.0 && d2.getShortestDistance() != 0.0){
        path.resize(d1.getPathVertices().size() + d2.getPathVertices().size() - 1);
        dist = d2.getShortestDistance() + d1.getShortestDistance();
        
        
        unsigned i = 0;
        while(i < d1.getPathVertices().size()){
            path[i] = d1.getPathVertices()[i];
            i++;
        }
        i = 0;
        while(i < d2.getPathVertices().size()){
            path[i+ d1.getPathVertices().size() - 1] = d2.getPathVertices()[i];
            i++;
        }
    }else{
        
    dist = 0.0;
        path.clear();
    }
}


vector<string> Landmark::getPath(){
    return path;
}


double Landmark::getDist(){
    return dist;
}
