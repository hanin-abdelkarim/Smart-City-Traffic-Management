#pragma once
#include "LinkedList.h"

template <typename T>
class Queue {
private:
    LinkedList<T> list;

public:
    Queue() {}

    Queue(const Queue&) = delete;             
    Queue& operator=(const Queue&) = delete;  

    bool isEmpty() {                           
        return list.isEmpty();
    }

    int size() const {                        
        return list.getSize();                 
    }

    void enqueue(const T& value) {             
        list.Insert(value);                  
    }

    bool dequeue(T& item) {                   
        return list.RemoveFront(item);         
    }

    bool front(T& item) {                     
        if (list.isEmpty())
            return false;

        item = list.getHead()->getItem();     
        return true;
    }
};
