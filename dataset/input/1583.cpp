#include <iostream>
#include <vector>

class Counter {
private:
    static int currentCount;

public:
    Counter() {
        currentCount++;
        std::cout << "Counter created. Current count: " << currentCount << std::endl;
    }

    ~Counter() {
        // LOGICAL ERROR: Destructor does not decrement currentCount
        std::cout << "Counter destroyed. Current count: " << currentCount << std::endl; // Count remains unchanged here
    }

    static int getCount() {
        return currentCount;
    }
};

int Counter::currentCount = 0;

int main() {
    std::cout << "Initial count: " << Counter::getCount() << std::endl;

    {
        Counter c1;
        std::cout << "Count after c1 creation: " << Counter::getCount() << std::endl;
        Counter c2;
        std::cout << "Count after c2 creation: " << Counter::getCount() << std::endl;
    } // c1 and c2 go out of scope here

    std::cout << "Count after c1, c2 destruction: " << Counter::getCount() << std::endl;

    Counter* c3 = new Counter();
    std::cout << "Count after c3 (heap) creation: " << Counter::getCount() << std::endl;
    delete c3;
    std::cout << "Count after c3 (heap) destruction: " << Counter::getCount() << std::endl;

    std::vector<Counter> counters;
    counters.emplace_back();
    std::cout << "Count after vector add 1: " << Counter::getCount() << std::endl;
    counters.emplace_back();
    std::cout << "Count after vector add 2: " << Counter::getCount() << std::endl;
    counters.clear();
    std::cout << "Count after vector clear: " << Counter::getCount() << std::endl;

    return 0;
}