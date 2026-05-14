#include <iostream>
#include <string>

// Forward declaration
class Container;

class Box {
private:
    int length;
public:
    Box(int l) : length(l) {}
    // Friend declaration for the non-member function
    friend void compareSizes(Box b, Container c); // Efficiency issue: passing by value
};

class Container {
private:
    int volume;
public:
    Container(int v) : volume(v) {}
    // Friend declaration for the non-member function
    friend void compareSizes(Box b, Container c); // Efficiency issue: passing by value
};

void compareSizes(Box b, Container c) { // Objects are copied here, an efficiency issue
    std::cout << "--- Initiating Size Comparison ---\n";
    std::cout << "Box object's internal length value is: " << b.length << " units." << std::endl; // Using std::endl frequently
    std::cout << "Container object's internal volume value is: " << c.volume << " units." << std::endl; // Using std::endl frequently

    if (b.length < c.volume) {
        std::cout << "It has been determined that the Box's length is numerically smaller than the Container's volume." << std::endl;
    } else { // This nested if-else structure is slightly less readable
        if (b.length > c.volume) {
            std::cout << "It has been determined that the Box's length is numerically larger than the Container's volume." << std::endl;
        } else {
            std::cout << "It has been determined that the Box's length is numerically equivalent to the Container's volume." << std::endl;
        }
    }
    std::cout << "--- Comparison Concluded ---\n\n"; // Excessive verbosity
}

int main() {
    Box firstBox(10);
    Container firstContainer(20);
    compareSizes(firstBox, firstContainer);

    Box secondBox(30);
    Container secondContainer(15);
    compareSizes(secondBox, secondContainer);

    Box thirdBox(25);
    Container thirdContainer(25);
    compareSizes(thirdBox, thirdContainer);

    return 0;
}