#include "Intersection.h"
Intersection::Intersection(int intid, int nl) {
    id = intid;
    numlanes = nl;
    isclosed = false;
    closeduntil = 0;
    lanes = new Lane * [numlanes];
    for (int i = 0; i < numlanes; i++) {
        lanes[i] = new Lane(i);
    }
    activelane = lanes[0];
}
Intersection::~Intersection() {
    for (int i = 0; i < numlanes; i++) {
        delete lanes[i];
    }
    delete[] lanes;
}
    int Intersection::getid() { return id; }
    bool Intersection::getisclosed() { return isclosed; }
    int Intersection::getcloseduntil() { return closeduntil; }
    int Intersection::getnumlanes() { return numlanes; }
    Lane& Intersection::getlane(int laneid) { return  *lanes[laneid]; }
    Lane* Intersection::getactivelane() { return activelane; }
    void Intersection::setactivelane(Lane * lane) { activelane = lane; }
    void Intersection::setisclosed(bool closed) { isclosed = closed; }
    void Intersection::setcloseduntil(int time) { closeduntil = time; }

    // Phase 2
    int Intersection::chooseBestLane() {
        if (isclosed) { return -1; }
        for (int i = 0; i < numlanes; i++) {
            Lane* currentLane = lanes[i];
            if (currentLane->isFree() && !currentLane->getEVqueue().isEmpty()) {
                return i;
            }
        }
        for (int i = 0; i < numlanes; i++) {
            Lane* currentLane = lanes[i];
            if (currentLane->isFree() && !currentLane->getPTqueue().isEmpty()) {
                return i;
            }
        }
        for (int i = 0; i < numlanes; i++) {
            Lane* currentLane = lanes[i];
            if (currentLane->isFree() && !currentLane->getFVqueue().isEmpty()) {
                return i;
            }
        }
        for (int i = 0; i < numlanes; i++) {
            Lane* currentLane = lanes[i];
            if (currentLane->isFree() && !currentLane->getNCqueue().isEmpty()) {
                return i;
            }
        }
        return -1;
    }
