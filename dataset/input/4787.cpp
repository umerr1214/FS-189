#include <iostream>
#include <numeric> // Not strictly needed for this simple sum, but good practice

int main() {
    int arr[10];
    int sum = 0; // sum is int
    double average;

    std::cout << "Enter 10 integers:\n";
    for (int i = 0; i < 10; ++i) {
        std::cout << "Enter integer " << i + 1 << ": ";
        std::cin >> arr[i];
        sum += arr[i];
    }

    // Logical Error: Integer division occurs here because 'sum' is an int.
    // The result of 'sum / 10' will be an integer (e.g., 55 / 10 = 5),
    // which is then implicitly converted to double (5.0) before assignment.
    average = sum / 10; 

    std::cout << "The sum of the elements is: " << sum << std::endl;
    std::cout << "The average of the elements is: " << average << std::endl;

    return 0;
}