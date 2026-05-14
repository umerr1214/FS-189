#include <iostream>
#include <vector>
using namespace std;

class Stack {
private:
    vector<int> v;

public:
    void push(int x) {
        // Efficiency/Readability:
        // Implementing stack using vector insert at BEGINNING?
        // vector::insert(begin, x) is O(N).
        // Stack push should be O(1).
        // Using vector::push_back is O(1).
        
        v.insert(v.begin(), x);
    }

    int pop() {
        if (v.empty()) return -1;
        int val = v.front();
        v.erase(v.begin()); // O(N) erase
        return val;
    }
    
    // This effectively makes the stack operations O(N) instead of O(1).
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    cout << s.pop() << endl;
    return 0;
}
