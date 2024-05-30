#include "PriorityQueue.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main(){
    PriorityQueue<int> p1;
    PriorityQueue<int> p2;

    p1.Enqueue(1);
    p1.Enqueue(3);
    p1.Enqueue(8);
    p1.Enqueue(7);
    p1.Enqueue(2);

    p2.Enqueue(4);
    p2.Enqueue(10);
    p2.Enqueue(5);
    p2.Enqueue(9);
    p2.Enqueue(6);
    
    p1.MergeQueue(p2);

    // Print the contents of the queue using the overloaded operator<<
    std::cout << p1;
    std::cout << p2;
}