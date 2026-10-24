#pragma once
#include <string>
using namespace std;
#include "Lane.h"
class Intersection {
private:
    int id;
    Lane** lanes;
    int numlanes;
    bool isclosed;
    int closeduntil;
    Lane* activelane;
public:
    Intersection(int intid, int nl);
    ~Intersection();
    int getid();
    Lane& getlane(int laneid);
    bool getisclosed();
    int getcloseduntil();
    Lane* getactivelane();
    int getnumlanes();
    void setisclosed(bool closed);
    void setcloseduntil(int time);
    void setactivelane(Lane* lane);
    int chooseBestLane();
};