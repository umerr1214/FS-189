#include <iostream>

// Forward declarations
class Container;

class Box {
private:
    double length;

public:
    Box(double l) : length(l) {}

    // Friend declaration for the non-member function (correctly declared for Box)
    friend void compareSizes(Box b, Container c);
};

class Container {
private:
    double volume;

public:
    Container(double v) : volume(v) {}

    // SEMANTIC ERROR: Missing friend declaration for compareSizes in Container.
    // The function 'compareSizes' will not be able to access private members of Container.
    // friend void compareSizes(Box b, Container c); // This line is missing
};

void compareSizes(Box b, Container c) {
    std::cout << "Box length: " << b.length << std::endl; // OK: 'Box' declared 'compareSizes' as friend
    std::cout << "Container volume: " << c.volume << std::endl; // ERROR: 'Container' did NOT declare 'compareSizes' as friend. Access violation.

    if (b.length > c.volume) {
        std::cout << "Box length is greater than Container volume." << std::endl;
    } else if (b.length < c.volume) {
        std::cout << "Container volume is greater than Box length." << std::endl;
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