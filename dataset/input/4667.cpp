#include <iostream>

int main() {
    long long num_input;
    int count = 0;

    std::cout << "Enter a non-negative integer: ";
    std::cin >> num_input;

    if (num_input < 0) {
        std::cout << "Input must be a non-negative integer." << std::endl;
        return 1;
    }

    // Logical error: If num_input is 0, the loop won't execute, and count will remain 0.
    // The correct count for 0 is 1.
    long long temp_num = num_input;
    while (temp_num > 0) {
        temp_num /= 10;
        count++;
    }

    std::cout << "The number " << num_input << " has " << count << " digits." << std::endl;

    return 0;
}