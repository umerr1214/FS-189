#include <iostream>

class Counter {
public:
    // Constructor increments the static count when a new object is created.
    Counter() {
        s_count++;
    }

    // Destructor decrements the static count when an object is destroyed.
    ~Counter() {
        s_count--;
    }

    // Static member function to retrieve the current count of alive objects.
    // Static methods do not have a 'this' pointer and thus cannot be 'const'.
    static int getCount() {
        return s_count;
    }

private:
    // Static member variable to keep track of the total number of Counter objects alive.
    static int s_count;
};

// Initialize the static member variable outside the class definition.
int Counter::s_count = 0;

int main() {
    std::cout << "Initial count: " << Counter::getCount() << std::endl; // Expected: 0

    Counter c1; // Create first object
    std::cout << "After c1 created. Count: " << Counter::getCount() << std::endl; // Expected: 1

    { // Create a local scope to demonstrate object lifetime
        Counter c2; // Create second object
        std::cout << "Object c2 created. Current count: " << Counter::getCount() << std::endl; // Expected: 2

        Counter c3; // Create third object
        std::cout << "Object c3 created. Current count: " << Counter::getCount() << std::endl; // Expected: 3
    } // c3 and c2 go out of scope here and are destroyed, decrementing the count.

    std::cout << "After temporary objects destroyed. Current count: " << Counter::getCount() << std::endl; // Expected: 1 (only c1 remains)

    Counter c4; // Create fourth object
    std::cout << "Object c4 created. Current count: " << Counter::getCount() << std::endl; // Expected: 2 (c1 and c4 remain)

    // c4 and c1 are destroyed when main function exits, decrementing the count to 0.
    std::cout << "End of test. Final count before main exit: " << Counter::getCount() << std::endl; // Expected: 2

    return 0;
}