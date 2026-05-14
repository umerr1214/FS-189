#include <iostream>

long long calculateFactorial(int num) {
    if (num < 0) {
        return -1;
    }
    if (num == 0) {
        return 1 // Missing semicolon here
    }
    long long result = 1;
    for (int i = 1; i <= num; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    std::cout << "Factorial of 5: " << calculateFactorial(5) << std::endl;
    std::cout << "Factorial of 0: " << calculateFactorial(0) << std::endl;
    std::cout << "Factorial of -3: " << calculateFactorial(-3) << std::endl;
    std::cout << "Factorial of 1: " << calculateFactorial(1) << std::endl;
    std::cout << "Factorial of 10: " << calculateFactorial(10) << std::endl;
    return 0;
}