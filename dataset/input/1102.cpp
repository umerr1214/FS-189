#include <iostream>

class Counter {
private:
    static int totalCount;

public:
    Counter() {
        totalCount++;
    }

    ~Counter() {
        totalCount--;
    }

    static int getTotalCount() {
        return totalCount;
    }
}; // Missing semicolon here, causing a syntax error

// Static member definition (this line will not be reached due to syntax error above)
int Counter::totalCount = 0;

int main() {
    std::cout << "Initial count: " << Counter::getTotalCount() << std::endl; // Expected: 0

    Counter c1;
    std::cout << "After c1 creation: " << Counter::getTotalCount() << std::endl; // Expected: 1

    {
        Counter c2;
        Counter c3;
        std::cout << "After c2, c3 creation: " << Counter::getTotalCount() << std::endl; // Expected: 3
    } // c2, c3 are destroyed here

    std::cout << "After c2, c3 destruction: " << Counter::getTotalCount() << std::endl; // Expected: 1

    Counter* c4 = new Counter();
    std::cout << "After c4 (dynamic) creation: " << Counter::getTotalCount() << std::endl; // Expected: 2
    delete c4; // c4 is destroyed here
    std::cout << "After c4 (dynamic) destruction: " << Counter::getTotalCount() << std::endl; // Expected: 1

    return 0;
}