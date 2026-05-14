#include <iostream>

class Counter {
public:
    Counter() {
        count++;
    }

    Counter(const Counter& other) {
        count++;
    }

    ~Counter() {
        // LOGICAL ERROR: Missing decrement for 'count' in destructor
        // count--; // This line is intentionally omitted
    }

    static int getCount() {
        return count;
    }

private:
    static int count;
};

int Counter::count = 0;

int main() {
    std::cout << "Initial count: " << Counter::getCount() << std::endl; // Expected 0, Actual 0

    Counter c1;
    std::cout << "After c1 creation: " << Counter::getCount() << std::endl; // Expected 1, Actual 1

    {
        Counter c2;
        std::cout << "After c2 creation: " << Counter::getCount() << std::endl; // Expected 2, Actual 2
        Counter c3 = c1;
        std::cout << "After c3 (copy of c1) creation: " << Counter::getCount() << std::endl; // Expected 3, Actual 3
    } // c2 and c3 go out of scope, destructors called but don't decrement
    std::cout << "After c2 and c3 destroyed: " << Counter::getCount() << std::endl; // Expected 1, Actual 3

    Counter* p = new Counter();
    std::cout << "After p created with new: " << Counter::getCount() << std::endl; // Expected 2, Actual 4
    delete p; // Destructor called but doesn't decrement
    std::cout << "After p deleted: " << Counter::getCount() << std::endl; // Expected 1, Actual 4

    return 0;
}