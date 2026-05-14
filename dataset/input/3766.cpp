#include <iostream>
#include <vector>
#include <string>

long long calculatePower(int base, int exponent) {
    if (exponent == 0) {
        return 1;
    }
    long long result = 1;
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result // Syntax Error: Missing semicolon here
}

int main() {
    std::vector<std::pair<std::pair<int, int>, long long>> test_cases = {
        {{2, 3}, 8},
        {{5, 0}, 1},
        {{10, 1}, 10},
        {{3, 4}, 81},
        {{-2, 2}, 4},
        {{-2, 3}, -8}
    };

    for (const auto& tc : test_cases) {
        int base = tc.first.first;
        int exponent = tc.first.second;
        long long expected = tc.second;
        long long result = calculatePower(base, exponent);
        std::cout << "calculatePower(" << base << ", " << exponent << ") -> ";
        std::cout << "Expected: " << expected << ", Got: " << result;
        if (result == expected) {
            std::cout << " [PASSED]\n";
        } else {
            std::cout << " [FAILED]\n";
        }
    }

    return 0;
}