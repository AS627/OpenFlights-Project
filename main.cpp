#include <iostream>
#include <vector>
#include <unordered_map>
#include <iomanip>


#include "airport_mapper.h"
#include "djikstra.h"
#include "landmark.h"
#include "graph.h"

using namespace std;


int main() {
    
    string departureingAirport;
    string DestinationAirport;
    
    string airportFile = "airports.dat";
    string routesFile = "routes.dat";

    
    cout << "1. Shortest journey between two places" << endl;
    cout << "2. Shortest journey between two places with a layover" << endl;
          
    Graph airportGraph(airportFile, routesFile);
    unordered_map<int, Airport> vert_in_graph = airportGraph.getVertices();

    int opt; 
    cin >> opt;
         

    switch (opt)
    {
        
        case 1:{
            string departure; 

            cout << "Enter the airport of departure, or enter 'comp' to use \n'Los Angeles International Airport' as departure and \n'Dabolim Airport' as final destination:\n (quick test)";
            
            cin.ignore();
            getline(std::cin, departure);

            if(departure == "comp"){
                Djikstras shortestpath = Djikstras(airportGraph, "Los Angeles International Airport", "Dabolim Airport");
                double distance = shortestpath.getShortestDistance();
                vector<string> path = shortestpath.getPathVertices();

                cout<<"Airports Visited during Transit: \n"<<endl;
                for (unsigned long i = 0; i < path.size(); i++) {
                    cout << path[i];
                    if(i != path.size()-1)
                        cout<< " --> ";
                    
                }
                cout<<""<<endl;
                cout<<"Total Distance: "<< distance << " KM" << endl;
            } else {
                cout << "Enter the final destination:\n";
                string final_; 
                getline(std::cin, final_);
                Djikstras shortestpath = Djikstras(airportGraph, departure, final_);
                vector<string> path = shortestpath.getPathVertices();
                double distance = shortestpath.getShortestDistance();
                if(distance == 0.0){
                    cout<< "Airport not found."<<endl;
                    break;
                }
                cout<<"Airports Visited during Transit: \n"<<endl;
                for (unsigned long i = 0; i < path.size(); i++) {
                    cout << path[i];
                    if(i != path.size()-1)
                        cout<< " --> ";
                    
                }
                cout<<""<<endl;
                cout<<"Total Distance: "<< distance << " KM" << endl;
            }
            break;
        }


        case 2:{
            string departure; 
            string final_; 
            cout << "Enter the departure location, or enter 'comp' to use \n'Beijing Capital ";
            cout << "International Airport' as departure, \n'Gold Coast Airport' as final destination, ";
            cout << "and \n'Dallas Fort Worth International Airport' ";
            cout << "as the selected landmark:\n";
            cin.ignore();
            getline(std::cin, departure);

            if(departure == "comp"){
                Landmark l1 = Landmark(airportGraph, "Beijing Capital International Airport", "Dallas Fort Worth International Airport", 
                                                    "Gold Coast Airport");
                
                double distance = l1.getDist();
                vector<string> path = l1.getPath();

                cout<<"Airports Visited during Transit: \n"<<endl;
                unsigned long i = 0;
                while (i < path.size()) {
                    cout<< path[i] <<endl;
                    i++;
                }
                cout<<""<<endl;
                cout<<"Total Distance: "<< distance << " KM" << endl;
            } else {
                string lndmrk;
                cout << "Enter the final destination:\n";
                getline(std::cin, final_);
                cout << "Enter the landmark:\n";
                getline(std::cin, lndmrk);
                Landmark l1 = Landmark(airportGraph, departure, lndmrk, final_);
                
                vector<string> path = l1.getPath();
                double distance = l1.getDist();

                if(distance == 0.0){
                    cout<< "Airport not found"<<endl;
                    break;
                }
                cout<<"Airports Visited: \n"<<endl;
                unsigned long i = 0;
                while (i < path.size()) {
                    cout<< path[i] <<endl;
                    i++;
                }
                cout<<""<<endl;
                cout<<"Total Distance: "<< distance << " KM" << endl;   
            }
            break;

            
        }
        default: cout << "Enter only 1 or 2" << endl;

        
    }
    
    return 0;
}
