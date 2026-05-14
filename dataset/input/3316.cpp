#include <iostream>
#include <vector> // Not strictly necessary for this implementation, but often included.

int main() {
    int n;
    std::cout << "Enter n: ";
    std::cin >> n // Syntax Error: Missing semicolon here

    if (n <= 0) {
        std::cout << "Please enter a positive integer." << std::endl;
        return 1;
    }

    if (n == 1) {
        std::cout << "0" << std::endl;
        return 0;
    }

    if (n == 2) {
        std::cout << "0 1" << std::endl;
        return 0;
    }

    long long a = 0, b = 1;
    std::cout << a << " " << b;

    for (int i = 2; i < n; ++i) {
        long long next = a + b;
        std::cout << " " << next;
        a = b;
        b = next;
    }
    std::cout << std::endl;

    return 0;
}