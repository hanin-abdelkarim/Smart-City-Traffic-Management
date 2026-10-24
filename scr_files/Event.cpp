#include "Event.h"

// Constructor for Arrival events
Event::Event(string t, int event_id, int ar, int interid, string vt, int lane, int xd, int pr, bool cargo) {
    type = t;
    id = event_id;
    at = ar;
    intid = interid;
    Vtype = vt;
    ln = lane;
    XD = xd;
    PR = pr;
    cargoflag = cargo;
    DUR = 0;
}

// Constructor for Cancellation and Promotion events
Event::Event(string t, int event_id, int ar, int interid) {
    type = t;
    id = event_id;
    at = ar;
    intid = interid;
    Vtype = "";
    ln = 0;
    XD = 0;
    PR = 0;
    cargoflag = false;
    DUR = 0;
}

// Constructor for Accident and Road Closure events
Event::Event(string t, int event_id, int ar, int interid, int dur) {
    type = t;
    id = event_id;
    at = ar;
    intid = interid;
    Vtype = "";
    ln = 0;
    XD = 0;
    PR = 0;
    cargoflag = false;
    DUR = dur;
}

string Event::gettype() { return type; }
int Event::getat() { return at; }
int Event::getid() { return id; }
string Event::getVtype() { return Vtype; }
int Event::getintid() { return intid; }
int Event::getln() { return ln; }
int Event::getXD() { return XD; }
int Event::getPR() { return PR; }
bool Event::getcargoflag() { return cargoflag; }
int Event::getDUR() { return DUR; }
