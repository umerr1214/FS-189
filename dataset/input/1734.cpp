#include <iostream>
#include <string>

class Printer {
public:
    void print(int num) {
        std::cout << "Printing int: " << num << std::endl;
    }

    void print(const std::string& text) {
        std::cout << "Printing string: " << text << std::endl;
    }

    void print(char character) {
        std::cout << "Printing char: " << character << std::endl;
    }
};

int main() {
    Printer p;
    p.print(100);
    p.print("Hello");
    // Semantic error: Attempting to pass a C-style string literal ("A")
    // to a method that expects a single 'char' type.
    // The compiler will report "no matching function for call to 'Printer::print(const char*)'"
    // or similar, as "A" is a const char[2] and not implicitly convertible to char.
    p.print("A"); 
    p.print('B');
    return 0;
}