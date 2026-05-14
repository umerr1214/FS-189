#include <iostream>
#include <vector>
#include <string>

// Semantic Error: Using 'int' for return type and result variable,
// which can lead to integer overflow for large power values.
int calculatePower(int base, int exponent) {
    if (exponent == 0) {
        return 1;
    }
    int result = 1; // Potential overflow here
    for (int i = 0; i < exponent; ++i) {
        result *= base; // Potential overflow here
    }
    return result;
}

int main() {
    std::vector<std::pair<std::pair<int, int>, long long>> test_cases = {
        {{2, 3}, 8},
        {{5, 0}, 1},
        {{10, 1}, 10},
        {{3, 4}, 81},
        {{-2, 2}, 4},
        {{-2, 3}, -8},
        {{2, 31}, 2147483648LL} // 2^31, which overflows a 32-bit signed int
    };

    for (const auto& tc : test_cases) {
        int base = tc.first.first;
        int exponent = tc.first.second;
        long long expected = tc.second;
        // The function returns int, so capture it as int and cast for comparison
        int result_int = calculatePower(base, exponent);
        long long result_long_long = static_cast<long long>(result_int);

        std::cout << "calculatePower(" << base << ", " << exponent << ") -> ";
        std::cout << "Expected: " << expected << ", Got: " << result_long_long;
        if (result_long_long == expected) {
            std::cout << " [PASSED]\n";
        } else {
            std::cout << " [FAILED]\n";
        }
    }

    return 0;
}