#include <iostream>
#include <string>
#include <iomanip> // For std::fixed and std::setprecision

int main() {
    std::string firstName;
    int age;
    double height;

    std::cout << "Enter your first name: " // Missing semicolon here
    std::cin >> firstName;

    std::cout << "Enter your age: ";
    std::cin >> age;

    std::cout << "Enter your height in meters (e.g., 1.75): ";
    std::cin >> height;

    std::cout << std::fixed << std::setprecision(2); // Format height to 2 decimal places
    std::cout << "Hello " << firstName << ", you are " << age << " years old and "
              << height << " meters tall." << std::endl;

    return 0;
}