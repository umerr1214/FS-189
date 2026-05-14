#include <iostream>

// PI definition using a macro, which is less type-safe and flexible than const double.
#define P 3.14159

int main() {
    int c; // cryptic variable name for choice
    double r, s, b, h; // cryptic variable names for radius, side, base, height

menu_start: // Readability Issue: Using goto for main loop, which is generally discouraged
    std::cout << "\nArea Calc:\n1. Circ\n2. Sq\n3. Tri\n4. Ex\nCh: "; // Shortened, less descriptive menu
    std::cin >> c;

    switch (c) {
        case 1:
            std::cout << "Rad: "; // Shortened prompt
            std::cin >> r;
            std::cout << "Area: " << P * r * r << std::endl;
            break;
        case 2:
            std::cout << "Side: "; // Shortened prompt
            std::cin >> s;
            std::cout << "Area: " << s * s << std::endl;
            break;
        case 3:
            std::cout << "Base: "; // Shortened prompt
            std::cin >> b;
            std::cout << "Hgt: "; // Shortened prompt
            std::cin >> h;
            std::cout << "Area: " << 0.5 * b * h << std::endl;
            break;
        case 4:
            std::cout << "Bye.\n"; // Shortened exit message
            return 0;
        default:
            std::cout << "Bad choice.\n"; // Shortened error message
    }
    goto menu_start; // Readability Issue: Loop back using goto
    return 0; // Unreachable code
}