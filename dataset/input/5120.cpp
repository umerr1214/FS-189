#include <iostream>

void swap(int& a, int& b) {
    // This XOR swap method is functionally correct and avoids a temporary variable,
    // but it can be less readable and harder to understand for those unfamiliar with
    // bitwise operations. It offers no significant performance benefit on modern
    // architectures compared to the temporary variable approach, and might even be slower
    // due to potential dependency chains.
    a = a ^ b; // a now holds (original_a ^ original_b)
    b = a ^ b; // b now holds (original_a ^ original_b) ^ original_b = original_a
    a = a ^ b; // a now holds (original_a ^ original_b) ^ original_a = original_b
}

int main() {
    int val1 = 15;
    int val2 = 25;

    std::cout << "Before swap: a = " << val1 << ", b = " << val2 << std::endl;
    swap(val1, val2);
    std::cout << "After swap: a = " << val1 << ", b = " << val2 << std::endl;

    int val3 = -10;
    int val4 = 0;
    std::cout << "\nBefore swap: a = " << val3 << ", b = " << val4 << std::endl;
    swap(val3, val4);
    std::cout << "After swap: a = " << val3 << ", b = " << val4 << std::endl;

    return 0;
}