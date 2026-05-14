#include <iostream>

int main() {
    int n;
    std::cout << "Enter n: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Please enter a positive integer." << std::endl;
        return 1;
    }

    long long a = 0, b = 1;

    // Logical Error: Incorrect handling for n=1.
    // For n=1, it should print only "0". This code prints "0 1".
    // For n=2, it correctly prints "0 1".
    // For n > 2, the loop correctly generates the rest of the terms.
    if (n == 1) {
        std::cout << a << " " << b << std::endl; // Should be just 'a'
    } else { // n >= 2
        std::cout << a << " " << b;
        for (int i = 2; i < n; ++i) {
            long long next = a + b;
            std::cout << " " << next;
            a = b;
            b = next;
        }
        std::cout << std::endl;
    }

    return 0;
}