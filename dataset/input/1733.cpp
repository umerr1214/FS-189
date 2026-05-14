#include <iostream>
#include <string>

class Printer {
public:
    void print(int num) {
        std::cout << "Printing int: " << num << std::endl;
    }

    void print(const std::string& text) {
        // Logical error: Instead of printing the string, it prints a generic message.
        std::cout << "A string was printed." << std::endl;
    }

    void print(char character) {
        std::cout << "Printing char: " << character << std::endl;
    }
};

int main() {
    Printer p;
    p.print(42);
    p.print("Test String");
    p.print('C');
    p.print(0);
    p.print("Another String");
    p.print('Z');
    return 0;
}