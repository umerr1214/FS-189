#include <iostream>
#include <string>
#include <iomanip> // For std::fixed and std::setprecision

int main() {
    std::string firstName;
    int age;
    double height;

    std::cout << "Enter your first name: ";
    std::cin >> firstName;

    std::cout << "Enter your age: ";
    std::cin >> age;

    std::cout << "Enter your height in meters (e.g., 1.75): ";
    std::cin >> height;

    std::cout << std::fixed << std::setprecision(2); // Format height to 2 decimal places
    // Logical error: printing age for height instead of the actual height variable
    std::cout << "Hello " << firstName << ", you are " << age << " years old and "
              << age << " meters tall." << std::endl; // Should be 'height' here

    return 0;
}