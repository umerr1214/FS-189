#include <iostream>
#include <string>
#include <limits> // Required for std::numeric_limits

int main() {
    std::string firstName;
    int age = 0; // Initialize to 0 to clearly show potential failure
    double height = 0.0; // Initialize to 0.0 to clearly show potential failure

    std::cout << "Enter your first name: ";
    std::cin >> firstName;

    std::cout << "Enter your age: ";
    std::cin >> age; // If non-integer input, cin will fail, age remains 0

    std::cout << "Enter your height in meters: ";
    std::cin >> height; // If non-double input, cin will fail, height remains 0.0

    // This program lacks robustness.
    // It does not check if the numeric inputs (age, height) were successful.
    // If the user enters non-numeric data for age or height, std::cin will
    // enter a fail state, the variables will not be updated (or contain garbage),
    // and the program will continue with potentially incorrect values without
    // any warning or opportunity for the user to re-enter valid data.

    std::cout << "Hello " << firstName << ", you are " << age
              << " years old and " << height << " meters tall." << std::endl;

    return 0;
}