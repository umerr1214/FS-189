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
        if (size == MAX_SIZE) {
            cout << "Queue Overflow" << endl;
            return;
        }
        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = x;
        size++;
    }

    int dequeue() {
        if (size == 0) {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        int val = arr[front];
        front = (front + 1) % MAX_SIZE;
        size--;
        return val;
    }

    bool isEmpty() {
        return size == 0;
    }
} // Syntax Error: Missing semicolon

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    cout << q.dequeue() << endl;
    return 0;
}
