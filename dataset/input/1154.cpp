#include <iostream>

class Counter {
private:
    int count;
public:
    // Readability/Efficiency Issue: Assigns in the constructor body instead of using an initializer list.
    // While functionally correct, initializer lists are generally more efficient for member initialization
    // (especially for complex types) and are considered idiomatic C++.
    Counter(int initial_count = 0) {
        count = initial_count;
    }

    int getCount() const {
        return count;
    }

    // Readability/Efficiency Issue: Overly complex and less efficient implementation of prefix increment.
    // It unnecessarily creates a temporary object, modifies it, and then assigns its value back.
    // A direct increment (`++count;`) would be simpler and more efficient.
    Counter& operator++() {
        Counter temp_counter_object(*this); // Unnecessary temporary copy
        temp_counter_object.count = temp_counter_object.count + 1; // Increment temporary
        this->count = temp_counter_object.count; // Assign back to original
        return *this; // Returns reference to the modified original object
    }
};

int main() {
    Counter myCounter(10);
    std::cout << "Initial count: " << myCounter.getCount() << std::endl;

    ++myCounter; // Calls the overloaded operator
    std::cout << "After first increment: " << myCounter.getCount() << std::endl;

    Counter anotherCounter(0);
    Counter& ref_to_counter = ++anotherCounter; // Chaining and reference works
    std::cout << "Initial anotherCounter (before ++): " << 0 << std::endl;
    std::cout << "After increment (ref_to_counter): " << ref_to_counter.getCount() << std::endl;
    std::cout << "Original anotherCounter: " << anotherCounter.getCount() << std::endl;

    ++++myCounter; // Chained increment
    std::cout << "After chained increment: " << myCounter.getCount() << std::endl;

    return 0;
}