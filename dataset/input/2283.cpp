#include <iostream>

class Counter {
private:
    static int s_count; // Private static member variable for the count

public:
    // Default Constructor: increments the count when a new object is created
    Counter() {
        s_count++;
    }

    // Copy Constructor: increments the count for a new object created via copy.
    // This ensures that a copied object is also considered "alive" and correctly tracked.
    Counter(const Counter& other) {
        s_count++;
    }

    // Destructor: decrements the count when an object is destroyed
    ~Counter() {
        s_count--;
    }

    // Assignment operator: This operation reassigns the state of an existing object.
    // It does not create a new object or destroy an existing one, so the count of
    // "currently alive" objects should not change due to assignment.
    Counter& operator=(const Counter& other) {
        // No change to s_count is needed here as 'this' object was already alive.
        return *this; // Return a reference to the current object
    }

    // Static method to retrieve the current count of alive objects
    static int getCount() {
        return s_count;
    }
};

// Initialize the static member variable outside the class definition
// This is crucial for static members to be properly linked.
int Counter::s_count = 0;

int main() {
    std::cout << "Initial count: " << Counter::getCount() << std::endl; // Expected: 0

    {
        Counter c1;
        std::cout << "After creating c1: " << Counter::getCount() << std::endl; // Expected: 1

        Counter c2;
        std::cout << "After creating c2: " << Counter::getCount() << std::endl; // Expected: 2

        // Copy constructor is called, s_count is correctly incremented
        Counter c3 = c1; 
        std::cout << "After copying c1 to c3: " << Counter::getCount() << std::endl; // Expected: 3

        Counter c4;
        std::cout << "After creating c4: " << Counter::getCount() << std::endl; // Expected: 4
    } // c1, c2, c3, c4 go out of scope. Destructors are called, s_count is decremented for each.

    std::cout << "After block ends: " << Counter::getCount() << std::endl; // Expected: 0

    Counter* p_c5 = new Counter(); // Heap allocation
    std::cout << "After creating c5 (heap): " << Counter::getCount() << std::endl; // Expected: 1
    delete p_c5; // Heap deallocation
    std::cout << "After deleting c5 (heap): " << Counter::getCount() << std::endl; // Expected: 0

    return 0;
}