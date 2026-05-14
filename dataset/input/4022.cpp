#include <iostream>
#include <iomanip>

int main() { double l, w; std::cout << "Enter the length of the rectangle: "; std::cin >> l; std::cout << "Enter the width of the rectangle: "; std::cin >> w; double a = l * w; double p = 2 * (l + w); std::cout << std::fixed << std::setprecision(2); std::cout << "Area: "; std::cout << a; std::cout << "\n"; std::cout << "Perimeter: "; std::cout << p; std::cout << "\n"; return 0; }