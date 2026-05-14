#include <iostream>
#include <string>
#include <iomanip> // Included for potential use, but specific manipulators are avoided for robustness issue

class Printer {
public:
    // Robustness Issue: print methods are not declared as const, even though they don't modify object state.
    // This limits their use with const Printer objects, reducing interface robustness.
    void print(std::string s) {
        std::cout << "String: " << s << std::endl; // Using std::endl for string and double, \n for int and bool for inconsistency
    }

    void print(int i) {
        std::cout << "Int: " << i << "\n";
    }

    void print(double d) {
        std::cout << "Double: " << d << std::endl;
    }

    // Robustness Issue: Does not use std::boolalpha. Prints '1' for true and '0' for false.
    // This can lead to issues if the output is consumed by a system expecting literal "true"/"false" strings.
    void print(bool b) {
        std::cout << "Bool: " << b << "\n";
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