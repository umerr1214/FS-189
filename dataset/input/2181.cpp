#include <iostream>
#include <string>
#include <algorithm> // For std::max

// Forward declaration of Container is necessary because Box's friend declaration refers to it.
class Container;

class Box {
private:
    int length;
public:
    // Constructor with basic input validation for non-negative length
    Box(int l) : length(std::max(0, l)) {
        if (l < 0) {
            std::cerr << "Warning: Box length cannot be negative. Setting to 0.\n";
        }
    }

    // Declare compareSizes as a friend function, passing by const reference for efficiency
    friend void compareSizes(const Box& b, const Container& c);
};

class Container {
private:
    int volume;
public:
    // Constructor with basic input validation for non-negative volume
    Container(int v) : volume(std::max(0, v)) {
        if (v < 0) {
            std::cerr << "Warning: Container volume cannot be negative. Setting to 0.\n";
        }
    }

    // Declare compareSizes as a friend function, passing by const reference for efficiency
    friend void compareSizes(const Box& b, const Container& c);
};

// Non-member friend function to compare sizes, taking objects by const reference
void compareSizes(const Box& b, const Container& c) {
    std::cout << "Comparing Box (length: " << b.length << ") and Container (volume: " << c.volume << "):\n";
    if (b.length < c.volume) {
        std::cout << "  Box's length is less than Container's volume.\n";
    } else if (b.length > c.volume) {
        std::cout << "  Box's length is greater than Container's volume.\n";
    } else {
        std::cout << "  Box's length is equal to Container's volume.\n";
    }
    std::cout << "\n";
}

int main() {
    Box box1(10);
    Container cont1(20);
    compareSizes(box1, cont1);

    Box box2(30);
    Container cont2(15);
    compareSizes(box2, cont2);

    Box box3(25);
    Container cont3(25);
    compareSizes(box3, cont3);

    // Test with invalid inputs to show validation handling
    Box box4(-5); // Length will be set to 0
    Container cont4(10);
    compareSizes(box4, cont4);

    Box box5(0);
    Container cont5(-10); // Volume will be set to 0
    compareSizes(box5, cont5);

    return 0;
}