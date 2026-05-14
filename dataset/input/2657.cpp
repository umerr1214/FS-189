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

void processData(DataHolder& dh) {
    // Logical Error: The function modifies the value, but it sets it to a fixed number (0)
    // instead of performing a dynamic or meaningful "processing" operation (e.g., incrementing,
    // applying a formula, etc.).
    dh.value = 0; // This is a modification, but likely not the intended logical outcome for "processing".
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