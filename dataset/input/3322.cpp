#include <iostream>

int main() {
    int num;
    int sum = 0;
    std::cout << "Enter positive integers (0 to stop):\n";
    while (true) {
        std::cin >> num;
        if (num == 0) {
            break;
        }
        if (num > 0) {
            sum += num;
        }
    }
    std::cout << "Sum of non-zero numbers: " << sum << std::endl // Missing semicolon here
    return 0;
}