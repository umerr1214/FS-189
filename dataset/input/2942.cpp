#include <iostream>

class BooleanFlag {
private:
    // Efficiency issue: Using an int to store a boolean value, wasting memory and potentially cycles for conversion.
    int m_value_as_int;

public:
    // Constructor
    BooleanFlag(bool initialValue) : m_value_as_int(initialValue ? 1 : 0) {}

    // Overload unary logical NOT operator
    // Readability issue: Overly verbose implementation using if-else instead of direct boolean logic.
    // Efficiency issue: Involves integer arithmetic and comparisons for a simple boolean flip.
    bool operator!() {
        if (m_value_as_int == 1) {
            m_value_as_int = 0;
            return false;
        } else { // Assuming m_value_as_int is 0 or any other non-1 for false
            m_value_as_int = 1;
            return true;
        }
    }

    // Helper to get current state (for testing), involves conversion
    bool getValue() const {
        return m_value_as_int != 0;
    }
};

int main() {
    BooleanFlag flag1(true);
    std::cout << "Initial flag1: " << flag1.getValue() << std::endl; // Expected: 1

    bool result1 = !flag1;
    std::cout << "Result of !flag1: " << result1 << std::endl; // Expected: 0
    std::cout << "Flag1 after !flag1: " << flag1.getValue() << std::endl; // Expected: 0 (state modified)

    std::cout << std::endl;

    BooleanFlag flag2(false);
    std::cout << "Initial flag2: " << flag2.getValue() << std::endl; // Expected: 0

    bool result2 = !flag2;
    std::cout << "Result of !flag2: " << result2 << std::endl; // Expected: 1
    std::cout << "Flag2 after !flag2: " << flag2.getValue() << std::endl; // Expected: 1 (state modified)

    return 0;
}