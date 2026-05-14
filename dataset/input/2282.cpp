#include <iostream>

// Readability/Efficiency Issue:
// The counter uses a global variable instead of a static member variable as specified in the question.
// This design choice breaks encapsulation, making the Counter class less self-contained and harder
// to manage in a larger codebase. It couples the class tightly with a global state, reducing modularity
// and increasing the risk of unintended modifications from other parts of the program.
int total_alive_counters = 0; // Global variable for the count

class Counter {
public:
    // Constructor: increments the global count
    Counter() {
        total_alive_counters++;
    }

    // Copy Constructor: increments the global count for a new object created via copy
    Counter(const Counter& other) {
        total_alive_counters++;
    }

    // Destructor: decrements the global count
    ~Counter() {
        total_alive_counters--;
    }

    // Assignment operator: does not affect the count of alive objects,
    // as it operates on an already existing object.
    Counter& operator=(const Counter& other) {
        return *this;
    }

    // Static method to retrieve the current count (accessing the global variable)
    static int getCount() {
        return total_alive_counters;
    }
};

// No static member initialization needed as it uses a global variable.

int main() {
    std::cout << "Initial count: " << Counter::getCount() << std::endl; // Expected: 0

    {
        Counter c1;
        std::cout << "After creating c1: " << Counter::getCount() << std::endl; // Expected: 1

        Counter c2;
        std::cout << "After creating c2: " << Counter::getCount() << std::endl; // Expected: 2

        Counter c3 = c1; // Copy constructor increments global count
        std::cout << "After copying c1 to c3: " << Counter::getCount() << std::endl; // Expected: 3

        Counter c4;
        std::cout << "After creating c4: " << Counter::getCount() << std::endl; // Expected: 4
    } // c1, c2, c3, c4 go out of scope. Destructors decrement global count.

    std::cout << "After block ends: " << Counter::getCount() << std::endl; // Expected: 0

    Counter* p_c5 = new Counter(); // Heap allocation
    std::cout << "After creating c5 (heap): " << Counter::getCount() << std::endl; // Expected: 1
    delete p_c5; // Heap deallocation
    std::cout << "After deleting c5 (heap): " << Counter::getCount() << std::endl; // Expected: 0

    return 0;
}