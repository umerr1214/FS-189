#include <iostream>
#include <string>
#include <vector>

// Function to be tested
void doubleValue(int& val) {
    // This uses a bit shift operation (left shift by 1) to multiply by 2.
    // While functionally correct and sometimes perceived as a micro-optimization,
    // it can be less readable for those unfamiliar with bitwise operations compared
    // to direct multiplication (val *= 2; or val = val * 2;).
    // Modern compilers often optimize 'val * 2' to a bit shift anyway,
    // so this might not offer a real efficiency gain and reduces readability for some.
    val = val << 1;
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
        std::cout << "  Result: FAILED\n\n";
    }
}

int main() {
    run_test(5, 10, "Positive value");
    run_test(-3, -6, "Negative value");
    run_test(0, 0, "Zero value");
    run_test(100, 200, "Another positive value");
    run_test(-50, -100, "Another negative value");
    run_test(1000000, 2000000, "Large positive value");
    run_test(-1000000, -2000000, "Large negative value");

    return 0;
}