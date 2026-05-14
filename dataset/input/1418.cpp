#include <iostream>
#include <string> // Included but not strictly necessary for a simple counter, adds to "clutter"

class Counter {
private:
    int current_val; // Renamed for slightly less common 'value', impacting immediate recognition
    bool is_active_status; // Unused private member, adds to class complexity/clutter
public:
    // Verbose constructor with explicit 'this->' and redundant initialization
    Counter(int initial_value_param = 0) {
        this->current_val = initial_value_param;
        this->is_active_status = true; // Initialized but never used
    }

    // Getter with slightly more verbose logic (e.g., unnecessary temporary variable)
    int getValue() const {
        int temp_retrieved_value = this->current_val;
        return temp_retrieved_value; // Redundant variable, could directly return this->current_val
    }

    // Pre-increment operator (prefix) - Readability Issue
    // Correct return type, but verbose increment style and explicit 'this->'
    Counter& operator++() {
        this->current_val = this->current_val + 1; // Verbose increment instead of ++this->current_val
        return *this;
    }

    // Post-increment operator (postfix) - Readability/Efficiency Issue
    // Correct functionality, but verbose parameter name and slightly less concise steps
    Counter operator++(int dummy_int_parameter) { // 'dummy_int_parameter' is verbose/non-standard name
        Counter temporary_copy_before_increment = *this; // Create a temporary copy
        this->current_val = this->current_val + 1; // Increment the original object
        return temporary_copy_before_increment; // Return the temporary
    }
};

int main() {
    std::cout << "--- Testing Readability / Efficiency Issue ---" << std::endl;

    // Test pre-increment
    Counter c1(7);
    std::cout << "c1 initial: " << c1.getValue() << std::endl; // Expected: 7
    std::cout << "Value of (++c1): " << (++c1).getValue() << std::endl; // c1 becomes 8, prints 8
    std::cout << "c1 after pre-inc: " << c1.getValue() << std::endl; // Expected: 8

    std::cout << std::endl;

    // Test post-increment
    Counter c2(12);
    std::cout << "c2 initial: " << c2.getValue() << std::endl; // Expected: 12
    std::cout << "Value of (c2++): " << (c2++).getValue() << std::endl; // c2 becomes 13, prints 12
    std::cout << "c2 after post-inc: " << c2.getValue() << std::endl; // Expected: 13

    std::cout << std::endl;

    // Chained pre-increment (demonstrates that it's functionally correct despite verbosity)
    Counter c3(1);
    std::cout << "c3 initial: " << c3.getValue() << std::endl; // Expected: 1
    ++(++c3); // Should increment c3 twice
    std::cout << "c3 after ++(++c3): " << c3.getValue() << std::endl; // Expected: 3

    return 0;
}