#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>

int main() {
    const int SIZE = 8;
    int numbers[SIZE];
    int sum = 0; // sum is an int

    std::cout << "Enter " << SIZE << " integers:" << std::endl;

    for (int i = 0; i < SIZE; ++i) {
        std::cin >> numbers[i];
        sum += numbers[i];
    }

    // Logical Error: Integer division.
    // sum is int, SIZE is int. The result of sum / SIZE will be an int,
    // truncating any decimal part before being assigned to a double.
    double average = sum / SIZE;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "The average of the numbers is: " << average << std::endl;

    return 0;
}