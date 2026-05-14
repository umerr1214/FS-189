#include <iostream>
#include <vector>
#include <atomic> // For thread-safe counting

class Counter {
private:
    // Static member variable to track alive objects, using std::atomic for thread safety
    static std::atomic<int> s_count;

public:
    // Constructor: increments the count
    Counter() {
        s_count++;
    }

    // Destructor: decrements the count
    ~Counter() {
        s_count--;
    }

    // Static method to get the current count
    static int getCount() {
        return s_count.load(); // Use load() for atomic read
    }

    // The default copy/move constructors and assignment operators are sufficient
    // as they will correctly call the constructor/destructor for new objects
    // or when objects go out of scope. No special handling needed for the counter itself.
};

// Initialize static member variable
std::atomic<int> Counter::s_count = 0;

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