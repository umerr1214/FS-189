#include <iostream>

int main() {
    int num;
    int sum = 0; // Initialize sum
    std::cout << "Enter positive integers (0 to stop):\n";
    while (true) {
        std::cin >> num;
        if (num == 0) {
            break;
        }
        // Logical error: sum is reset in each iteration instead of accumulating
        sum = num; // Should be sum += num;
    }
    std::cout << "Sum of non-zero numbers: " << sum << std::endl;
    return 0;
}