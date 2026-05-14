#include <iostream>

class PrivateData {
private:
    int value;
public:
    PrivateData(int val) : value(val) {}

    // Semantic error: The 'friend' declaration for displayPrivateValue is missing.
    // friend void displayPrivateValue(const PrivateData& obj); // This line is commented out
};

// Forward declaration of the function (necessary for its definition later)
void displayPrivateValue(const PrivateData& obj);

// Definition of the function
void displayPrivateValue(const PrivateData& obj) {
    // This will cause a compile-time error because 'obj.value' is a private member
    // and 'displayPrivateValue' is not declared as a friend of 'PrivateData'.
    std::cout << "Private value: " << obj.value << std::endl;
}

int main() {
    PrivateData obj1(10);
    // The program will not compile due to the semantic error (access violation).
    // If it were to compile, it would attempt to call the display function.
    // displayPrivateValue(obj1);
    // PrivateData obj2(99);
    // displayPrivateValue(obj2);
    return 0;
}