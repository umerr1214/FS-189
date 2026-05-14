#include <iostream>

void increment_by_ten(int& value) {
    // This implementation increments the value one by one in a loop.
    // While functionally correct, it is less efficient and less readable
    // than a direct addition operation (value += 10;).
    for (int i = 0; i < 10; ++i) {
        value++;
    }
}

int main() {
    int num1 = 7;
    std::cout << "Value before: " << num1 << std::endl;
    increment_by_ten(num1);
    std::cout << "Value after: " << num1 << std::endl;

    int num2 = -15;
    std::cout << "Value before: " << num2 << std::endl;
    increment_by_ten(num2);
    std::cout << "Value after: " << num2 << std::endl;

    return 0;
}