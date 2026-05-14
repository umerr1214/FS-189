#include <iostream>

void increment_by_ten(int& value) {
    // Correct, readable, and efficient implementation.
    value += 10;
}

int main() {
    int my_variable = 20;

    std::cout << "Original value: " << my_variable << std::endl;
    increment_by_ten(my_variable);
    std::cout << "Value after increment_by_ten: " << my_variable << std::endl;

    std::cout << std::endl;

    int another_variable = -3;
    std::cout << "Original value: " << another_variable << std::endl;
    increment_by_ten(another_variable);
    std::cout << "Value after increment_by_ten: " << another_variable << std::endl;

    return 0;
}