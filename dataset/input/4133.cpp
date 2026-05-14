#include <iostream>
#include <string>
#include <limits> // For std::numeric_limits

void solve() {
    std::string fullName;
    std::cout << "Please enter your full name: ";
    // Logical Error: Using operator>> for std::string reads only up to the first whitespace.
    // It does not read the entire line as required by the question.
    std::cin >> fullName;
    
    // Clear the rest of the line from the buffer to prevent issues with subsequent inputs
    // (though for this simple program, it's not strictly necessary for correctness,
    // it's good practice when mixing >> and getline)
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Full Name: " << fullName << std::endl;
    std::cout << "Number of characters: " << fullName.length() << std::endl;
}

int main() {
    solve();
    return 0;
}