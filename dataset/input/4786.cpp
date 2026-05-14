#include <iostream>
#include <numeric> // Not strictly needed for this simple sum, but good practice

int main() {
    int arr[10];
    int sum = 0;
    double average;

    std::cout << "Enter 10 integers:\n" // Syntax Error: Missing semicolon
    for (int i = 0; i < 10; ++i) {
        std::cout << "Enter integer " << i + 1 << ": ";
        std::cin >> arr[i];
        sum += arr[i];
    }

    average = static_cast<double>(sum) / 10;

    std::cout << "The sum of the elements is: " << sum << std::endl;
    std::cout << "The average of the elements is: " << average << std::endl;

    return 0;
}