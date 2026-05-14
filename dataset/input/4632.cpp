#include <iostream>

long long calculateFactorial(int num) {
    if (num < 0) {
        return -1;
    }
    if (num == 0) {
        return 1;
    }
    int result = 1; // Semantic error: 'result' should be long long to prevent overflow for larger factorials
    for (int i = 1; i <= num; ++i) {
        result *= i;
    }
    return result; // Implicit conversion from int to long long, but value might have already overflowed
}

int main() {
    std::cout << "Factorial of 5: " << calculateFactorial(5) << std::endl;
    std::cout << "Factorial of 0: " << calculateFactorial(0) << std::endl;
    std::cout << "Factorial of -3: " << calculateFactorial(-3) << std::endl;
    std::cout << "Factorial of 1: " << calculateFactorial(1) << std::endl;
    std::cout << "Factorial of 10: " << calculateFactorial(10) << std::endl;
    std::cout << "Factorial of 13: " << calculateFactorial(13) << std::endl; // Will overflow int
    return 0;
}