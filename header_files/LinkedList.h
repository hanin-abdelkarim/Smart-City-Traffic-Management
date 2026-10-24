#pragma once
#include "Node.h"

template <typename T>
class LinkedList {
private:
	Node<T>* head;
	Node<T>* tail;
	int size;
public:
	LinkedList() {
		tail = nullptr;
		head = nullptr;
		size = 0;
	}

	LinkedList(const LinkedList&) = delete; //34an nemna3 ay copy
	LinkedList& operator=(const LinkedList&) = delete;

	bool isEmpty() { 
		return head == nullptr;
	}

	int getSize() const { 
		return size;
	}

	void Insert(const T& value) {
		Node<T>* Temp = new Node<T>(value);
		if (head == nullptr) {
			head = tail = Temp;
		} else {
			tail->setNext(Temp);
			tail = Temp;
		}
		size++;
	}

	void Remove() {
		if (head == nullptr) return;

		Node<T>* current = head;
		head = head->getNext();
		if (head == nullptr) {
			tail = nullptr;
		}
		delete current;
		size--;
	}

	bool RemoveFront(T& out) { 
		if (head == nullptr) return false;

		out = head->getItem();  
		Remove();               
		return true;
	}

	bool removeItem(const T& value) { 
		Node<T>* previous = nullptr;       
		Node<T>* current = head;           

		while (current != nullptr) {      
			if (current->getItem() == value) { 
				if (previous == nullptr) {     
					head = current->getNext(); 
					 
					if (head == nullptr) {       
        				tail = nullptr;           
					 }
				} else {
					previous->setNext(current->getNext()); 
				}

				if (current == tail) {         
					tail = previous;         
				}

				delete current;               
				size--;                   
				return true;              
			}

			previous = current;                   
			current = current->getNext();        
		}

		return false;                     
	}

	Node<T>* getHead() { 
		return head;
	}

	~LinkedList() {
		while (!isEmpty()) {
			Remove();
		}
	}
};
