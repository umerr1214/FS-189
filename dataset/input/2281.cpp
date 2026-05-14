#include <iostream>

class Counter {
private:
    static int s_count; // Static member variable for the count

public:
    // Constructor: increments the count when a new object is created
    Counter() {
        s_count++;
    }

    // Robustness Issue:
    // The default copy constructor is implicitly generated and used here.
    // The default copy constructor performs a member-wise copy but does NOT
    // automatically call the default constructor or explicitly increment s_count.
    // This means when an object is copied, the static count is not updated.
    // When the copied object is later destroyed, its destructor will decrement
    // s_count, leading to an incorrect (underflowed) count.

    // Destructor: decrements the count when an object is destroyed
    ~Counter() {
        s_count--;
    }

    // Static method to retrieve the current count of alive objects
    static int getCount() {
        return s_count;
    }
};

// Initialize the static member variable outside the class definition
int Counter::s_count = 0;

int main() {
    std::cout << "Initial count: " << Counter::getCount() << std::endl; // Expected: 0

    {
        Counter c1;
        std::cout << "After creating c1: " << Counter::getCount() << std::endl; // Expected: 1

        Counter c2;
        std::cout << "After creating c2: " << Counter::getCount() << std::endl; // Expected: 2

        // This copy uses the implicitly generated copy constructor.
        // It does NOT increment Counter::s_count.
        Counter c3 = c1; 
        std::cout << "After copying c1 to c3: " << Counter::getCount() << std::endl; // Actual: 2 (Incorrect, should be 3)

        Counter c4;
        std::cout << "After creating c4: " << Counter::getCount() << std::endl; // Actual: 3 (Incorrect, should be 4)
    } // c1, c2, c3, c4 go out of scope.
      // Destructors are called for c4, c3, c2, c1 in reverse order of construction.
      // c3's destructor will decrement s_count, but s_count was never incremented for c3's creation.
      // So, the count will become negative.
      // Expected sequence of s_count: 0 -> 1 (c1) -> 2 (c2) -> 2 (c3, BUG) -> 3 (c4)
      // On destruction: 3 -> 2 (c4) -> 1 (c3) -> 0 (c2) -> -1 (c1, BUG due to c3's earlier bug)

    std::cout << "After block ends: " << Counter::getCount() << std::endl; // Actual: -1 (Incorrect, should be 0)

    Counter* p_c5 = new Counter(); // Heap allocation
    std::cout << "After creating c5 (heap): " << Counter::getCount() << std::endl; // Actual: 0 (Incorrect, should be 1)
    delete p_c5; // Heap deallocation
    std::cout << "After deleting c5 (heap): " << Counter::getCount() << std::endl; // Actual: -1 (Incorrect, should be 0)

    return 0;
}