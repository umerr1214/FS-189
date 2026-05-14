#include <iostream>

class Counter {
private:
    int count;

public:
    Counter(int initial_count = 0) : count(initial_count) {}

    int getCount() const {
        return count;
    }

    // Prefix increment: ++obj - SEMANTIC ERROR
    // Should return Counter& to allow chaining and modification of the original object.
    // This returns Counter by value, which means chained operations operate on temporaries.
    Counter operator++() { // SEMANTIC ERROR: Should be 'Counter& operator++()'
        ++count;
        return *this; // Returns a copy, not a reference to *this
    }

    // Postfix increment: obj++ (correctly implemented here)
    Counter operator++(int) {
        Counter temp = *this; // Save current state
        ++count;             // Increment actual object
        return temp;         // Return saved state
    }

    // For printing
    friend std::ostream& operator<<(std::ostream& os, const Counter& c) {
        os << c.count;
        return os;
    }
};

int main() {
    std::cout << "--- Testing Counter class ---" << std::endl;

    Counter c1(0);
    std::cout << "Initial c1: " << c1.getCount() << std::endl;

    // Test Prefix Increment (simple use works, but chaining is affected)
    Counter simple_prefix_result = ++c1;
    std::cout << "After ++c1 (assigned to simple_prefix_result): c1 = " << c1.getCount() << ", simple_prefix_result = " << simple_prefix_result.getCount() << std::endl; // Expected: 1, 1

    // Test Postfix Increment (should work correctly)
    Counter c2(5);
    std::cout << "Initial c2: " << c2.getCount() << std::endl;
    Counter c2_old_value = c2++;
    std::cout << "After c2++: c2 = " << c2.getCount() << ", c2_old_value = " << c2_old_value.getCount() << std::endl; // Expected: 6, 5

    // Test Chaining Prefix Increment (will show semantic error effect)
    Counter c3(10);
    std::cout << "Initial c3: " << c3.getCount() << std::endl;
    // The inner ++c3 increments c3 to 11 and returns a *copy* of Counter(11).
    // The outer ++ operates on this *copy*, incrementing it to 12, and returns another *copy* of Counter(12).
    // The original c3 remains 11.
    Counter chained_prefix_result = ++(++c3);
    std::cout << "After ++(++c3): c3 = " << c3.getCount() << ", chained_prefix_result = " << chained_prefix_result.getCount() << std::endl; // Expected (correct behavior): 12, 12 (Actual: 11, 12)

    // Attempting to bind a reference to the result of prefix increment (will not compile as expected for semantic error)
    // Counter& c_ref_error = ++c1; // This line would cause a compiler error if enabled: "non-const lvalue reference to type 'Counter' cannot bind to a temporary of type 'Counter'"
    // This demonstrates the semantic problem, but we need compilable code for this category.
    // The chaining test above effectively shows the issue without compilation error.

    return 0;
}