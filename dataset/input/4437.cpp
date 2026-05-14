#include <iostream>

// Implements a correct, efficient, and readable recursive function `calculatePower`
// using binary exponentiation (exponentiation by squaring).
// It handles edge cases like base 0, exponent 0, and negative bases correctly.
// It uses `long long` for intermediate products to prevent overflow during squaring,
// assuming the final result fits within an `int`.
int calculatePower(int base, int exponent) {
    // Base case 1: Any number to the power of 0 is 1.
    // This handles 0^0 as 1, which is the common convention in programming contexts.
    if (exponent == 0) {
        return 1;
    }
    // Base case 2: 0 to any positive power is 0.
    // (0^0 is already handled by the first base case, returning 1).
    if (base == 0) {
        return 0;
    }

    // Recursive step: Binary Exponentiation (Exponentiation by Squaring)
    // Calculate power for half of the exponent.
    // The result of calculatePower(base, exponent / 2) can be large,
    // so using long long for intermediate product is crucial to prevent overflow
    // before the final cast to int.
    int half_power = calculatePower(base, exponent / 2);
    long long result_ll; // Use long long for intermediate multiplication

    if (exponent % 2 == 0) {
        // If exponent is even: base^exponent = (base^(exponent/2))^2
        result_ll = (long long)half_power * half_power;
    } else {
        // If exponent is odd: base^exponent = base * (base^(exponent/2))^2
        result_ll = (long long)base * half_power * half_power;
    }

    // Cast back to int. If the final result exceeds INT_MAX, it will wrap around
    // according to standard C++ integer overflow rules for signed integers.
    // The question implies an `int` return type, so this is the expected behavior
    // for results that exceed `int` capacity.
    return static_cast<int>(result_ll);
}

int main() {
    // This main function is for local compilation and testing.
    // The actual testing environment will use the driver code provided in the JSON.
    std::cout << "Running local tests for 4437.cpp (Correct Version)" << std::endl;
    std::cout << "calculatePower(2, 3) = " << calculatePower(2, 3) << " (Expected: 8)" << std::endl;
    std::cout << "calculatePower(5, 0) = " << calculatePower(5, 0) << " (Expected: 1)" << std::endl;
    std::cout << "calculatePower(0, 0) = " << calculatePower(0, 0) << " (Expected: 1)" << std::endl;
    std::cout << "calculatePower(0, 5) = " << calculatePower(0, 5) << " (Expected: 0)" << std::endl;
    std::cout << "calculatePower(1, 100) = " << calculatePower(1, 100) << " (Expected: 1)" << std::endl;
    std::cout << "calculatePower(3, 15) = " << calculatePower(3, 15) << " (Expected: 14348907)" << std::endl;
    std::cout << "calculatePower(-2, 3) = " << calculatePower(-2, 3) << " (Expected: -8)" << std::endl;
    std::cout << "calculatePower(-2, 4) = " << calculatePower(-2, 4) << " (Expected: 16)" << std::endl;
    std::cout << "calculatePower(2, 30) = " << calculatePower(2, 30) << " (Expected: 1073741824)" << std::endl;
    std::cout << "calculatePower(-1, 99) = " << calculatePower(-1, 99) << " (Expected: -1)" << std::endl;
    std::cout << "calculatePower(-1, 100) = " << calculatePower(-1, 100) << " (Expected: 1)" << std::endl;
    return 0;
}