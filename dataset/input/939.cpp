#include <iostream>
using namespace std;

const int MAX_SIZE = 5;

class Queue {
private:
    int arr[MAX_SIZE];
    int front, rear, size;

public:
    Queue() {
        front = 0;
        rear = -1;
        size = 0;
    }

    void enqueue(int x) {
        // Semantic Error: bitwise AND instead of logical AND? Not applicable here.
        // Assignment in condition?
        // if (size = MAX_SIZE) // Sets size to MAX, returns true. Queue full immediately.
        
        if (size = MAX_SIZE) { // Semantic Error: Assignment
             cout << "Queue Overflow" << endl;
             return;
        }
        
        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = x;
        size++;
    }
    
    // ...
};

int main() {
    Queue q;
    // Expected: Enqueues 10.
    // Actual: "Queue Overflow", size becomes 5.
    q.enqueue(10);
    return 0;
}
