#include <iostream>

class Counter {
private:
    static int objectCount;

public:
    Counter() {
        objectCount++;
    }

    // Logical Error: Destructor is missing or does not decrement objectCount
    // This will cause the count to only ever increase, not reflecting objects going out of scope.
    // ~Counter() {
    //     objectCount--;
    // }

    static int getCount() {
        return objectCount;
    }
};

int Counter::objectCount = 0;

int main() {
    std::cout << "Initial count: " << Counter::getCount() << std::endl;

    Counter c1;
    std::cout << "Count after c1: " << Counter::getCount() << std::endl;

    {
        Counter c2;
        std::cout << "Count after c2 (in scope): " << Counter::getCount() << std::endl;
    } // c2 goes out of scope, but objectCount is not decremented
    std::cout << "Count after c2 out of scope: " << Counter::getCount() << std::endl;

    Counter c3;
    std::cout << "Count after c3: " << Counter::getCount() << std::endl;

    return 0;
}