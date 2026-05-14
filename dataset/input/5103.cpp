#include <iostream> // Required for std::cin, std::cout, std::endl
#include <string>   // Required for std::string

int main() {
    // Optimize C++ standard streams for faster I/O.
    // This unties cin from cout and prevents synchronization with C stdio.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string firstName;
    int age;
    double height;

    // Prompt user for first name and read input
    std::cout << "Enter your first name: ";
    std::cin >> firstName; // Reads a single word for the first name

    // Prompt user for age and read input
    std::cout << "Enter your age: ";
    std::cin >> age;

    // Prompt user for height and read input
    std::cout << "Enter your height in meters: ";
    std::cin >> height;

    // Print the formatted summary using chained output for readability and efficiency
    std::cout << "Hello " << firstName << ", you are " << age
              << " years old and " << height << " meters tall." << std::endl;

    return 0; // Indicate successful program execution
}