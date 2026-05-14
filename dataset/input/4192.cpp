#include <iostream>
#include <string>

int main() {
    int n;
    std::cout << "Enter the height of the pyramid: "
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Please enter a positive integer for the height." << std::endl;
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        // Print spaces
        for (int j = 0; j < n - 1 - i; ++j) {
            std::cout << " ";
        }
        // Print stars
        for (int k = 0; k < 2 * i + 1; ++k) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    return 0;
}