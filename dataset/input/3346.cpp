#include <iostream>

long long power(int base, int n) {
    if (n == 0) {
        return 1;
    }
    // Syntax error: Missing semicolon after return statement
    return base * power(base, n - 1) 
}

int main() {
    std::cout << "2^3 = " << power(2, 3) << std::endl;
    std::cout << "5^0 = " << power(5, 0) << std::endl;
    std::cout << "3^4 = " << power(3, 4) << std::endl;
    std::cout << "10^1 = " << power(10, 1) << std::endl;
    return 0;
}