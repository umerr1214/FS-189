#include <iostream>

int main() {
    int num;
    int sum = 0;
    std::cout << "Enter positive integers (0 to stop):\n";
    while (true) {
        std::cin >> num;
        // Semantic error: comparing integer num with character literal '0' (ASCII 48)
        // The loop will only terminate if the user enters the integer 48, not 0.
        if (num == '0') { // Should be num == 0
            break;
        }
        if (num > 0) {
            sum += num;
        }
    }
    std::cout << "Sum of non-zero numbers: " << sum << std::endl;
    return 0;
}