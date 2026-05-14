#include <iostream>

int main() {
    int n;
    std::cout << "Enter n: ";
    std::cin >> n // Missing semicolon here

    int a = 0, b = 1;

    if (n <= 0) {
        // Prints nothing for n <= 0
    } else if (n == 1) {
        std::cout << a << std::endl;
    } else {
        std::cout << a << " " << b;
        for (int i = 2; i < n; ++i) {
            int nextTerm = a + b;
            std::cout << " " << nextTerm;
            a = b;
            b = nextTerm;
        }
        std::cout << std::endl;
    }
    return 0;
}