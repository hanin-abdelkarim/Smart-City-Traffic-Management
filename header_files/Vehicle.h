#pragma once
#include <string>
using namespace std;

class Vehicle {
private:
	string type;
	int ID;
	int arrivaltime;
	int intersectionid;
	int laneid;
	int crossingduration;
	int priorityscore;
	bool cargoflag;

public:
	Vehicle(string t,int id,int at,int intid,int ln,int xd,int pr=0,bool cargo=false);
	string gettype();
	int getid();
	int getarrivaltime();
	int getintersectionid();
	int getlaneid();
	int getcrossingduration();
	int getpriorityscore();
	bool getcargoflag();
	void setpriorityscore(int pr);
	void setcargoflag(bool cargo);
};
