# pragma once
# include <string>
# include "Mapper.h"

using namespace std;
class Route{
    public:
        Route(string IATA, Mapper& here, Mapper& destination, unsigned int stops);
        const Mapper& getHereAirport() const;
        const Mapper& getDestinationAirport() const;
        unsigned int getNumStops() const;

    private:
        string IATA_code_;
        Mapper hereport_;
        Mapper destport_;
        unsigned int num_stops_;
};
