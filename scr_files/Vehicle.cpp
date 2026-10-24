#include "Vehicle.h"
#include <string>
Vehicle::Vehicle(string t,int id,int at,int intid, int ln, int xd, int pr,bool cargo){
    type=t;
    ID=id;
    arrivaltime=at;
    intersectionid= intid;
    laneid=ln;
    crossingduration=xd;
    priorityscore= pr;
    cargoflag =cargo;
}
string Vehicle::gettype() { return type; }
int Vehicle::getid() { return ID; }
int Vehicle::getarrivaltime() { return arrivaltime; }
int Vehicle::getintersectionid() { return intersectionid; }
int Vehicle::getlaneid() { return laneid; }
int Vehicle::getcrossingduration() { return crossingduration; }
int Vehicle::getpriorityscore() { return priorityscore; }
bool Vehicle::getcargoflag() { return cargoflag; }
void Vehicle::setpriorityscore(int pr) {priorityscore = pr;}
void Vehicle::setcargoflag(bool cargo) {cargoflag = cargo; }

