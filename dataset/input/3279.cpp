#include <iostream> // For input/output operations (std::cout, std::cin)
#include <iomanip>  // For output formatting (std::fixed, std::setprecision)

int main() {
    // Declare variables to store weight and height
    double weight_kg;
    double height_m;

    // Prompt user for weight input
    std::cout << "Enter your weight in kilograms: ";
    std::cin >> weight_kg;

    // Prompt user for height input
    std::cout << "Enter your height in meters: ";
    std::cin >> height_m;

    // Basic input validation for a robust solution
    if (weight_kg <= 0 || height_m <= 0) {
        std::cerr << "Error: Weight and height must be positive values." << std::endl;
        return 1; // Indicate an error
    }

    // Calculate BMI using the formula: weight / (height * height)
    double bmi = weight_kg / (height_m * height_m);

    // Display the result formatted to two decimal places
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Your BMI is: " << bmi << std::endl;

    return 0; // Indicate successful execution
}