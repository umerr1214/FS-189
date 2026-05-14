#include <iostream>

class BooleanFlag {
private:
    bool m_value;

public:
    // Constructor
    BooleanFlag(bool initialValue) : m_value(initialValue) {}

    // Overload unary logical NOT operator
    // Robustness issue: Declared const, preventing it from modifying the internal state
    // as required by "invert the encapsulated boolean value". It only returns the inverted value.
    bool operator!() const { // Marked const, so it cannot modify m_value
        return !m_value;
    }

    // Helper to get current state (for testing)
    bool getValue() const {
        return m_value;
    }
};

int main() {
    BooleanFlag flag(true);
    std::cout << "Initial flag value: " << flag.getValue() << std::endl; // Expected: 1 (true)

    // Call the operator!
    bool inverted_value = !flag;
    std::cout << "Result of !flag: " << inverted_value << std::endl; // Expected: 0 (false)
    std::cout << "Flag value after !flag: " << flag.getValue() << std::endl; // Robustness issue: Still 1, not 0

    std::cout << std::endl;

    BooleanFlag anotherFlag(false);
    std::cout << "Initial anotherFlag value: " << anotherFlag.getValue() << std::endl; // Expected: 0 (false)

    bool inverted_another_value = !anotherFlag;
    std::cout << "Result of !anotherFlag: " << inverted_another_value << std::endl; // Expected: 1 (true)
    std::cout << "AnotherFlag value after !anotherFlag: " << anotherFlag.getValue() << std::endl; // Robustness issue: Still 0, not 1

    return 0;
}