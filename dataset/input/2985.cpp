#include <iostream>

// Implements a Counter class with private count and public methods.
// Ensures count does not go below zero.
class Counter {
private:
    int count; // The private integer count

public:
    // Constructor initializes count to zero.
    Counter() : count(0) {}

    // Increments the counter by one.
    void increment() {
        count++;
    }

    // Decrements the counter by one, but only if count is greater than zero.
    // Prevents count from going below zero.
    void decrement() {
        if (count > 0) {
            count--;
        }
    }

    // Returns the current value of the counter.
    int getCount() const {
        return count;
    }
};

int main() {
    std::cout << "Demonstrating the Counter class:" << std::endl;

    Counter c; // Create a Counter object
    std::cout << "Initial Count: " << c.getCount() << std::endl; // Should be 0

    c.increment(); // Increment once
    std::cout << "After increment: " << c.getCount() << std::endl; // Should be 1

    c.increment(); // Increment again
    std::cout << "After another increment: " << c.getCount() << std::endl; // Should be 2

    c.decrement(); // Decrement once
    std::cout << "After decrement: " << c.getCount() << std::endl; // Should be 1

    c.decrement(); // Decrement to zero
    std::cout << "After decrement to zero: " << c.getCount() << std::endl; // Should be 0

    // Attempt to decrement below zero
    std::cout << "Attempting to decrement below zero:" << std::endl;
    c.decrement();
    std::cout << "After decrement attempt (should be 0): " << c.getCount() << std::endl; // Still 0

    // Demonstrate multiple operations
    std::cout << "\nPerforming multiple operations:" << std::endl;
    for (int i = 0; i < 10; ++i) {
        c.increment();
    }
    std::cout << "After 10 increments: " << c.getCount() << std::endl; // Should be 10

    for (int i = 0; i < 5; ++i) {
        c.decrement();
    }
    std::cout << "After 5 decrements: " << c.getCount() << std::endl; // Should be 5

    // Another attempt to decrement past zero
    std::cout << "Decrementing 10 times from 5 (should stop at 0):" << std::endl;
    for (int i = 0; i < 10; ++i) {
        c.decrement();
    }
    std::cout << "Final count: " << c.getCount() << std::endl; // Should be 0

    return 0;
}