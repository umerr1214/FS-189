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
};

int main() {
    Counter myCounter;
    std::cout << "Initial count: " << myCounter.getCount() << std::endl;

    ++myCounter;
    std::cout << "After ++myCounter: " << myCounter.getCount() << std::endl;

    // Semantic Error: Attempting to access a private member 'count' directly from outside the class.
    // This violates encapsulation and will cause a compile-time error.
    myCounter.count = 10; 

    Counter anotherCounter;
    ++(++anotherCounter);
    std::cout << "After ++(++anotherCounter): " << anotherCounter.getCount() << std::endl;

    return 0;
}