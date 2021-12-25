#pragma once
#include <string>
#include <limits.h>

using namespace std;

enum routeRef {
    R_AIRLINE,
    R_AID,
    R_SOURCE,
    R_SID,
    R_DEST,
    R_DID
};

//  Edge class for graphs
class Edge {
    public:
        //  Constructor w/o weights
        Edge(int s, int d)
            : source(s), dest(d), weight(INT_MAX)
            {};
        
        //  Constructor with weight
        Edge(int s, int d, double w)
            : source(s), dest(d), weight(w)
            {};

        double getWeight() {
            return weight;
        }

        int getDestId() {
            return dest;
        }

        int getSourceId() {
            return source;
        }
 
        void setWeight(double w) {
            weight = w;
        }

        //  compares weight of 2 edges
        bool operator<(const Edge& other) const {
            return weight < other.weight;
        }

        bool operator==(Edge& other) const {
            if (source != other.source)
                return false;
            if (dest != other.dest)
                return false;
            return true;
        }
    
    private:
        int source;  //  ID of source of the egde
        int dest;    //  ID of destination of the edge
        double weight;  //  distance of flight
};
