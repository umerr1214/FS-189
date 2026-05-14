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

private: // Semantic Error: getCount() is declared private
    static int getCount() {
        return objectCount;
    }
};

int Counter::objectCount = 0;

int main() {
    // Attempting to call private static method getCount() from outside the class
    std::cout << "Initial count: " << Counter::getCount() << std::endl;

    Counter c1;
    std::cout << "Count after c1: " << Counter::getCount() << std::endl;

    {
        Counter c2;
        std::cout << "Count after c2 (in scope): " << Counter::getCount() << std::endl;
    }
    std::cout << "Count after c2 out of scope: " << Counter::getCount() << std::endl;

    Counter c3;
    std::cout << "Count after c3: " << Counter::getCount() << std::endl;

    return 0;
}