#include <iostream>

int main() {
    int arr[10];
    int sum = 0;
    double average;

    std::cout << "Enter 10 integers:\n";
    for (int i = 0; i < 10; ++i) {
        std::cout << "Enter integer " << i + 1 << ": ";
        // Semantic Error: Attempting to read input into the entire array 'arr'
        // instead of an individual element 'arr[i]'. The '>>' operator
        // does not have an overload for 'std::istream' and 'int[10]' (or 'int*').
        std::cin >> arr; // Should be std::cin >> arr[i];
        sum += arr[i];
    }

    average = static_cast<double>(sum) / 10;

    std::cout << "The sum of the elements is: " << sum << std::endl;
    std::cout << "The average of the elements is: " << average << std::endl;

    return 0;
}