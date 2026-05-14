#include <iostream>

class Rectangle {
public:
    Rectangle() {
        // Constructor, not explicitly required by the question, but good for completeness.
    }

    // Destructor definition with a syntax error (missing semicolon)
    ~Rectangle() {
        std::cout << "Rectangle object destroyed." << std::endl // Missing semicolon here
    }
};

int main() {
    {
        Rectangle r1; // r1 created
    } // r1 goes out of scope, destructor should be called
    
    Rectangle r2; // r2 created

    // The program will not compile due to the syntax error.

    return 0; // r2 goes out of scope, destructor should be called
}