#include <iostream>

class DataHolder {
private:
    int value;
public:
    DataHolder(int v) : value(v) {}
    int getValue() const { return value; }

    // Semantic Error: The 'friend' declaration for processData is missing.
    // friend void processData(DataHolder& dh); // This line is commented out or missing.
};

// Forward declaration of processData (good practice but not strictly needed for this error)
// void processData(DataHolder& dh);

void processData(DataHolder& dh) {
    // This line attempts to access a private member 'value' without 'processData'
    // being declared as a friend, leading to a semantic error during compilation.
    dh.value = dh.value + 10;
}

class Processor {
public:
    // This class is required by the question but doesn't need specific functionality for this problem.
};

int main() {
    DataHolder myData(5);
    std::cout << "Initial value: " << myData.getValue() << std::endl;

    // This call will result in a compilation error due to the semantic violation
    processData(myData);

    std::cout << "Processed value: " << myData.getValue() << std::endl;

    return 0;
}