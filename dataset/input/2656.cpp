#include <iostream>

class DataHolder {
private:
    int value;
public:
    DataHolder(int v) : value(v) {}
    int getValue() const { return value; }

    // Declare processData as a friend function
    friend void processData(DataHolder& dh);
};

// Syntax Error: Missing closing brace '}' for the processData function definition
void processData(DataHolder& dh) {
    dh.value = dh.value + 10;
// } <--- Missing here
}

class Processor {
public:
    // This class is required by the question but doesn't need specific functionality for this problem.
};

int main() {
    DataHolder myData(5);
    std::cout << "Initial value: " << myData.getValue() << std::endl;

    processData(myData);

    std::cout << "Processed value: " << myData.getValue() << std::endl;

    return 0;
}