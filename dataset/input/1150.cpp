#include <iostream>

class Counter {
private:
    int count;

public:
    Counter() : count(0) {}

    int getCount() const {
        return count;
    }

    // Prefix increment operator
    Counter& operator++() {
        ++count;
        return *this;
    }
} // Syntax Error: Missing semicolon after class definition

int main() {
    Counter myCounter;
    std::cout << "Initial count: " << myCounter.getCount() << std::endl;

    ++myCounter;
    std::cout << "After ++myCounter: " << myCounter.getCount() << std::endl;

    Counter anotherCounter;
    ++(++anotherCounter);
    std::cout << "After ++(++anotherCounter): " << anotherCounter.getCount() << std::endl;

    return 0;
}