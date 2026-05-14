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

    bool isFull() {
        return size == MAX_SIZE;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow" << endl;
            return;
        }
        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = x;
        size++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        int val = arr[front];
        front = (front + 1) % MAX_SIZE;
        size--;
        return val;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        return arr[front];
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    
    cout << "Dequeue: " << q.dequeue() << endl; // 10
    cout << "Peek: " << q.peek() << endl; // 20
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60); // Full now (size 5)
    q.enqueue(70); // Overflow
    
    return 0;
}
