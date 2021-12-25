#include "Graph.h"
#include "BFS.h"
#include "dijkstra.h"
#include "dataExtract.h"
#include "mapper.h"

#include <string>

using namespace std;

int main() {
    string airport_file = "airports.dat";
    string route_file = "routes.dat";

    cout << "extracting data..." <<endl;
    OpenFlights data_extract(airport_file, route_file);
    cout << "data extracted..." << endl;

    FlightMap mapper;
    Graph graph;
    
    cout << "BFS algorithm" << endl;
    BFS bfs_test;
    vector<mapper> bfs_result = bfs_test.traverseBFS(mapper, graph);
    
    for (int i = 0; i < 5; i++) {
        cout << bfs_result[i] << endl;
    }

    cout << "land mark algorithm" << endl;
    string input_start;
    string input_end;
    string landmark;
    cout << "Type in an airport to start from:";
    cin >> input_start;
    cout << "Type in the destination airport:";
    cin >> input_end;
    cout << "Type in a landmark airport";
    cin >> landmark;
    data_extract.landmark(input_start, landmark, input_end);

    Dijkstra dijkstra_test;
    int destination;
    pair<vector<string>, double> result = dijkstra_test.Dijkstra_function(graph, mapper, destination);

    
}