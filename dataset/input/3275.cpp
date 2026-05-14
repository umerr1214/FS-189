#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

int main() {
    double weight, height;

    std::cout << "Enter weight in kilograms: ";
    std::cin >> weight;

    std::cout << "Enter height in meters: ";
    std::cin >> height;

    if (height <= 0) {
        std::cout << "Height must be positive." << std::endl;
        return 1;
    }

    // Logical Error: Operator precedence mistake.
    // weight / height * height evaluates to (weight / height) * height, which simplifies to 'weight'.
    // The correct formula is weight / (height * height).
    double bmi = weight / height * height; 

    std::cout << "Your BMI is: " << std::fixed << std::setprecision(2) << bmi << std::endl;

    return 0;
}