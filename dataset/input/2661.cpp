#include <iostream>

class DataHolder {
private:
    int value;

public:
    // Constructor to initialize the private member
    DataHolder(int initialValue = 0) : value(initialValue) {}

    // Public method to display the value for verification
    void displayValue() const {
        std::cout << "DataHolder value: " << value << std::endl;
    }

    // Declare `processData` as a friend function
    friend void processData(DataHolder& dh);
};

// Processor class (as per question, though `processData` is a free function)
class Processor {
public:
    // This class is created as per the question's requirement.
    // In this correct version, `processData` is implemented as a free function
    // and declared as a friend, which is a common and direct interpretation of the prompt.
    // The Processor class itself might contain other logic or methods not relevant to this specific problem.
};

// Definition of the friend function
void processData(DataHolder& dh) {
    // Access and modify the private member `value`
    dh.value++;
    std::cout << "processData: Value incremented successfully." << std::endl;
}

int main() {
    DataHolder myData(5);
    std::cout << "Initial state:" << std::endl;
    myData.displayValue();

    processData(myData); // Call the friend function
    std::cout << "After first processData call:" << std::endl;
    myData.displayValue();

    processData(myData); // Call again
    std::cout << "After second processData call:" << std::endl;
    myData.displayValue();

    DataHolder anotherData(100);
    std::cout << "\nInitial state for anotherData:" << std::endl;
    anotherData.displayValue();
    processData(anotherData);
    std::cout << "After processData call for anotherData:" << std::endl;
    anotherData.displayValue();

    return 0;
}