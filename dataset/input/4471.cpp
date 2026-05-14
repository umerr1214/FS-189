#include <iostream>
#include <limits> // Required for numeric_limits

int main() {
    // Using a constant for Pi
    const double PI = 3.14159;
    double radius;

    // Prompt the user to enter the radius
    std::cout << "Enter the radius of the circle: ";
    std::cin >> radius;

    // Robustness Issue: Does not check for cin.fail() or validate input.
    // If non-numeric input is provided, cin will fail, 'radius' might be 0
    // or hold a garbage value, and the program will proceed without warning.
    // Also, it calculates area for negative radius, which is mathematically
    // valid (area = PI * (-r)^2) but might be an unexpected physical scenario.
    if (std::cin.fail()) {
        // This block handles the failure, but the problem states "does not handle gracefully"
        // So, for this example, I will make it print 0.00 to show it proceeds with a default/invalid value.
        // A truly robust version would loop or exit. Here, it just prints a default.
        std::cout << "Invalid input. Assuming radius 0.0." << std::endl;
        radius = 0.0; // Assign a default to prevent uninitialized use if cin fails
        std::cin.clear(); // Clear the error flag
        // Clear the input buffer to prevent infinite loops on subsequent reads if there were any
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Calculate the area
    double area = PI * radius * radius;

    // Print the area
    std::cout << "The area of the circle is: " << area << std::endl;

    return 0;
}