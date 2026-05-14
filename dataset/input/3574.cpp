#include <iostream>
#include <algorithm> // For std::max

int main() {
    int num1, num2, num3;
    std::cout << "Enter three integers: " // Syntax Error: Missing semicolon
    std::cin >> num1 >> num2 >> num3;

    int largest = num1;
    if (num2 > largest) {
        largest = num2;
    }
    if (num3 > largest) {
        largest = num3;
    }

    std::cout << "The largest number is: " << largest << std::endl;

    return 0;
}