#pragma once
#include <string>
using namespace std;

class Event {
private:
    string type;
    int at;
    int id;
    string Vtype;
    int intid;
    int ln;
    int XD;
    int DUR;
    int PR;
    bool cargoflag;

public:
    Event(string t, int event_id, int ar, int interid, string vt, int lane, int xd, int pr, bool cargo);
    Event(string t, int event_id, int ar, int interid);
    Event(string t, int event_id, int ar, int interid, int dur);

    string gettype();
    int getat();
    int getid();
    string getVtype();
    int getintid();
    int getln();
    int getXD();
    int getPR();
    bool getcargoflag();
    int getDUR();
};
