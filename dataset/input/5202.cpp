#include <iostream>
#include <iomanip> // Required for std::fixed and std::setprecision

int main() {
    int input;
    long long sum = 0; // Use long long for sum to prevent overflow with large inputs
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

    if (count > 0) {
        // Semantic Error: Integer division
        // 'sum' is long long and 'count' is int. The division 'sum / count'
        // performs integer division, resulting in a long long value where
        // any fractional part is truncated. This truncated value is then
        // implicitly converted to a double and assigned to 'average'.
        // To fix: cast one of the operands to double before division, e.g.,
        // average = static_cast<double>(sum) / count;
        average = sum / count;

        std::cout << "Average of positive integers: " << std::fixed << std::setprecision(2) << average << std::endl;
    } else {
        std::cout << "No positive integers were entered." << std::endl;
    }

    return 0;
}