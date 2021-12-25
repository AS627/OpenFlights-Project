#include "flight.h"
#include <limits.h>

Flight::Flight(){
    destination_Airport = -1; 
    weight = INT_MAX;
    source_Airport = -1;
       
};


Flight::Flight(int s, int d){
    destination_Airport = d; 
    weight = INT_MAX;
    source_Airport =s;
};

Flight::Flight(int s, int d, double w){
    destination_Airport = d; 
    weight = w;
    source_Airport = s;
};

int Flight::getSID() {
    return source_Airport;
}


int Flight::getDID() {
    return destination_Airport;
}


double Flight::getWeight() {
    return weight;
}

void Flight::setWeight(double w) {
    weight = w;
}

void Flight::setSource(double s) {
    source_Airport = s;
}

void Flight::setDestination(double d) {
    destination_Airport = d; 
}

bool Flight::operator<(const Flight& other) const {
    return weight < other.weight;
}

bool Flight::operator==(Flight& other) const {
    if (source_Airport != other.source_Airport)
        return false;
    if (destination_Airport != other.destination_Airport)
        return false;
    return true;
}