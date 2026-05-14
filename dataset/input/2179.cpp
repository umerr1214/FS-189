#include <iostream>
#include <string>

// Forward declaration of Container is necessary because Box's friend declaration refers to it.
class Container;

class Box {
private:
    int length;
public:
    // Constructor allows any integer value, including non-positive ones.
    Box(int l) : length(l) {}

    // Declare compareSizes as a friend function
    friend void compareSizes(Box b, Container c);
};

class Container {
private:
    int volume;
public:
    // Constructor allows any integer value, including non-positive ones.
    Container(int v) : volume(v) {}

    // Declare compareSizes as a friend function
    friend void compareSizes(Box b, Container c);
};

// Non-member friend function to compare sizes
void compareSizes(Box b, Container c) {
    // This function treats length and volume purely as integers.
    // It doesn't robustly handle cases where length or volume might be non-positive,
    // which for physical dimensions could be considered invalid.
    // The output might be misleading for such inputs without specific checks or warnings.
    std::cout << "Comparing Box (length: " << b.length << ") and Container (volume: " << c.volume << "):\n";
    if (b.length < c.volume) {
        std::cout << "Box's length is less than Container's volume.\n";
    } else if (b.length > c.volume) {
        std::cout << "Box's length is greater than Container's volume.\n";
    } else {
        std::cout << "Box's length is equal to Container's volume.\n";
    }
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

    // Robustness issue demonstration: Testing with non-positive values.
    // The program doesn't crash, but the interpretation of "size" for these inputs
    // might be considered not robust without explicit handling or validation.
    Box box4(0);
    Container cont4(10);
    compareSizes(box4, cont4);

    Box box5(-5);
    Container cont5(5);
    compareSizes(box5, cont5);

    Box box6(10);
    Container cont6(-20);
    compareSizes(box6, cont6);

    return 0;
}