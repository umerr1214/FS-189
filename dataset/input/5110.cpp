#include <iostream>

int main() {
    int num;
    do {
        std::cout << "Enter a positive integer: " // Missing semicolon here
        std::cin >> num;
    } while (num <= 0);

    std::cout << "You entered: " << num << std::endl;

    return 0;
}