#include <iostream>
#include <string>
#include <vector>
#include <limits> // For std::numeric_limits

// Function to be tested
void doubleValue(int& val) {
    // This is the most straightforward, readable, and idiomatic way
    // to multiply an integer by 2 in C++.
    // It correctly modifies the value by reference using the compound assignment operator.
    // Note: For extreme values that would cause an integer overflow/underflow,
    // C++ standard defines this as undefined behavior. A truly robust solution
    // (beyond the scope of this question) might use a larger integer type or
    // explicitly check for overflow before multiplication. However, for typical
    // use cases and the direct requirement, this implementation is correct.
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
    
    // Values near limits that won't overflow (assuming 32-bit int)
    // INT_MAX / 3 = 2147483647 / 3 = 715827882. Doubling this is 1431655764.
    run_test(std::numeric_limits<int>::max() / 3, (std::numeric_limits<int>::max() / 3) * 2, "Value near INT_MAX/3");
    // INT_MIN / 3 = -2147483648 / 3 = -715827882. Doubling this is -1431655764.
    run_test(std::numeric_limits<int>::min() / 3, (std::numeric_limits<int>::min() / 3) * 2, "Value near INT_MIN/3");

    return 0;
}