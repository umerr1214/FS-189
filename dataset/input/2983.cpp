#include <iostream>

class Counter {
private:
    int count; // Robustness issue: 'count' is not initialized in the default constructor

public:
    // Default constructor - robustness issue: 'count' is left uninitialized
    Counter() {
        // Missing: count = 0;
        // This means 'count' will have an indeterminate value.
        // If it happens to be negative, getCount() will return a negative value initially,
        // violating "count cannot go below zero" from the start.
    }

    void increment() {
        count++;
    }

    void decrement() {
        if (count > 0) { // This check prevents it from going below zero *after* initialization
            count--;
        }
    }

    int getCount() const {
        return count;
    }
};

int main() {
    std::cout << "Demonstrating Counter class with a robustness issue (uninitialized count)." << std::endl;
    Counter c;
    std::cout << "Initial Count (uninitialized): " << c.getCount() << std::endl; // Might print a garbage/negative value

    c.increment();
    std::cout << "After increment: " << c.getCount() << std::endl;

    c.decrement();
    std::cout << "After decrement: " << c.getCount() << std::endl;

    std::cout << "Attempting to decrement below zero (from current state):" << std::endl;
    c.decrement(); // If count was 0 or 1, it will go to 0. If it was negative, it might stay negative.
    std::cout << "After decrement attempt: " << c.getCount() << std::endl;

    Counter c2;
    std::cout << "\nAnother counter instance (also uninitialized): " << c2.getCount() << std::endl;
    for (int i = 0; i < 5; ++i) {
        c2.increment();
    }
    std::cout << "After 5 increments: " << c2.getCount() << std::endl;
    for (int i = 0; i < 7; ++i) {
        c2.decrement();
    }
    std::cout << "After 7 decrements (should be 0 if it started at 0): " << c2.getCount() << std::endl;

    return 0;
}