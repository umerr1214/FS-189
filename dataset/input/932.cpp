#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Stack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = 0; // Logical Error: Initializing top to 0 instead of -1
        // If top points to the *next empty* slot, this is fine, but push/pop logic must match.
        // push: arr[top++] = x. pop: return arr[--top].
        // BUT here I will mix the logic.
    }

    void push(int x) {
        if (top >= MAX_SIZE) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[top++] = x; // Post-increment: stores at 0, increments to 1. Correct for "next empty".
    }

    int pop() {
        if (top <= 0) { // Check empty
            cout << "Stack Underflow" << endl;
            return -1;
        }
        return arr[top]; // Logical Error: Returns value at 'top' without decrementing?
        // Or decrementing incorrectly?
        // If top points to next empty, valid data is at top-1.
        // Returning arr[top] returns garbage (uninitialized slot).
        
        // Correct for this scheme: return arr[--top];
    }

    int peek() {
        if (top <= 0) {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return arr[top]; // Same error: peeking at empty slot
    }

    bool isEmpty() {
        return top == 0;
    }
};

int main() {
    Stack s;
    s.push(10);
    // top is 1. arr[0] = 10.
    
    // Expected: 10
    // Actual: arr[1] (garbage)
    cout << "Pop: " << s.pop() << endl;
    return 0;
}
