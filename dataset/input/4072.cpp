#include <iostream>

int main() {
    int height;
    std::cout << "Enter height: ";
    std::cin >> height // Missing semicolon here
    
    for (int i = 1; i <= height; ++i) {
        for (int j = 1; j <= i; ++j) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    
    return 0;
}