//Airport Class
#include "airport_mapper.h"
#include <string>

using namespace std;

Airport::Airport(){
    AID = 0;
    AN = "";
    AC = "";
    ACount = "";
    A_lat = 0.0;
    A_long = 0.0;
}


Airport::Airport(int id, string name, string city, string country, double latitude, double longitude)
: AID(id), AN(name), AC(city), ACount(country), A_lat(latitude), A_long(longitude) {  }


Airport::Airport(string &line){
    
    bool q_flag = false;
    std::string curr = "";
    std::vector<std::string> vector_airport;

    
    for(size_t i = 0; i < line.size(); ++i){
        char curr2 = line[i];
        bool check1 = curr2 == '"';
        if(q_flag) {
            
            bool check = !(check1) || !(i+1 < line.size()) ;
            if(!check) {
                if(line[i+1] != '"') {
                    q_flag = false;
                }
                else {
                    curr += '"';
                    i++;
                } 
            }
            
            else
                curr += curr2;
        }
       
        else{
            if(check1) {
                
                q_flag = true;
            }
            
            else if(curr2 ==',') {
                vector_airport.push_back(curr);
                curr = "";
            }
            
            else
                curr += curr2;
            
        }
    }
    
    AID = stoi(vector_airport[0], nullptr);
    AN = vector_airport[1];
    AC = vector_airport[2];
    ACount = vector_airport[3];
    A_lat = stod(vector_airport[6], nullptr);
    A_long = stod(vector_airport[7], nullptr);
}


Airport::Airport(vector<string> vector_airport){
    AID = stoi(vector_airport[0], nullptr);
    AN = vector_airport[1];
    AC = vector_airport[2];
    ACount = vector_airport[3];
    A_lat = stod(vector_airport[6], nullptr);
    A_long = stod(vector_airport[7], nullptr);
}


int Airport::getAID() {return AID;}
string Airport::getAN() {return AN;}
string Airport::getAC() {return AC;}
string Airport::getACount() {return ACount;}
double Airport::get_Alat() {return A_lat;}
double Airport::get_Along() {return A_long;}