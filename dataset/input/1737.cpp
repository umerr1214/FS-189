#include <iostream> // Required for std::cout and std::endl
#include <string>   // Required for std::string

// The Printer class is designed to demonstrate method overloading
// for different data types.
class Printer {
public:
    // Overloaded print method for integers.
    // Displays the integer value followed by a newline.
    void print(int number) {
        std::cout << "Integer: " << number << std::endl;
    }

    // Overloaded print method for strings.
    // Takes a constant reference to a string to avoid unnecessary copying,
    // which is efficient and good practice.
    // Displays the string content followed by a newline.
    void print(const std::string& text) {
        std::cout << "String: " << text << std::endl;
    }

    // Overloaded print method for characters.
    // Displays the character followed by a newline.
    void print(char character) {
        std::cout << "Character: " << character << std::endl;
    }
};

int main() {
    // Create an instance of the Printer class.
    Printer printer_instance;

    // Test the print method with an integer.
    printer_instance.print(42);

    // Test the print method with a string.
    printer_instance.print("This is a well-designed string.");

    // Test the print method with a character.
    printer_instance.print('K');
    printer_instance.print(' '); // Test with a space character

    return 0; // Indicate successful execution.
}