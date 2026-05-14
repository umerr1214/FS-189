#include <iostream>
#include <cmath>    // Required for M_PI (or define a constant for PI)
#include <limits>   // Required for std::numeric_limits
#include <iomanip>  // Required for std::fixed and std::setprecision

// Define PI as a constant for accuracy and readability
#ifndef M_PI
    const double PI = 3.14159265358979323846;
#else
    const double PI = M_PI;
#endif

// Overloaded function to calculate the area of a circle
double calculateArea(double radius) {
    return PI * radius * radius;
}

// Overloaded function to calculate the area of a rectangle
double calculateArea(double length, double width) {
    return length * width;
}

// Function to handle robust double input
double getPositiveDoubleInput(const std::string& prompt) {
    double value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear(); // Clear the error flag
            // Discard invalid input from the buffer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if (value < 0) {
            std::cout << "Input cannot be negative. Please enter a positive number.\n";
            // Discard remaining input in the buffer if any
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            // Discard remaining input in the buffer if any
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
    }
}

int main() {
    int choice;

    std::cout << "Welcome to the Area Calculator!\n";

    while (true) {
        std::cout << "\nChoose which area to calculate:\n";
        std::cout << "1. Circle (using radius)\n";
        std::cout << "2. Rectangle (using length and width)\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice (1, 2, or 3): ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue; // Prompt again
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear buffer after reading choice

        if (choice == 1) {
            double radius = getPositiveDoubleInput("Enter the radius of the circle: ");
            std::cout << "The area of the circle is: "
                      << std::fixed << std::setprecision(4) << calculateArea(radius) << std::endl;
        } else if (choice == 2) {
            double length = getPositiveDoubleInput("Enter the length of the rectangle: ");
            double width = getPositiveDoubleInput("Enter the width of the rectangle: ");
            std::cout << "The area of the rectangle is: "
                      << std::fixed << std::setprecision(4) << calculateArea(length, width) << std::endl;
        } else if (choice == 3) {
            std::cout << "Exiting Area Calculator. Goodbye!\n";
            break; // Exit the loop
        } else {
            std::cout << "Invalid choice. Please enter 1, 2, or 3.\n";
        }
    }

    return 0;
}