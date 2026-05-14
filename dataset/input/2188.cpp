#include <iostream>
#include <vector>

class Counter {
public:
    static int count;

    Counter() {
        count++;
        std::cout << "Counter created. Total count: " << count << std::endl;
    }

    ~Counter() {
        count--;
        std::cout << "Counter destroyed. Total count: " << count << std::endl;
    }

    static int getTotalCount() {
        return count;
    }
} // SYNTAX ERROR: Missing semicolon here

int Counter::count = 0;

void createAndDestroyScope() {
    std::cout << "\nEntering createAndDestroyScope()" << std::endl;
    Counter c3;
    {
        Counter c4;
        std::cout << "Current count inside inner scope: " << Counter::getTotalCount() << std::endl;
    }
    std::cout << "Current count after inner scope: " << Counter::getTotalCount() << std::endl;
    std::cout << "Exiting createAndDestroyScope()" << std::endl;
}

int main() {
    std::cout << "Initial count: " << Counter::getTotalCount() << std::endl;

    Counter c1;
    std::cout << "Count after c1: " << Counter::getTotalCount() << std::endl;

    Counter c2;
    std::cout << "Count after c2: " << Counter::getTotalCount() << std::endl;

    createAndDestroyScope();

    std::cout << "Count after scope function: " << Counter::getTotalCount() << std::endl;

    std::vector<Counter> counters(3);
    std::cout << "Count after vector creation: " << Counter::getTotalCount() << std::endl;

    return 0;
}