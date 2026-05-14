#include <iostream>
#include <string>
#include <vector>
#include <limits> // Required for INT_MAX and INT_MIN

// Function to be tested
void doubleValue(int& val) {
    // This implementation works for most cases but has a robustness issue
    // regarding integer overflow/underflow if 'val' is large enough to exceed INT_MAX
    // or small enough to fall below INT_MIN when doubled.
    // In C++, signed integer overflow is undefined behavior. On most common
    // systems using two's complement, it wraps around.
    val *= 2;
}

void run_test(int input_val, int expected_val, const std::string& description) {
    int current_val = input_val;
    doubleValue(current_val);
    std::cout << "Test Case: " << description << "\n";
    std::cout << "  Initial Value: " << input_val << "\n";
    std::cout << "  Expected Value: " << expected_val << "\n";
    std::cout << "  Actual Value after doubleValue: " << current_val << "\n";
    if (current_val == expected_val) {
        std::cout << "  Result: PASSED\n\n";
    } else {
        std::cout << "  Result: FAILED (Robustness issue - potential overflow/underflow)\n\n";
    }
}

int main() {
    run_test(5, 10, "Positive value");
    run_test(-3, -6, "Negative value");
    run_test(0, 0, "Zero value");
    run_test(1000000000, 2000000000, "Large positive value (no overflow)"); // 1 billion * 2

    // This test case demonstrates the robustness issue (integer overflow)
    // INT_MAX is 2147483647.
    // If input is 1500000000, expected would be 3000000000, which overflows int.
    // On a 2's complement system, 3000000000 wraps around to -1294967296.
    run_test(1500000000, -1294967296, "Value causing integer overflow (1.5 billion * 2)");
    
    // This test case demonstrates the robustness issue (integer underflow)
    // INT_MIN is -2147483648.
    // If input is -1500000000, expected would be -3000000000, which underflows int.
    // On a 2's complement system, -3000000000 wraps around to 1294967296.
    run_test(-1500000000, 1294967296, "Value causing integer underflow (-1.5 billion * 2)");

    return 0;
}