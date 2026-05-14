#include <iostream>
#include <string>
#include <iomanip> // For std::fixed and std::setprecision

int main() {
    std::string firstName;
    int age;
    // Semantic error: Declaring height as an int instead of a double
    int height; // Should be double height;

    std::cout << "Enter your first name: ";
    std::cin >> firstName;

    std::cout << "Enter your age: ";
    std::cin >> age;

    std::cout << "Enter your height in meters (e.g., 1.75): ";
    std::cin >> height; // Reading a double value into an int variable will truncate decimals

    std::cout << std::fixed << std::setprecision(2); // This formatting will not affect 'height' as it's an int
    std::cout << "Hello " << firstName << ", you are " << age << " years old and "
              << height << " meters tall." << std::endl;

    return 0;
}