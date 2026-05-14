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

    // Correct destructor implementation
    ~Rectangle() {
        std::cout << "Rectangle object destroyed." << '\n'; // Efficiently prints and adds newline
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