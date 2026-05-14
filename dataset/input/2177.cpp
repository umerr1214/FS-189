#include <iostream>

// Forward declarations
class Container;

class Box {
private:
    double length;

public:
    Box(double l) : length(l) {}

    friend void compareSizes(Box b, Container c);
};

class Container {
private:
    double volume;

public:
    Container(double v) : volume(v) {}

    friend void compareSizes(Box b, Container c);
};

void compareSizes(Box b, Container c) {
    std::cout << "Box length: " << b.length << std::endl;
    std::cout << "Container volume: " << c.volume << std::endl;

    // LOGICAL ERROR: The comparison operators are swapped, leading to incorrect messages.
    if (b.length < c.volume) { // This condition should ideally check for 'greater than' to match the message below
        std::cout << "Box length is greater than Container volume." << std::endl; // This message is incorrect for b.length < c.volume
    } else if (b.length > c.volume) { // This condition should ideally check for 'less than' to match the message below
        std::cout << "Container volume is greater than Box length." << std::endl; // This message is incorrect for b.length > c.volume
    } else {
        std::cout << "Box length is equal to Container volume." << std::endl;
    }
}

int main() {
    Box b1(10.5);
    Container c1(8.2);
    compareSizes(b1, c1);
    std::cout << "---" << std::endl;

    Box b2(5.0);
    Container c2(12.0);
    compareSizes(b2, c2);
    std::cout << "---" << std::endl;

    Box b3(7.7);
    Container c3(7.7);
    compareSizes(b3, c3);
    std::cout << "---" << std::endl;

    return 0;
}