#pragma once
#include <string>
#include "LinkedList.h"
#include "Queue.h"
#include "PriorityQueue.h"
#include "Event.h"
#include "Intersection.h"
#include "Lane.h"
#include "Vehicle.h"

#define MAX_INTERSECTIONS 100
#define MAX_LANES 10

enum SimulationMode {
    SILENT,
    STEP_BY_STEP,
    INTERACTIVE
};

class Simulator {
private:
    LinkedList<Intersection> intersectionList;
    PriorityQueue<Event> eventQueue;
    LinkedList<Vehicle> CanceledVehicles;
    LinkedList<Vehicle> CompletedVehicles;
    LinkedList<Vehicle> ActiveVehicles;
    LinkedList<Vehicle> CrossingVehicles;
    LinkedList<Event> ProcessedEvents;
    bool rerouting;
    Queue<int> rerouteQueue;
    LinkedList<Vehicle> UI_PrintList;
    SimulationMode mode;
    bool BlockedLanes[MAX_INTERSECTIONS][MAX_LANES];
    bool BlockedIntersections[MAX_INTERSECTIONS];


    int currentTime;
    int maxSimulationTime;
    int intersectionsCount;
    int AutoArrival;
    int cancelT;
    int SwitchingCost;
    int totalVehicles;
    int completedVehicles;
    int canceledVehicles;
    int totalWaitingTime;
    int totalCrossingTime;
    int laneSwitchCount;
    int autoPromotedCount;


    void processEventsAtTime(int t);
    void handleArrival(Event* e);
    void handleCancel(Event* e);
    void handlePromotion(Event* e);
    void handleAccident(Event* e);
    void handleRoadClosure(Event* e);
    void scheduleIntersections();
    void scheduleIntersection(Intersection* inter);
    void processCrossing();
    bool rerouteVehicle(Vehicle* v);
    void lockLane(int interId, int laneId, int duration);
    void unlockLane(int interId, int laneId);
    void lockIntersection(int interId, int duration);
    void unlockIntersection(int interId);
    bool isSimulationDone() const;

public:
    Simulator();
    ~Simulator();

    void loadInputFile(const std::string& filename);
    void setMode(SimulationMode m);
    void run();
    void printUI();
    void printDebugOutput();
    void printStats();
    void generateOutput(const std::string& filename);
};