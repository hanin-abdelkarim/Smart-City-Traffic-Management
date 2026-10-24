#pragma once
#include <string>
#include "Queue.h"
#include "Vehicle.h"
using namespace std;

class Lane {
private:
    int laneid;
    Queue<Vehicle*> EV_queue;  
    Queue<Vehicle*> PT_queue;  
    Queue<Vehicle*> NC_queue;  
    Queue<Vehicle*> FV_queue;  
    bool isblocked;
    Vehicle* currentvehicle;
    int remainingcrossingtime;
    int blockeduntil;
public:
    Lane(int id = 0);
    ~Lane();
    Queue<Vehicle*>& getEVqueue();  
    Queue<Vehicle*>& getPTqueue();  
    Queue<Vehicle*>& getNCqueue();  
    Queue<Vehicle*>& getFVqueue();  
    void setEVqueue(const Queue<Vehicle*>& q);  
    void setPTqueue(const Queue<Vehicle*>& q);  
    void setNCqueue(const Queue<Vehicle*>& q);  
    void setFVqueue(const Queue<Vehicle*>& q);  
    int getlaneid();
    bool iscurrentlyblocked(int currenttime);
    void setIsblocked(bool blocked);
    void setcurrentvehicle(Vehicle* v);
    void setblockeduntil(int time);
    Vehicle* getcurrentvehicle();
    void setremainingcrossingtime(int time);
    int getremainingcrossingtime();
    int getblockeduntil();
    bool getIsblocked() const;
    // phase2
    Vehicle* assignNextVehicle();
    bool updateCrossing();
    bool isFree() const;
    bool isLockedByFV() const;
};


