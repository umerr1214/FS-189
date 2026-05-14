#include <iostream>

int main() {
    long long num;
    int count = 0;

    std::cout << "Enter a non-negative integer: "
    std::cin >> num;

    if (num < 0) {
        std::cout << "Input must be a non-negative integer." << std::endl;
        return 1;
    }

    if (num == 0) {
        count = 1;
    } else {
        while (num > 0) {
            num /= 10;
            count++;
        }
    }

    std::cout << "The number " << num << " has " << count << " digits." << std::endl;

    return 0;
}