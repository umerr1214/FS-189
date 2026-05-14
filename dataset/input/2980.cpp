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
} // Syntax Error: Missing semicolon after class definition

int main() {
    Counter c;
    std::cout << "Initial count: " << c.getCount() << std::endl;

    c.increment();
    c.increment();
    std::cout << "After 2 increments: " << c.getCount() << std::endl;

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