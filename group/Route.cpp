#include "Route.h"


Route::Route(string IATA, Mapper& here, Mapper& destination, unsigned int stops){
    IATA_code_ = IATA;
    num_stops_ = stops;

}

const Mapper& Route::getHereAirport() const{
    return hereport_;
}

const Mapper& Route::getDestinationAirport() const{
    return destport_;
}

unsigned int Route::getNumStops() const{
    return num_stops_;
}
