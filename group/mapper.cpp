#include "mapper.h"

void FlightMap::insertNode(vector<string> line) {
    node airport;
    airport.id = atoi(line[A_ID].c_str());
    airport.latitude = atof(line[A_LAT].c_str());
    airport.longitude = atof(line[A_LONG].c_str());
    airportMap.insert(pair<int, node>(airport.id, airport));
    string code;
    code = line[A_IATA];
    transform(code.begin(), code.end(), code.begin(), [](unsigned char c){return toupper(c); });
    airport.code = code;
    
    idToCodeMap.insert(pair<int, string>(airport.id, airport.code));
    codeToIdMap.insert(pair<string, int>(airport.code, airport.id));
}

void FlightMap::insertEdge(vector<string> line) {
    int source = atoi(line[R_SID].c_str());
    int dest = atoi(line[R_DID].c_str());
    double weight = findDist(source, dest);
    Edge flight(source, dest, weight);
    if (airportMap[source].departures.find(dest) == airportMap[source].departures.end())    //  checks for existing edge
        airportMap[source].departures.insert(pair<int, Edge>(dest, flight));
}

//  Uses Haversine formula to calculate the distance between 2 points on a Earth
double FlightMap::findDist(int start, int dest) {
   
    double rad = 6371; //  average radius of Earth in km
    double phi1 = airportMap[start].latitude * M_PI/180;  //  convert to radians
    double phi2 = airportMap[dest].latitude * M_PI/180;
    double lambda1 = airportMap[start].longitude* M_PI/180;
    double lambda2 = airportMap[dest].longitude* M_PI/180;
    double deltaPhi = phi2 - phi1;
    double deltaLambda = lambda2 - lambda1;

    double a = ( sin(deltaPhi/2)*sin(deltaPhi/2) ) + cos(phi1) * cos(phi2) * ( sin(deltaLambda/2)*sin(deltaLambda/2) );
    double c = 2 * atan2(sqrt(a), sqrt((1-a)));
    double d = rad * c;

    return d;  //  returns distance (in km)
}
