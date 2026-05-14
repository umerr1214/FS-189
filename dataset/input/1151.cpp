#include <iostream>

class Counter {
private:
    int count;

public:
    Counter() : count(0) {}

    int getCount() const {
        return count;
    }

    // Logical Error: The prefix increment operator should return a reference (Counter&)
    // Returning by value (Counter) means that when chaining increments (e.g., ++(++myCounter)),
    // the outer increment operates on a *copy* of the object returned by the inner increment,
    // not on the original object itself.
    Counter operator++() { // Should be Counter& operator++()
        ++count;
        return *this; // Returns a copy of the modified object
    }
};

int main() {
    Counter myCounter;
    std::cout << "Initial count: " << myCounter.getCount() << std::endl;

    ++myCounter;
    std::cout << "After ++myCounter: " << myCounter.getCount() << std::endl; // myCounter is 1

    Counter anotherCounter;
    // Here, (++anotherCounter) increments anotherCounter to 1, then returns a *copy* of it.
    // The outer '++' then increments this *copy* to 2.
    // However, the original 'anotherCounter' remains at 1.
    ++(++anotherCounter);
    std::cout << "After ++(++anotherCounter): " << anotherCounter.getCount() << std::endl; // Expect 2, but will output 1

    return 0;
}