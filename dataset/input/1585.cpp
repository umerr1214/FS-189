#include <iostream>
#include <vector>
// No <atomic> or <mutex> for this version, leading to robustness issue

class Counter {
private:
    static int s_count; // Static member variable, prone to race conditions

public:
    // Constructor increments the count
    Counter() {
        s_count++; // Not an atomic operation
    }

    // Destructor decrements the count
    ~Counter() {
        s_count--; // Not an atomic operation
    }

    // Static method to get the current count
    static int getCount() {
        return s_count;
    }
};

// Initialize static member variable
int Counter::s_count = 0;

int main() {
    std::cout << Counter::getCount() << std::endl; // Expected: 0

    Counter c1;
    std::cout << Counter::getCount() << std::endl; // Expected: 1

    {
        Counter c2;
        Counter c3;
        std::cout << Counter::getCount() << std::endl; // Expected: 3
    } // c2, c3 destructed here
    std::cout << Counter::getCount() << std::endl; // Expected: 1

    Counter* p_c4 = new Counter();
    std::cout << Counter::getCount() << std::endl; // Expected: 2

    std::vector<Counter> vec_counters;
    vec_counters.emplace_back(); // c5
    vec_counters.emplace_back(); // c6
    std::cout << Counter::getCount() << std::endl; // Expected: 4

    delete p_c4; // Destruct p_c4
    std::cout << Counter::getCount() << std::endl; // Expected: 3

    vec_counters.clear(); // Destruct c5, c6
    std::cout << Counter::getCount() << std::endl; // Expected: 1

    // c1 will be destructed when main exits
    return 0;
}