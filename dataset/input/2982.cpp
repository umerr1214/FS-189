#include <iostream>

class Counter {
private:
    int count;
public:
    Counter() : count(0) {}
    void increment() {
        count++;
    }
    void decrement() {
        if (count > 0) {
            count--;
        }
    }
    int getCount() {
        return count;
    }
};

int main() {
    Counter c;
    std::cout << "Initial count: " << c.getCount() << std::endl;

    c.increment();
    c.increment();
    std::cout << "After 2 increments: " << c.getCount() << std::endl;

    // Semantic Error: Attempting to access private member 'count' directly from outside the class
    c.count = 5; // This line causes a compile-time error due to access control violation

    c.decrement();
    std::cout << "After 1 decrement: " << c.getCount() << std::endl;

    c.decrement();
    c.decrement();
    std::cout << "After 2 more decrements: " << c.getCount() << std::endl;

    c.increment();
    c.increment();
    c.increment();
    std::cout << "After 3 increments: " << c.getCount() << std::endl;

    return 0;
}