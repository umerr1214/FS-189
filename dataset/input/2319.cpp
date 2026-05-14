#include <iostream> // Required for std::cout and std::endl

// Forward declaration of the PrivateData class is necessary
// because displayPrivateValue is declared as a friend function
// before PrivateData's full definition is available.
class PrivateData;

// Declaration of the external friend function.
// It takes a const reference to PrivateData to avoid copying and ensure read-only access.
void displayPrivateValue(const PrivateData& obj);

class PrivateData {
private:
    int value; // Private integer member

public:
    // Constructor to initialize the private member 'value'
    PrivateData(int v) : value(v) {}

    // Declare displayPrivateValue as a friend function.
    // This grants it access to private members of PrivateData.
    friend void displayPrivateValue(const PrivateData& obj);
};

// Definition of the friend function.
// It can directly access obj.value because it's a friend.
void displayPrivateValue(const PrivateData& obj) {
    std::cout << "Private Value: " << obj.value << '\n'; // Use '\n' for efficiency
}

int main() {
    // Create an instance of PrivateData
    PrivateData data(456);

    // Call the friend function to display the private value
    displayPrivateValue(data);

    return 0;
}