#include "graph.h"
#include <math.h> 
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <sstream>
#include <fstream>


using namespace std;


Graph::Graph(){

}


Graph::Graph(std::string & airportFile, std::string & routesFile){
    insertAllVertices(airportFile);
    insertAllEdge(routesFile);
}

void Graph::insertAllVertices(std::string & fileName)
{
    std::fstream doc;
    
    doc.open(fileName, ios::in);
    if (doc.is_open()){   
        std::string currL;
       
        while(getline(doc, currL)){ 
           
            int comma = 0;
            unsigned i = 0;
            while(i < currL.size()){
                i++;
                char current = currL[i];
                if(current == ',')
                    comma++;
            }
            if(comma == 13){
                Airport ap(currL);
                vertices[ap.getAID()] = ap;
            }
        }
        doc.close(); 
    }
}

std::vector<std::string> Graph::edge_make(string & line){
    
    std::string currString = "";
    std::vector<std::string> flightVector;

    int comma = 0;
    size_t i = 0;
    while(i < line.size()){
        i++;
        char current = line[i];
        if(current == ',')
            comma++;
        if(current == '\\')
            return flightVector;
        
    }
    if(comma != 8)
        return flightVector;
    i = 0;
    while (i < line.size()){
        i++;
        char current = line[i];
        
        if(current == ',') {
            flightVector.push_back(currString);
            currString = "";
        }
        
        else
            currString += current;
    }

    return flightVector;
}


Flight Graph::createEdge(std::vector<std::string> flightVector){
    int source = stoi(flightVector[3], nullptr);
    auto it = vertices.find(source);
    int dest = stoi(flightVector[5], nullptr);
    auto it2 = vertices.find(dest);
    bool check1 = it == vertices.end();
    bool check2 = it2 == vertices.end();
    
    if(check1 || check2){
        return Flight();
        
    }
    return Flight(source, dest, calcWeight(source, dest));
    
    
}


void Graph::insertEdge(Flight f){       
    int source = f.getSID();
    int dest = f.getDID();
    bool check = vertices[source].destAPs.find(dest) != vertices[source].destAPs.end();

    if (!check)   
        (vertices[source].destAPs)[dest] = f;
}


void Graph::insertAllEdge(std::string & fileName){
    std::fstream doc;
   
    doc.open(fileName, ios::in);
    if (doc.is_open()){   
        std::string currL;
        
        while(getline(doc, currL)){ 
            std::vector<std::string> currVect = edge_make(currL);
            bool check = currVect == std::vector<std::string>();
            if(!check){
                Flight defF = Flight();
                Flight f = createEdge(currVect);
                
                if(!(f == defF))
                    insertEdge(f);
            }
        }
        doc.close(); 
    }
}

unordered_map<int, Airport> Graph::getVertices(){
    return vertices;
}


unordered_map<int, Flight> Graph::adjVertWithWeight(int AID) {
    auto it = vertices.find(AID);
    if(it == vertices.end()){
        return unordered_map<int, Flight> ();
    }
    
    Airport& ap = vertices[AID];
    return ap.destAPs;
}

string Graph::get_Airport_name(int ID){
    auto it = vertices.find(ID);
    if(it == vertices.end()){
        return vertices[ID].getAN();
    }
    return string();
}


//modified but based of: https://www.geeksforgeeks.org/program-distance-two-points-earth/
double Graph::calcWeight(int fromID, int toID){
   
    double lat1 = radianConvert(vertices[fromID].get_Alat());
    double lat2 = radianConvert(vertices[toID].get_Alat());
    double lon1 = radianConvert(vertices[fromID].get_Along());
    double lon2 = radianConvert(vertices[toID].get_Along());

   
    double phi = lon2 - lon1;
    double lamdba = lat2 - lat1;
    
    long double ans = pow(sin(lamdba / 2), 2) +cos(lat1) * cos(lat2) * pow(sin(phi / 2), 2);
    ans = 2 * asin(sqrt(ans));
    double R = 6371;
    ans *= R;
    return ans; 
}


double Graph::radianConvert(double degree)
{
    long double one_deg = (M_PI) / 180;
    return (one_deg * degree);
}
 
