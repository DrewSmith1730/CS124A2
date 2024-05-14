//
// Created by drews on 9/26/2020.
//

#ifndef CS124_QUEUE_H
#define CS124_QUEUE_H

#include <iostream>
#include "Node.h"

template<typename T>
class Queue{
private:
    // Store the location of the
    Node<T>* first;
    Node<T>* last;

public:
    // Constructor
    Queue(){
        // first in the queue to get out
        first = nullptr;
        // last in the queue to be added
        last = nullptr;
    }

    // Destructor
    ~Queue(){
        while (first != nullptr){
            pop();
        }
    }

    // push will add a node to the end of the queue
    /**
     * push() adds a new node to the queue
     * @param item the value of the node your adding
     */
    void push(T item){
        // Goal is to creat a new node at the correct spot in the queue determine its position with an if statement first
        if (first == nullptr) { // --> only works if the list is empty
            Node<T>* newNode = new Node<T>(item, first);
            // add this node to the front and the end of the list
            first = newNode;
            last = newNode;
        }else { // --> if the list is not empty then add to the last position in the queue
            Node<T> *newNode = new Node<T>(item);
            // add this node to the last position and point to the previous last node
            last->setNext(newNode);
            last = newNode;
        }
    }

    // Pop will remove and return the Object from the frount of the Queue
    /**
     * pop() removes the node at the front of the queue
     * @return the node that was removed
     */
    T pop(){
        if (first == nullptr){
            // if the queue is empty this returns nothing and pops nothing
            return T();
        }
        // copy of the first node in the queue
        Node<T>* firstCopy = first;
        T item = firstCopy->getItem();
        // update the first node
        first = first->getNext();

        // deallocate the node memory
        // call delete on the pointer to the heap memory i want to deallocate
        delete firstCopy;
        // return the item in the first node
        return item;
    }

    /**
     * prints the nodes off in order from first to last
     */
    void printQueue(){
        std::cout << "Beginning of the Queue" << std::endl;
        Node<T>* curr = first;
        while (curr != nullptr){
            std::cout << curr->getItem() << std::endl;
            curr = curr->getNext();
        }
        std::cout << "End of the Queue" << std::endl;
    }

    // Returns true if item is in the queue, returns false if not
    /**
     * isinQueue tests if the value given is in the queue
     * @param item what is being searched for
     * @return a boolean of true or false
     */
    bool isInQueue(T item){
        // makes a copy of the queue
        Node<T>* curr = first;
        // loops through the queue to find if item is in it
        while (curr != nullptr){
            if (curr->getItem() == item){
                return true;
            }
            curr = curr->getNext();
        }
        // item is not in the queue
        return false;
    }
};


#endif //CS124_QUEUE_H
