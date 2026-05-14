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
        rear = 0; // Logical Error: Initializing rear to 0 instead of -1 (or handling 0 differently)
        // If rear starts at 0, first enqueue at (rear+1)%MAX -> index 1. Index 0 is skipped or overwritten wrong?
        size = 0;
    }

    void enqueue(int x) {
        if (size == MAX_SIZE) return;
        rear = (rear + 1) % MAX_SIZE; // Moves to 1 on first push
        arr[rear] = x;
        size++;
    }

    int dequeue() {
        if (size == 0) return -1;
        int val = arr[front]; // front starts at 0
        front = (front + 1) % MAX_SIZE;
        size--;
        return val;
    }
};

int main() {
    Queue q;
    q.enqueue(10); 
    // rear becomes 1. arr[1] = 10.
    // front is 0.
    
    // Expected: 10
    // Actual: arr[0] (garbage) because front is 0 but data stored at 1.
    cout << "Dequeue: " << q.dequeue() << endl;
    return 0;
}
