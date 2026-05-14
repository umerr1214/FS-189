#include <iostream>
#include <iomanip> // For output formatting

int main() {
    int arrayData[10]; // Less descriptive variable name 'arrayData'
    float sum_val = 0.0f; // Readability/Efficiency Issue: Using float instead of double for sum, less precision
    float avg_val;        // Using float for average, less precision

    std::cout << "Enter 10 numbers for processing:" << std::endl;

    for (int idx = 0; idx < 10; ++idx) { // Using 'idx' instead of 'i' or 'index'
        std::cout << "Num " << idx + 1 << ": ";
        std::cin >> arrayData[idx];
        sum_val += arrayData[idx]; // Summing as float, potentially losing precision for large numbers
    }

    avg_val = sum_val / 10.0f; // Using float division, and magic number 10 instead of a named constant

    std::cout << std::fixed << std::setprecision(3) << "Resulting average is: " << avg_val << std::endl; // Slightly different precision than optimal

    return 0;
}