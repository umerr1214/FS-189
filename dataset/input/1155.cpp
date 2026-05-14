#include <iostream>

class Counter {
private:
    int count;
public:
    // Correct and idiomatic constructor using an initializer list.
    Counter(int initial_count = 0) : count(initial_count) {}

    int getCount() const {
        return count;
    }

    // Correct, idiomatic, and efficient prefix increment operator.
    // It increments the private 'count' member and returns a reference
    // to the modified original object (*this).
    Counter& operator++() {
        ++count; // Increment the count
        return *this; // Return a reference to the current object
    }
};

int main() {
    Counter myCounter(5);
    std::cout << "Initial count: " << myCounter.getCount() << std::endl;

    // Demonstrate prefix increment
    ++myCounter;
    std::cout << "After first increment: " << myCounter.getCount() << std::endl;

    Counter anotherCounter(10);
    // Demonstrate chaining of prefix increment
    ++++anotherCounter; // ++(++anotherCounter)
    std::cout << "Initial anotherCounter (before ++): " << 10 << std::endl;
    std::cout << "After chained increment: " << anotherCounter.getCount() << std::endl;

    // Demonstrate taking a reference to the result of prefix increment
    Counter thirdCounter(20);
    Counter& ref_to_third = ++thirdCounter;
    std::cout << "Initial thirdCounter (before ++): " << 20 << std::endl;
    std::cout << "After increment (ref_to_third): " << ref_to_third.getCount() << std::endl;
    std::cout << "Original thirdCounter: " << thirdCounter.getCount() << std::endl;
    
    ref_to_third.operator++(); // Increment via reference
    std::cout << "After incrementing via ref_to_third: " << ref_to_third.getCount() << std::endl;
    std::cout << "Original thirdCounter (affected): " << thirdCounter.getCount() << std::endl;

    return 0;
}