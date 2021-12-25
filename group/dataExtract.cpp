#include "dataExtract.h"

using namespace std;

//  Constructor
OpenFlights::OpenFlights(const string &airport, const string &route) {
    airport_ = airport;
    route_ = route;
    insertAirports();
    insertFlights();
}


// Takes each CSV line and puts in separate vectors
// Quotation mark sanitazation for output vector
// Input example: " item1, "item2", ... "
// Output example: vector([0]: item1, [1]: item2, [2]: ...)
vector<string> OpenFlights::parser(const string &line) {
    char curr;
    bool quotePresent = false;
    string builtStr = "";
    vector<string> outputStrings;

    // Cycle through all characters
    for(size_t i = 0; i < line.size(); ++i) {
        curr = line[i];

        // Pushes string into vector when comma found
        if(!quotePresent) {
            if(curr == '"')
                quotePresent = true;
            else if(curr == ',') {
                outputStrings.push_back(builtStr);
                builtStr = string();
            }
            else
                builtStr += curr;
        }

        // Checks for matching quotation marks and removes from output
        else {
            if(curr == '"' && i+1 < line.size()) {
                if(line[i+1] == '"') {
                    builtStr += '"';
                    ++i;
                }
                else
                    quotePresent = false;
            }
            else
                builtStr += curr;
        }
    }
    return outputStrings;
}


//  airports are added to the map
void OpenFlights::insertAirports() {
    ifstream input_file(airport_.c_str());
    string lines;

    // each line is put into a vector
    while(getline(input_file, lines)) {
        vector<string> line = parser(lines);
        map_.insertNode(line);
    }
    //manually inserting first line due to some bug causing first line to not be read
    map_.insertNode(vector<string>{string("1"),string("Goroka Airport"),string("Goroka"),string("Papua New Guinea"),string("GKA"),string("AYGA"),
                            string("-6.081689834590001"),string("145.391998291"),string("5282"),string("10"),string("U"),string("Pacific/Port_Moresby"),
                            string("airport"),string("OurAirports")});
    input_file.close();
}

//  adds flights connecting airports on map
void OpenFlights::insertFlights() {
    ifstream input_file(route_.c_str());
    string lines;

    // Seperates each line into vectors, and connects airports on map (without distances calculated)
    while(getline(input_file, lines)) {
        vector<string> line = parser(lines);
        map_.insertEdge(line);
    }
    //getting a bug that the first line of file is not being parsed above -- manual insert
    map_.insertEdge(vector<string>{string("2B"),string("410"),string("AER"),string("2965"),string("KZN"),string("2990"),string(""),string("0"),string("CR2")});
    input_file.close();
}


tuple<vector<string>,double> OpenFlights::landmark(string start, string landmark, string destination) {
    tuple<vector<string>,double> firstPath = Dijkstra::Dijkstra_function(FlightMap mapper, string start, string landmark);
    tuple<vector<string>,double> secondPath = Dijkstra::Dijkstra_function(FlightMap mapper, string landmark, string destination)
    if (get<0>(firstPath).empty() || get<0>(secondPath).empty()) {  //  no path could be found between start and destination while stopping at landmark
        tuple<vector<string>,double> T;
        return T;
    }
    vector<string> path = get<0>(firstPath);    //  append paths together
    path.insert(path.end(), get<0>(secondPath).begin()+1, get<0>(secondPath).end());
    double distance = get<1>(firstPath) + get<1>(secondPath);   //  add distances together
    tuple<vector<string>,double> shortestPath(path, distance);    //  create tuple of path and total distance
    return shortestPath;
}
