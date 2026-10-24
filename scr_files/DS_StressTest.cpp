#include <iostream>
#include "Queue.h"
#include "LinkedList.h"
#include "PriorityQueue.h"
#include "Vehicle.h"
#include "Event.h"

using namespace std;

static void printResult(const string& testName, bool pass) {
    cout << (pass ? "[PASS] " : "[FAIL] ") << testName << "\n";
}

int main() {
    bool allPass = true;

    // ------------------------------------------------------------
    // TEST 1: Queue<int> enqueue/dequeue 10,000
    // ------------------------------------------------------------
    {
        Queue<int> q;
        const int N = 10000;
        for (int i = 1; i <= N; i++) q.enqueue(i);

        bool pass = (q.size() == N);

        for (int i = 1; i <= N; i++) {
            int x = -1;
            if (!q.dequeue(x)) { pass = false; break; }
            if (x != i) { pass = false; break; }
        }
        if (!q.isEmpty()) pass = false;
        if (q.size() != 0) pass = false;

        printResult("Queue<int> enqueue/dequeue 10,000", pass);
        allPass = allPass && pass;
    }

    // ------------------------------------------------------------
    // TEST 2: Queue<Vehicle*> enqueue/dequeue 5,000
    // ------------------------------------------------------------
    {
        Queue<Vehicle*> q;
        const int N = 5000;

        Vehicle** arr = new Vehicle*[N];

        for (int i = 0; i < N; i++) {
            // Vehicle(string t,int id,int at,int intid,int ln,int xd,int pr=0,bool cargo=false);
            arr[i] = new Vehicle("NC", 1000 + i, 0, 1, 0, 1, 0, false);
            q.enqueue(arr[i]);
        }

        bool pass = (q.size() == N);

        for (int i = 0; i < N; i++) {
            Vehicle* v = nullptr;
            if (!q.dequeue(v)) { pass = false; break; }
            if (v != arr[i]) { pass = false; break; } // pointer equality
        }

        if (!q.isEmpty()) pass = false;
        if (q.size() != 0) pass = false;

        // delete objects
        for (int i = 0; i < N; i++) delete arr[i];
        delete[] arr;

        printResult("Queue<Vehicle*> enqueue/dequeue 5,000", pass);
        allPass = allPass && pass;
    }

    // ------------------------------------------------------------
    // TEST 3: PriorityQueue<Event*> ordering
    // ------------------------------------------------------------
    {
        PriorityQueue<Event*> pq;

        Event* e1 = new Event("A", 1, 5, 1, "NC", 0, 1, 0, false);  
        Event* e2 = new Event("C", 2, 3, 1);                       
        Event* e3 = new Event("P", 3, 4, 1);                      

        pq.enqueue(e1, 10);
        pq.enqueue(e2, 30);
        pq.enqueue(e3, 20);

        bool pass = true;
        Event* out = nullptr;

        if (!pq.dequeue(out) || out != e2) pass = false; // 30 first
        if (!pq.dequeue(out) || out != e3) pass = false; // 20 second
        if (!pq.dequeue(out) || out != e1) pass = false; // 10 third
        if (!pq.isEmpty()) pass = false;

        // delete events
        delete e1;
        delete e2;
        delete e3;

        printResult("PriorityQueue<Event*> ordering (bigger priority first)", pass);
        allPass = allPass && pass;
    }

    // ------------------------------------------------------------
    // TEST 4: LinkedList removeItem (first/middle/last)
    // ------------------------------------------------------------
    {
        LinkedList<int> list;
        list.Insert(10);
        list.Insert(20);
        list.Insert(30);
        list.Insert(40);
        list.Insert(50);

        bool pass = true;

        // remove first
        if (!list.removeItem(10)) pass = false;
        // remove middle
        if (!list.removeItem(30)) pass = false;
        // remove last
        if (!list.removeItem(50)) pass = false;

        // remove something not exist
        if (list.removeItem(999)) pass = false;

        // المفروض المتبقي: 20, 40 => size = 2
        if (list.getSize() != 2) pass = false;

        printResult("LinkedList removeItem (first/middle/last + not found)", pass);
        allPass = allPass && pass;
    }

    cout << "---------------------------------------\n";
    cout << (allPass ? "ALL TESTS PASSED ✅\n" : "SOME TESTS FAILED ❌\n");
    return allPass ? 0 : 1;
}
