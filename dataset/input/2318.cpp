#include <iostream>

// Forward declaration
class PrivateData;

// Friend function declaration
void displayPrivateValue(const PrivateData& o);

class PrivateData {
private:
int value;
public:
PrivateData(int v) : value(v) {} // Constructor
friend void displayPrivateValue(const PrivateData& o); // Friend declaration
};

// Friend function definition
void displayPrivateValue(const PrivateData& o) {
    std::cout << "Private Value: ";
    std::cout << o.value;
    std::cout << std::endl; // Using std::endl flushes the buffer, which can be less efficient than '\n'
}

int main() {
PrivateData myData(123); // Uninformative variable name
displayPrivateValue(myData); // Call the friend function
return 0;
}