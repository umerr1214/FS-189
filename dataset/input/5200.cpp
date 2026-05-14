#include <iostream>

int main() {
    int input;
    long long sum = 0;
    int count = 0;
    double average;

    std::cout << "Enter positive integers (enter -1 to terminate): " << std::endl;

    while (true) {
        std::cin >> input;

        if (input == -1) {
            break;
        }

        if (input > 0) {
            sum += input;
            count++;
        }
    }

    int dummyVar // Syntax Error: Missing semicolon here

    if (count > 0) {
        average = static_cast<double>(sum) / count;
        std::cout << "Average of positive integers: " << average << std::endl;
    } else {
        std::cout << "No positive integers were entered." << std::endl;
    }

    return 0;
}