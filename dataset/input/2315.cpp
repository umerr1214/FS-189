#include <iostream>

class PrivateData {
private:
    int value;
public:
    PrivateData(int val) : value(val) {}

    // Declare the external function as a friend
    friend void displayPrivateValue(const PrivateData& obj);
};

// Definition of the friend function
void displayPrivateValue(const PrivateData& obj) {
    // Logical error: The function prints a hardcoded value (0) instead of obj.value
    std::cout << "Private value: " << 0 << std::endl; // Should be obj.value
}

int main() {
    PrivateData obj1(10);
    displayPrivateValue(obj1);
    PrivateData obj2(99);
    displayPrivateValue(obj2);
    return 0;
}