#pragma once
#include "Node.h"
#include "Queue.h"

template <typename T>
class PriorityNode {
public:
	T data;
	int priority;
	PriorityNode<T>* next;

	PriorityNode(const T& d, int p) {        
		data = d;
		priority = p;
		next = nullptr;
	}
};

template <typename T>
class PriorityQueue {
private:
	PriorityNode<T>* front;
	int sz;                                   

public:
	PriorityQueue() {
		front = nullptr;
		sz = 0;                                
	}

	PriorityQueue(const PriorityQueue&) = delete;      
	PriorityQueue& operator=(const PriorityQueue&) = delete; 

	bool isEmpty() const {                    
		return front == nullptr;
	}

	int size() const {                       
		return sz;
	}

	void enqueue(const T& value, int priority) {  
		PriorityNode<T>* node = new PriorityNode<T>(value, priority);

		if (front == nullptr || priority > front->priority) {
			node->next = front;
			front = node;
		}
		else {
			PriorityNode<T>* current = front;
			while (current->next != nullptr && current->next->priority >= priority) {
				current = current->next;
			}
			node->next = current->next;
			current->next = node;
		}
		sz++;                                
	}

	bool dequeue(T& value) {                 
		if (isEmpty())
			return false;

		PriorityNode<T>* temp = front;
		value = front->data;
		front = front->next;
		delete temp;
		sz--;                                 
		return true;
	}

	bool highestPriority(T& value) const {    
		if (isEmpty())
			return false;

		value = front->data;
		return true;
	}

	~PriorityQueue() {
		while (front != nullptr) {
            PriorityNode<T>* temp = front;
            front = front->next;
            delete temp;
        }
        sz = 0;
    };
};