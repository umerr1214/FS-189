#include <iostream>
using namespace std;

const int MAX_SIZE = 2; // Small for testing

class Queue {
private:
    int arr[MAX_SIZE];
    int front, rear; // Missing size tracking for circular queue with this logic?
    // Without size, we need front/rear logic (empty if front==-1, full if ...).
    // Let's implement robust-less logic.

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int x) {
        // Robustness Issue: No overflow check.
        // In circular queue, if we just increment, we overwrite old data.
        // Which might be desired (ring buffer) or bug (queue overflow).
        // Standard Queue throws overflow.
        // Also simple linear increment without mod?
        
        // If we implement linear queue without shift/circular:
        if (rear == MAX_SIZE - 1) {
            // Full? 
            // If we assume linear, once rear hits end, it's full even if front moved.
            // But let's assume no check at all.
        }
        
        arr[++rear] = x; // Buffer overflow if rear >= MAX_SIZE-1
    }

    int dequeue() {
        // Robustness Issue: No underflow check.
        return arr[front++]; // Reads OOB if front > rear? Or front initial -1 -> OOB.
        // Front starts at -1. ++front -> 0.
        // But if empty?
    }
};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3); // Overflow writing to arr[2] (size 2 is indices 0,1)
    return 0;
}
