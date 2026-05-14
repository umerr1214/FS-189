#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>

int main() {
    const int SIZE = 8;
    int numbers[SIZE];
    int sum; // Semantic Error: 'sum' is declared but not initialized

    std::cout << "Enter " << SIZE << " integers:" << std::endl;

    for (int i = 0; i < SIZE; ++i) {
        std::cin >> numbers[i];
        // The first iteration will use an uninitialized 'sum', leading to undefined behavior.
        sum += numbers[i];
    }

    double average = static_cast<double>(sum) / SIZE;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "The average of the numbers is: " << average << std::endl;

    return 0;
}