#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Stack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int x) {
        // Semantic Error: bitwise assignment?
        // Or using sizeof.
        
        // Let's use assignment in condition.
        if (top = MAX_SIZE - 1) { // Sets top to 99!
            cout << "Stack Overflow" << endl;
            return;
        }
        
        // Code is unreachable or behaves weirdly.
        // top becomes 99. Returns "Stack Overflow" immediately on first push.
        arr[++top] = x;
    }

    int pop() {
        if (top < 0) return -1;
        return arr[top--];
    }
};

int main() {
    Stack s;
    // Expected: pushes 10.
    // Actual: prints "Stack Overflow", top becomes 99.
    s.push(10);
    return 0;
}
