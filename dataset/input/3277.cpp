#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

int main() {
    double weight_kg;
    double height_m;

    std::cout << "Enter your weight in kilograms: ";
    std::cin >> weight_kg;

    std::cout << "Enter your height in meters: ";
    std::cin >> height_m;

    // Robustness Issue: No check for height_m being zero.
    // If height_m is 0, this will result in division by zero,
    // producing 'inf' or 'nan' for BMI, or potentially a crash
    // depending on the environment and specific calculation.
    double bmi = weight_kg / (height_m * height_m);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Your BMI is: " << bmi << std::endl;

    return 0;
}