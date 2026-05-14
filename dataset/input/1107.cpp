#include <iostream>
#include <vector>
#include <memory> // For std::unique_ptr demonstration, though not strictly required by question

class Counter {
private:
    // Static member variable to keep track of active Counter objects
    static int s_count;

public:
    // Default constructor: increments the count when a new object is created
    Counter() {
        s_count++;
        // std::cout << "Counter object created. Active count: " << s_count << std::endl;
    }

    // Destructor: decrements the count when an object is destroyed
    ~Counter() {
        s_count--;
        // std::cout << "Counter object destroyed. Active count: " << s_count << std::endl;
    }

    // Static method to retrieve the current number of active Counter objects
    static int getTotalCount() {
        return s_count;
    }
};

// Definition and initialization of the static member variable outside the class
int Counter::s_count = 0;

int main() {
    std::cout << "Initial active counters: " << Counter::getTotalCount() << std::endl; // Expected: 0

    // Test case 1: Objects in local scope
    {
        Counter c1;
        std::cout << "After creating c1: " << Counter::getTotalCount() << std::endl; // Expected: 1

        Counter c2;
        std::cout << "After creating c2: " << Counter::getTotalCount() << std::endl; // Expected: 2
    } // c1 and c2 are destroyed here
    std::cout << "After c1 and c2 go out of scope: " << Counter::getTotalCount() << std::endl; // Expected: 0

    // Test case 2: Objects in a vector
    std::vector<Counter> counterVector;
    counterVector.reserve(3); // Pre-allocate memory to avoid reallocations
    counterVector.emplace_back(); // Creates 1 object
    counterVector.emplace_back(); // Creates 1 object
    std::cout << "After adding 2 objects to vector: " << Counter::getTotalCount() << std::endl; // Expected: 2

    counterVector.clear(); // Destroys all objects in the vector
    std::cout << "After clearing vector: " << Counter::getTotalCount() << std::endl; // Expected: 0

    // Test case 3: Dynamically allocated objects
    Counter* c3 = new Counter();
    std::cout << "After dynamically allocating c3: " << Counter::getTotalCount() << std::endl; // Expected: 1

    std::unique_ptr<Counter> c4 = std::make_unique<Counter>();
    std::cout << "After creating c4 with unique_ptr: " << Counter::getTotalCount() << std::endl; // Expected: 2

    delete c3; // Explicitly delete c3
    std::cout << "After deleting c3: " << Counter::getTotalCount() << std::endl; // Expected: 1

    // c4 will be automatically destroyed when it goes out of scope (end of main)
    std::cout << "Final active counters before main exits: " << Counter::getTotalCount() << std::endl; // Expected: 1

    return 0;
} // c4 is destroyed here