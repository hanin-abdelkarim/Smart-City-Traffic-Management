#include "Lane.h"

Lane::Lane( int id=0) {
    laneid = id;
    currentvehicle = nullptr;
    isblocked = false;
    remainingcrossingtime = 0;
    blockeduntil = 0;
}
Lane::~Lane() {}
    Queue<Vehicle*>& Lane::getEVqueue() { return EV_queue; }
    Queue<Vehicle*>& Lane::getPTqueue() { return PT_queue; }
    Queue<Vehicle*>& Lane::getNCqueue() { return NC_queue; }
    Queue<Vehicle*>& Lane::getFVqueue() { return  FV_queue; }
    void Lane::setEVqueue(const Queue<Vehicle*>&q) { EV_queue = q; }
    void Lane::setPTqueue(const Queue<Vehicle*>&q) { PT_queue = q; }
    void Lane::setNCqueue(const Queue<Vehicle*>&q) { NC_queue = q; }
    void Lane::setFVqueue(const Queue<Vehicle*>&q) { FV_queue = q; }
    bool Lane::getIsblocked()const { return isblocked; }
    Vehicle* Lane::getcurrentvehicle() { return currentvehicle; }
    void Lane::setcurrentvehicle(Vehicle * v) { currentvehicle = v; }
    void Lane::setremainingcrossingtime(int time) { remainingcrossingtime = time; }
    void Lane::setblockeduntil(int time) { blockeduntil = time; }
    bool Lane::iscurrentlyblocked(int currenttime) {
        if (!isblocked) return false;
        else if (blockeduntil > currenttime) return true;
        return false;
    }
    int Lane::getremainingcrossingtime() { return remainingcrossingtime; }
    int Lane::getblockeduntil() { return blockeduntil; }
    void Lane::setIsblocked(bool blocked) { isblocked = blocked; }
    int Lane::getlaneid() { return laneid; }
    //Phase 2

    Vehicle* Lane::assignNextVehicle() {
        {
            if (isLockedByFV()) {
                return nullptr;
            }
        if (isblocked || currentvehicle != nullptr) {
            return nullptr;
        }
        if (!EV_queue.isEmpty()) {
            Vehicle* ev = nullptr;
            EV_queue.dequeue(ev);
            currentvehicle = ev;
            remainingcrossingtime = ev->getcrossingduration();
            return ev;
        }
        if (!PT_queue.isEmpty()) {
            Vehicle* pt = nullptr;
            PT_queue.dequeue(pt);
            currentvehicle = pt;
            remainingcrossingtime = pt->getcrossingduration();
            return pt;
        }
        if (!FV_queue.isEmpty()) {
            Vehicle* fv = nullptr;
            FV_queue.dequeue(fv);
            currentvehicle = fv;
            remainingcrossingtime = fv->getcrossingduration();
            return fv;
        }
        if (!NC_queue.isEmpty()) {
            Vehicle* nc = nullptr;
            NC_queue.dequeue(nc);
            currentvehicle = nc;
            remainingcrossingtime = nc->getcrossingduration();
            return nc;
        }
        return nullptr;
    }

    bool Lane::updateCrossing() {
        if (currentvehicle == nullptr) {
            return false;
        }
        remainingcrossingtime--;
        if (remainingcrossingtime <= 0) {
            currentvehicle = nullptr;
            return true;
        }
        return false;
    }
    bool Lane::isLockedByFV() const {
        return (currentvehicle != nullptr && currentvehicle->gettype() == "FV");
    }
    bool Lane::isFree() const {
        return (currentvehicle == nullptr && !isblocked && !isLockedByFV());
    }
