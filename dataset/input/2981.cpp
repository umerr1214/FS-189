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
        // Logical Error: Allows count to go below zero, violating the requirement
        count--; 
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

    c.decrement();
    std::cout << "After 1 decrement: " << c.getCount() << std::endl;

    c.decrement();
    c.decrement(); // This will make count -1, as there's no check
    std::cout << "After 2 more decrements: " << c.getCount() << std::endl; // Expected 0, will output -1

    c.increment();
    c.increment();
    c.increment();
    std::cout << "After 3 increments: " << c.getCount() << std::endl; // Expected 3, will output 2 (since starting from -1)

    return 0;
}