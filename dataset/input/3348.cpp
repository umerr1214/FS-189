#include <iostream>

// Semantic error: The return type 'int' is insufficient for larger power results,
// leading to integer overflow for large inputs without a compile-time error.
int power(int base, int n) {
    if (n == 0) {
        return 1;
    }
    return base * power(base, n - 1);
}

int main() {
    std::cout << "2^3 = " << power(2, 3) << std::endl;
    std::cout << "5^0 = " << power(5, 0) << std::endl;
    std::cout << "3^4 = " << power(3, 4) << std::endl;
    std::cout << "10^1 = " << power(10, 1) << std::endl;
    // These calls will likely result in integer overflow, producing incorrect values
    std::cout << "2^30 = " << power(2, 30) << std::endl;
    std::cout << "7^10 = " << power(7, 10) << std::endl;
    return 0;
}