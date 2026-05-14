#include <iostream>

// Forward declaration of PrivateData class
class PrivateData;

// Declaration of the friend function
void displayPrivateValue(const PrivateData& obj);

class PrivateData {
private:
    int value; // Member 'value' is private

public:
    // No explicit constructor provided.
    // 'value' will be uninitialized if a default PrivateData object is created.
    void setValue(int v) {
        value = v;
    }

    // Declare displayPrivateValue as a friend function
    friend void displayPrivateValue(const PrivateData& obj);
};

// Definition of the friend function
// This function can access the private member 'value' of PrivateData objects
void displayPrivateValue(const PrivateData& obj) {
    std::cout << "Private Value: " << obj.value << std::endl;
}

int main() {
    // Create a PrivateData object without explicitly initializing 'value'
    // 'value' will hold an indeterminate (garbage) value in this case.
    PrivateData p;
    // p.setValue(100); // If this line is uncommented, it works as expected.
                     // But for robustness issue, we leave it uninitialized.

    std::cout << "Attempting to display uninitialized private value:" << std::endl;
    displayPrivateValue(p); // This will print an indeterminate value.

    // Example of setting a value later, to show it works if initialized
    p.setValue(200);
    std::cout << "Attempting to display initialized private value:" << std::endl;
    displayPrivateValue(p);

    return 0;
}