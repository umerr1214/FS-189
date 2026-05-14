#include <iostream>

class BooleanFlag {
private:
    bool m_value;

public:
    // Constructor
    BooleanFlag(bool initialValue) : m_value(initialValue) {}

    // Overload unary logical NOT operator
    // Inverts the encapsulated boolean value and returns the new value.
    bool operator!() {
        m_value = !m_value; // Invert the encapsulated value
        return m_value;     // Return the new value
    }

    // Helper to get current state (for testing)
    bool getValue() const {
        return m_value;
    }
};

int main() {
    BooleanFlag flag1(true);
    std::cout << "Initial flag1: " << flag1.getValue() << std::endl; // Expected: 1

    bool result1 = !flag1;
    std::cout << "Result of !flag1: " << result1 << std::endl; // Expected: 0
    std::cout << "Flag1 after !flag1: " << flag1.getValue() << std::endl; // Expected: 0

    std::cout << std::endl;

    BooleanFlag flag2(false);
    std::cout << "Initial flag2: " << flag2.getValue() << std::endl; // Expected: 0

    bool result2 = !flag2;
    std::cout << "Result of !flag2: " << result2 << std::endl; // Expected: 1
    std::cout << "Flag2 after !flag2: " << flag2.getValue() << std::endl; // Expected: 1

    std::cout << std::endl;

    BooleanFlag flag3(true);
    std::cout << "Initial flag3: " << flag3.getValue() << std::endl; // Expected: 1
    !flag3; // Invert to false
    std::cout << "Flag3 after first !flag3: " << flag3.getValue() << std::endl; // Expected: 0
    !flag3; // Invert back to true
    std::cout << "Flag3 after second !flag3: " << flag3.getValue() << std::endl; // Expected: 1

    return 0;
}