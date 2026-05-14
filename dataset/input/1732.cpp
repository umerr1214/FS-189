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
}; // Missing semicolon here, causing a syntax error

int main() {
    Printer p;
    p.print(123);
    p.print("Hello, World!");
    p.print('X');
    return 0;
}