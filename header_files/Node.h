#pragma once
template <typename T>

class Node
{
private:
    T item;                 
    Node<T>* next;          

public:
    Node(): item{}, next(nullptr) {}   

    Node(const T& Item) : item(Item), next(nullptr) {}

    Node(const T& Item, Node<T>* nextNodePtr) : item(Item), next(nextNodePtr) {}

    void setItem(const T& Item) {   
        item = Item;
    }

    void setNext(Node<T>* nextNodePtr) {
        next = nextNodePtr;
    }

    T& getItem() {               
        return item;
    }

    const T& getItem() const {    
        return item;
    }

    Node<T>* getNext() const {
        return next;
    }
};
