#include <iostream>

// Global flag to control reset behavior.
// This introduces a robustness issue: the function's core purpose can be
// silently disabled or enabled externally, making its behavior unpredictable
// and harder to reason about or test in isolation.
bool enable_reset_functionality = true;

void resetToZero(int& num) {
    if (enable_reset_functionality) {
        num = 0;
    }
    // If enable_reset_functionality is false, the function silently fails to perform its duty.
    // This makes the function less robust to external state changes and a potential source of bugs.
}

int main() {
    // Test case 1: Default behavior (reset enabled)
    int val1 = 5;
    std::cout << "Initial value 1: " << val1 << std::endl;
    enable_reset_functionality = true; // Ensure it's enabled for this test
    resetToZero(val1);
    std::cout << "After resetToZero (enabled): " << val1 << std::endl; // Expected: 0

    std::cout << "--------------------" << std::endl;

    // Test case 2: Functionality disabled - demonstrates the robustness issue
    int val2 = -10;
    enable_reset_functionality = false; // Disable the function's effect
    std::cout << "Initial value 2: " << val2 << std::endl;
    resetToZero(val2);
    std::cout << "After resetToZero (disabled): " << val2 << std::endl; // Expected: -10 (not reset)

    std::cout << "--------------------" << std::endl;

    // Test case 3: Re-enable and test again
    int val3 = 100;
    enable_reset_functionality = true; // Re-enable for this test
    std::cout << "Initial value 3: " << val3 << std::endl;
    resetToZero(val3);
    std::cout << "After resetToZero (re-enabled): " << val3 << std::endl; // Expected: 0

    return 0;
}