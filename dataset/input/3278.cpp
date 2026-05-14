#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision
#include <cmath>   // Unnecessary include for this simple calculation

int main() {
    // Readability Issue: Poor, non-descriptive variable names
    double w; // Represents weight in kilograms
    double h; // Represents height in meters

    std::cout << "Enter your weight in kilograms: ";
    std::cin >> w;

    std::cout << "Enter your height in meters: ";
    std::cin >> h;

    // Readability Issue: Lack of comments explaining the formula or steps
    double res = w / (h * h); // Calculate BMI

    // Outputting the result
    std::cout << std::fixed << std::setprecision(2) << "Your BMI is: " << res << std::endl;

    return 0;
}