#pragma once
#include "LinkedList.h"
#include "Node.h"

class Graph {
private:
    int n;                  
    LinkedList<int>* adj;     

public:
    Graph() : n(0), adj(nullptr) {}
    Graph(const Graph&) = delete;
    Graph& operator=(const Graph&) = delete;
    void init(int N) {
        if (adj != nullptr) {
            delete[] adj;
            adj = nullptr;}
        n = N;
        adj = new LinkedList<int>[n + 1]; 
    }

    int getCount() const { return n; }

    bool isValid(int a) const {
        return (a >= 1 && a <= n);}

    void addEdge(int a, int b) {
        if (!isValid(a) || !isValid(b)) return;
        adj[a].Insert(b);}

    Node<int>* getNeighborHead(int a) {
        if (!isValid(a)) return nullptr;
        return adj[a].getHead();
    }

    ~Graph() {
        if (adj != nullptr) {
            delete[] adj;
            adj = nullptr;
        }
        n = 0;
    }
};