#include <iostream>
#include <vector>
using namespace std;

class Queue {
private:
    vector<int> v;

public:
    void enqueue(int x) {
        v.push_back(x);
    }

    int dequeue() {
        if (v.empty()) return -1;
        // Efficiency Issue: Erasing from beginning of vector is O(N).
        // Queue dequeue should be O(1).
        // Using vector as queue this way is inefficient.
        
        int val = v[0];
        v.erase(v.begin());
        return val;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    cout << q.dequeue() << endl;
    return 0;
}
