#include <iostream>

class Counter {
private:
    int count;
public:
    Counter(int initial_count = 0) : count(initial_count) {}

    int getCount() const {
        return count;
    }

    // Robustness Issue: Returns Counter by value instead of Counter&
    // This creates a temporary object and can lead to unexpected behavior
    // if chaining or taking a reference to the result is attempted,
    // as the reference would bind to a temporary.
    Counter operator++() { // Should be Counter& operator++()
        ++count;
        return *this; // Returns a copy of the modified object
    }
};

int main() {
    Counter myCounter(5);
    std::cout << "Initial count: " << myCounter.getCount() << std::endl;

    Counter result_counter = ++myCounter; // Calls operator++, returns a copy
    std::cout << "After ++myCounter (result_counter): " << result_counter.getCount() << std::endl;
    std::cout << "Original myCounter: " << myCounter.getCount() << std::endl;

    // Demonstrate the robustness issue:
    // If we tried to take a reference to the returned object, it would bind to a temporary.
    // E.g., Counter& ref = ++myCounter; // This would be a dangling reference after the full expression.
    // While the code below doesn't cause UB directly, it shows that `result_counter` is a distinct copy.
    result_counter.operator++(); // Increment the copy
    std::cout << "After incrementing result_counter: " << result_counter.getCount() << std::endl;
    std::cout << "Original myCounter (unaffected): " << myCounter.getCount() << std::endl;

    // Chaining example (still works, but involves copies)
    Counter anotherCounter(10);
    Counter chained_result = ++++anotherCounter; // Two copies created
    std::cout << "Initial anotherCounter: " << 10 << std::endl;
    std::cout << "After ++++anotherCounter (chained_result): " << chained_result.getCount() << std::endl;
    std::cout << "Original anotherCounter: " << anotherCounter.getCount() << std::endl;

    return 0;
}