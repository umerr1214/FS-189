#include <iostream>
#include <string>
#include <vector>

class Rectangle {
private:
    int width;
    int height;

public:
    Rectangle(int w, int h) : width(w), height(h) {
        // Constructor, not the focus of the question
    }

    // Destructor with a readability/efficiency issue:
    // Using string concatenation for a simple literal message and then
    // printing with std::endl (which flushes the buffer) is less efficient
    // than a direct string literal with '\n'.
    ~Rectangle() {
        std::string message = "Rectangle object " + std::string("destroyed.");
        std::cout << message << std::endl; // std::endl flushes, less efficient than '\n'
    }
};

void createAndDestroyLocal() {
    Rectangle localRect(3, 4); // Destructor called when function exits
    std::cout << "  Inside createAndDestroyLocal function." << std::endl;
}

int main() {
    std::cout << "Main function started." << std::endl;

    Rectangle mainRect(5, 6); // Destructor called when main exits

    {
        std::cout << "  Entering inner block." << std::endl;
        Rectangle blockRect(7, 8); // Destructor called when block exits
        std::cout << "  Exiting inner block." << std::endl;
    } // blockRect destroyed here

    createAndDestroyLocal(); // localRect destroyed here

    std::cout << "Main function about to end." << std::endl;
    // mainRect destroyed here
    return 0;
}