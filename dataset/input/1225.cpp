#include <iostream>
#include <vector>

class Counter {
public:
    // Default constructor increments the alive count
    Counter() {
        _alive_objects++;
    }

    // Destructor decrements the alive count
    ~Counter() {
        _alive_objects--;
    }

    // Static member function to get the current count of alive objects
    static int getAliveCount() {
        return _alive_objects;
    }

private:
    // Static member variable to keep track of alive objects
    static int _alive_objects;
};

// Initialize the static member variable outside the class definition
int Counter::_alive_objects = 0;

void run_test_case() {
    std::cout << "--- Robustness Issue Test ---" << std::endl;
    std::cout << "Initial alive count: " << Counter::getAliveCount() << std::endl; // Expected: 0, Actual: 0

    Counter c1; // Default constructor called, _alive_objects becomes 1
    std::cout << "After creating c1: " << Counter::getAliveCount() << std::endl; // Expected: 1, Actual: 1

    // Robustness Issue: Default copy constructor is implicitly used.
    // It does NOT call the Counter() constructor, so _alive_objects is NOT incremented.
    // However, a new Counter object (c2) IS created.
    Counter c2 = c1;
    std::cout << "After creating c2 (copy of c1): " << Counter::getAliveCount() << std::endl; // Expected: 2, Actual: 1 (BUG!)

    {
        Counter c3; // Default constructor called, _alive_objects becomes 2
        std::cout << "After creating c3 in inner scope: " << Counter::getAliveCount() << std::endl; // Expected: 3, Actual: 2 (BUG!)
        // c3 goes out of scope here. Destructor called, _alive_objects becomes 1.
    }
    std::cout << "After c3 goes out of scope: " << Counter::getAliveCount() << std::endl; // Expected: 2, Actual: 1 (BUG!)

    // When c1 and c2 go out of scope:
    // ~c2() is called: _alive_objects becomes 0. (Expected: 1)
    // ~c1() is called: _alive_objects becomes -1. (Expected: 0)
    std::cout << "Expected final alive count after c1, c2 destroyed: 0" << std::endl;
}

int main() {
    run_test_case();
    std::cout << "Final alive count (after c1, c2 destroyed): " << Counter::getAliveCount() << std::endl; // Actual: -1 (BUG!)
    return 0;
}