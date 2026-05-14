#include <iostream>

class Counter {
private:
    static int totalCount; // Declaration of static member

public:
    Counter() {
        totalCount++;
    }

    ~Counter() {
        totalCount--;
    }

    static int getTotalCount() {
        return totalCount;
    }
};

// Semantic Error: Missing the definition of static member 'totalCount' outside the class.
// int Counter::totalCount = 0; // This line is commented out, causing a linker error.

int main() {
    std::cout << "Initial count: " << Counter::getTotalCount() << std::endl;

    Counter c1;
    std::cout << "After c1 creation: " << Counter::getTotalCount() << std::endl;

    {
        Counter c2;
        Counter c3;
        std::cout << "After c2, c3 creation: " << Counter::getTotalCount() << std::endl;
    }

    std::cout << "After c2, c3 destruction: " << Counter::getTotalCount() << std::endl;

    Counter* c4 = new Counter();
    std::cout << "After c4 (dynamic) creation: " << Counter::getTotalCount() << std::endl;
    delete c4;
    std::cout << "After c4 (dynamic) destruction: " << Counter::getTotalCount() << std::endl;

    return 0;
}