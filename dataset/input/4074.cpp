#include <iostream>

int main() {
    int height;
    std::cout << "Enter height: ";
    std::cin >> height;
    
    // Semantic error: The pattern is slightly off due to incorrect loop bounds interpretation
    // For height N, it prints a triangle of height N-1, and the first row is empty.
    for (int i = 0; i < height; ++i) { // Outer loop from 0 to height-1
        for (int j = 0; j < i; ++j) { // Inner loop from 0 to i-1, meaning it prints 'i' stars
                                     // For i=0, j<0 is false, so 0 stars
                                     // For i=1, j<1 means j=0, so 1 star
                                     // For i=2, j<2 means j=0,1, so 2 stars
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    
    return 0;
}