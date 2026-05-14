#include <iostream>

class Counter {
private:
    static int totalCount;

public:
    Counter() {
        totalCount++; // Increment count
    }

    ~Counter() {
        totalCount++; // Logical Error: Destructor increments instead of decrements
    }

    static int getTotalCount() {
        return totalCount;
    }
};

// Static member definition
int Counter::totalCount = 0;

int main() {
    std::cout << "Initial count: " << Counter::getTotalCount() << std::endl; // Expected: 0, Actual: 0

    Counter c1;
    std::cout << "After c1 creation: " << Counter::getTotalCount() << std::endl; // Expected: 1, Actual: 1

    {
        Counter c2;
        Counter c3;
        std::cout << "After c2, c3 creation: " << Counter::getTotalCount() << std::endl; // Expected: 3, Actual: 3
    } // c2, c3 are destroyed here
    // Expected behavior: totalCount should decrease by 2 (from 3 to 1)
    // Actual behavior: totalCount will increase by 2 (from 3 to 5) due to logical error
    std::cout << "After c2, c3 destruction: " << Counter::getTotalCount() << std::endl; // Expected: 1, Actual: 5

    Counter* c4 = new Counter();
    std::cout << "After c4 (dynamic) creation: " << Counter::getTotalCount() << std::endl; // Expected: 2, Actual: 6
    delete c4; // c4 is destroyed here
    // Expected behavior: totalCount should decrease by 1 (from 2 to 1)
    // Actual behavior: totalCount will increase by 1 (from 6 to 7) due to logical error
    std::cout << "After c4 (dynamic) destruction: " << Counter::getTotalCount() << std::endl; // Expected: 1, Actual: 7

    std::cout << "Final count: " << Counter::getTotalCount() << std::endl; // Expected: 1, Actual: 7
    return 0;
}