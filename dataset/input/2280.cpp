#include <iostream>

class Counter {
private:
    static int count; // Declaration of static member

public:
    Counter() {
        count++;
        std::cout << "Counter object created. Current count: " << count << std::endl;
    }

    ~Counter() {
        count--;
        std::cout << "Counter object destroyed. Current count: " << count << std::endl;
    }

    static int getCount() {
        return count;
    }
};

// SEMANTIC ERROR: Missing the definition and initialization for the static member `Counter::count`.
// int Counter::count = 0; // This line is missing.

int main() {
    std::cout << "Initial count: " << Counter::getCount() << std::endl;

    Counter c1;
    std::cout << "After c1 creation: " << Counter::getCount() << std::endl;

    {
        Counter c2;
        Counter c3;
        std::cout << "Inside block, count: " << Counter::getCount() << std::endl;
    }
    std::cout << "After block, count: " << Counter::getCount() << std::endl;

    Counter* c4 = new Counter();
    std::cout << "After c4 (new) creation: " << Counter::getCount() << std::endl;

    delete c4;
    std::cout << "After c4 (new) destruction: " << Counter::getCount() << std::endl;

    return 0;
}