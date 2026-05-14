#include <iostream>
#include <string>
#include <iomanip> // For std::boolalpha

/**
 * @brief A class that provides overloaded print methods to display various data types to the console.
 */
class Printer {
public:
    /**
     * @brief Prints a string value to the console.
     * @param s The string to print. Passed by const reference for efficiency.
     */
    void print(const std::string& s) const {
        std::cout << "String: " << s << '\n';
    }

    /**
     * @brief Prints an integer value to the console.
     * @param i The integer to print.
     */
    void print(int i) const {
        std::cout << "Int: " << i << '\n';
    }

    /**
     * @brief Prints a double value to the console.
     * @param d The double to print.
     */
    void print(double d) const {
        std::cout << "Double: " << d << '\n';
    }

    /**
     * @brief Prints a boolean value to the console as 'true' or 'false'.
     * @param b The boolean to print. Uses std::boolalpha for clear output.
     */
    void print(bool b) const {
        std::cout << "Bool: " << std::boolalpha << b << '\n';
    }
};

int main() {
    Printer p;
    p.print("Hello, C++!");
    p.print(123);
    p.print(45.6789);
    p.print(true);
    p.print("");
    p.print(-5);
    p.print(0.0);
    p.print(false);
    return 0;
}