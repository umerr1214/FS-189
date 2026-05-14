#include <iostream>
using namespace std;

const int MAX_SIZE = 2; // Small size for testing

class Stack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int x) {
        // Robustness Issue: No overflow check.
        arr[++top] = x; // Buffer overflow if push called > MAX_SIZE times
    }

    int pop() {
        // Robustness Issue: No underflow check.
        return arr[top--]; // Undefined behavior if pop called on empty stack (top becomes -2)
    }
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3); // Overflow writing to arr[2]
    return 0;
}
