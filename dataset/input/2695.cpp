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

    // Destructor with a robustness issue:
    // This destructor is implemented correctly, but the robustness issue
    // will be demonstrated by intentionally leaking a heap-allocated object,
    // preventing its destructor from being called.
    ~Rectangle() {
        std::cout << "Rectangle object destroyed." << std::endl;
    }
};

void createAndDestroyLocal() {
    Rectangle localRect(3, 4); // Destructor called when function exits
    std::cout << "  Inside createAndDestroyLocal function." << std::endl;
}

int main() {
    std::cout << "Main function started." << std::endl;

    // Robustness Issue: A heap-allocated object that is never deleted.
    // Its destructor will not be called, leading to a resource leak (in a real scenario)
    // and preventing the expected message from being printed for this specific object.
    Rectangle* leakedRect = new Rectangle(10, 20);
    std::cout << "  Creating a leaked Rectangle object." << std::endl;
    // No 'delete leakedRect;' here, demonstrating the robustness issue.

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