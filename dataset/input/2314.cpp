#include <iostream>

// Forward declaration of the friend function
// This is needed if the friend function is defined before the class or if it's external
void displayPrivateValue(const PrivateData& obj); // Syntax error: PrivateData is not yet defined here

class PrivateData {
private:
    int value;
public:
    PrivateData(int val) : value(val) {}
}; // Missing semicolon here, will cause a syntax error

// Definition of the friend function
// This function needs to be declared as a friend inside PrivateData to access 'value'
void displayPrivateValue(const PrivateData& obj) {
    std::cout << "Private value: " << obj.value << std::endl;
}

int main() {
    PrivateData obj1(10);
    // The program will not compile due to the syntax error.
    // If it were to compile, it would call the display function.
    // displayPrivateValue(obj1); 
    // PrivateData obj2(99);
    // displayPrivateValue(obj2);
    return 0;
}