//
// Created by drews on 9/26/2020.
//

#ifndef CS124_STACK_H
#define CS124_STACK_H

/*
 * Stack class
 * Linked list with Nodes pointing from top to bottom
 */

#include <iostream>
#include "Node.h"

template<typename Object>
class Stack {
private:
    // Store the location of the top Node
    Node<Object>* top;

public:
    // Constructor
    Stack() {
        // The Stack is empty
        top = nullptr;
    }

    // Deconstructor aka Destructor
    ~Stack() {
        //std::cout << "Deleting Nodes from Stack" << std::endl;
        // Deallocate all remaining heap memory from the Stack
        while (top != nullptr) {
            // There is still a Node in the Stack
            pop();
        }
    }

    // Push will add a Node to the top of the Stack
    void push(Object item) {
        // Create a new Node that stores item and points to top
        // Use the new keyword to allocate heap memory
        Node<Object>* newNode = new Node<Object>(item, top);
        // Update top to point to the new Node
        top = newNode;
    }

    // Pop will remove and return the Object from the top of the Stack
    Object pop() {
        if (top == nullptr) {
            // The Stack is empty
            // There is nothing to pop
            // Return the default Object
            return Object();
        }
        // Store a copy of the Object to be returned
        Object item = top->getItem();
        // Store a copy of top
        Node<Object>* topCopy = top;
        // Update top
        top = top->getNext();
        // Deallocate the heap memory to remove the Node
        // Call delete on the pointer to the heap memory I want to deallocate
        delete topCopy;
        // Return the Object
        return item;
    }

    void printStack() {
        std::cout << "Beginning of Stack" << std::endl;
        // Make a copy of top
        Node<Object>* curr = top;
        // Iterate through the Stack from top to bottom
        while (curr != nullptr) {
            std::cout << curr->getItem() << std::endl;
            curr = curr->getNext();
        }
        std::cout << "End of Stack" << std::endl;
    }

    // Returns true if item is in the Stack, returns false otherwise
    bool isInStack(Object item) {
        // Make a copy of top
        Node<Object>* curr = top;
        // Iterate through the Stack from top to bottom
        while (curr != nullptr) {
            // This will require you to overload the == operator
            if (curr->getItem() == item) {
                // We found the item in the Stack
                return true;
            }
            curr = curr->getNext();
        }
        // We looked through the Stack and did not find the item
        return false;
    }
};



#endif //CS124_STACK_H
