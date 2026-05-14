#include <iostream>

int main() {
    int num;
    std::cout << "Enter an integer: ";
    std::cin >> num // Missing semicolon here
    for (int i = 1; i <= 10; ++i) {
        std::cout << num << " x " << i << " = " << (num * i) << std::endl;
    }
    return 0;
}