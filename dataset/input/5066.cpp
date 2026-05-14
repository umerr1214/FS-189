#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

int main() {
    // Using uninformative, single-letter variable names
    double l, w; 

    // Prompt and input for rectangle dimensions
    std::cout << "Input length: ";
    std::cin >> l; // 'l' for length

    std::cout << "Input width: ";
    std::cin >> w; // 'w' for width

    // Calculate area and perimeter using cryptic variable names
    double a = l * w;       // 'a' for area
    double p = 2 * (l + w); // 'p' for perimeter

    // Output results with less descriptive labels and minimal formatting
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Area result: " << a << std::endl;
    std::cout << "Perimeter result: " << p << std::endl;

    return 0;
}