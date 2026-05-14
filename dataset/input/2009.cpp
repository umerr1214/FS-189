#include <iostream>

class Printer {
public:
    void print(int value) {
        std::cout << "Double: " << value << std::endl; // Logical Error: Prints "Double" label for an integer
    }

    void print(double value) {
        std::cout << "Double: " << value << std::endl;
    }

    void print(const char* value) {
        std::cout << "String: " << value << std::endl;
    }
};

int main() {
    Printer p;
    p.print(10);
    p.print(3.14);
    p.print("Hello C++");
    return 0;
}