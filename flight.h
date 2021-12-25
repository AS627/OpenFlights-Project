#pragma once

class Flight {
    public:
        //default constructor
        Flight();
        //constructor without given weight
        Flight(int s, int d);
        //constructor with everything
        Flight(int s, int d, double w);

        //getters
        int getSID();       
        int getDID();         
        double getWeight();
       
        //setters
        void setWeight(double w);
        void setSource(double s);
        void setDestination(double d); 

        //operator overloading
        //"<" is potentially used when comparing weight of edges in later algorithms
        bool operator<(const Flight& other) const;
        //"==" is potentially used when checking if two edges are the same in later algorithms
        bool operator==(Flight& other) const;
    
    private:
        //source airport ID
        int source_Airport;
        //destination airport ID
        int destination_Airport;
        //distances in KM between two airports
        double weight;
};