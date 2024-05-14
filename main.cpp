#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "TennisWinners.h"
#include "Queue.h"
#include "Stack.h"

using namespace std;

int main() {

    // showing my queue class using ints and strings
    Queue<int> intQue;
    intQue.push(10);
    intQue.push(24);
    intQue.push(34);
    cout << "printing the que of 3 ints" << endl;
    intQue.printQueue();
    intQue.pop();
    cout << "printing the que after one item has been removed" << endl;
    intQue.printQueue();
    cout << "using the isInQueue method test" << endl;
    cout << "Prints 0 because it is false: " << intQue.isInQueue(10) << endl;
    cout << "Prints 1 becasue it is true: " << intQue.isInQueue(24) << endl;

    // showing my queue class works using strings
    Queue<string> stringQue;
    stringQue.push("Drew");
    stringQue.push("random stuff to fill these strings");
    stringQue.push("more random stuff");
    cout << "Printing the queue" << endl;
    stringQue.printQueue();
    stringQue.pop();
    cout << "Printing the queue after removing the first item" << endl;
    stringQue.printQueue();
    cout << "Showing the isInQueue method works" << endl;
    cout << "Prints 0 because it is false: " << stringQue.isInQueue("stuff") << endl;
    cout << "Prints 1 because it is true: " << stringQue.isInQueue("random stuff to fill these strings") << endl;

    // creates the vector of all the tenniswinners objects
    vector<TennisWinners> tWinners;
    getTennisWinnersFromFile("TennisWins2000.csv", tWinners);

    // creat the stack and the queue
    Stack<TennisWinners> twStack;
    Queue<TennisWinners> twQueue;

    for(int i = 0; i < 10; i++){
        twQueue.push(tWinners[i]);
    }

    cout << "The beginning of the Queue" << endl;
    for(int i = 0; i < 10; i++){
        cout << twQueue.pop() << endl;
        twStack.push(tWinners[i]);
    }

    cout << "The beginning of the Stack" << endl;
    for(int i = 0; i < 10; i++){
        cout << twStack.pop() << endl;
    }


    // returning 0 means there were no errors in the run any other number means error
    return 0;
}
