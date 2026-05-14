#include <iostream>

class Counter {
private:
    static int objectCount;

public:
    Counter() {
        objectCount++;
    }

    ~Counter() {
        objectCount--;
    }

    static int getCount() {
        return objectCount;
    }
} // Syntax Error: Missing semicolon here

int Counter::objectCount = 0;

int main() {
    std::cout << "Initial count: " << Counter::getCount() << std::endl;

    Counter c1;
    std::cout << "Count after c1: " << Counter::getCount() << std::endl;

    {
        Counter c2;
        std::cout << "Count after c2 (in scope): " << Counter::getCount() << std::endl;
    } // c2 goes out of scope
    std::cout << "Count after c2 out of scope: " << Counter::getCount() << std::endl;

    Counter c3;
    std::cout << "Count after c3: " << Counter::getCount() << std::endl;

    return 0;
}