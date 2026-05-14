#include <iostream>

bool isPerfect(int num) {
    if (num <= 1) {
        return false;
    }
    int sum_divisors = 0;
    // Syntax Error: Missing semicolon after ++i in the for loop header
    for (int i = 1; i < num; ++i) 
    {
        if (num % i == 0) {
            sum_divisors += i;
        }
    }
    return sum_divisors == num;
}

int main() {
    // Driver code for testing
    std::cout << "Is 6 perfect? " << (isPerfect(6) ? "true" : "false") << std::endl;
    std::cout << "Is 28 perfect? " << (isPerfect(28) ? "true" : "false") << std::endl;
    std::cout << "Is 1 perfect? " << (isPerfect(1) ? "true" : "false") << std::endl;
    std::cout << "Is 7 perfect? " << (isPerfect(7) ? "true" : "false") << std::endl;
    std::cout << "Is 0 perfect? " << (isPerfect(0) ? "true" : "false") << std::endl;
    std::cout << "Is -6 perfect? " << (isPerfect(-6) ? "true" : "false") << std::endl;
    std::cout << "Is 12 perfect? " << (isPerfect(12) ? "true" : "false") << std::endl;
    std::cout << "Is 496 perfect? " << (isPerfect(496) ? "true" : "false") << std::endl;
    return 0;
}