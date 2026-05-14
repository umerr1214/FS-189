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

    double bmi = weight / (height * height);

    // Semantic Error: std::setprecision(2) without std::fixed sets precision to 2 significant digits,
    // not 2 decimal places as required by the problem statement.
    std::cout << "Your BMI is: " << std::setprecision(2) << bmi << std::endl;

    return 0;
}