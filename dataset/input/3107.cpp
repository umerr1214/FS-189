#include <iostream>

class DataStore {
private:
    int secretValue;

public:
    DataStore() : secretValue(0) {}

    int getSecretValue() {
        return secretValue;
    }

    // Logical Error: The parameter 'secretValue' shadows the member 'secretValue'.
    // The assignment 'secretValue = secretValue' assigns the parameter to itself,
    // leaving the class member 'this->secretValue' unchanged.
    void setSecretValue(int secretValue) { // Parameter name is the same as member name
        secretValue = secretValue;         // Assigns parameter to parameter, not to this->secretValue
    }
};

int main() {
    DataStore ds;

    std::cout << "Initial secret value: " << ds.getSecretValue() << std::endl; // Expected: 0

    ds.setSecretValue(42);
    std::cout << "Attempted to set secret value to 42." << std::endl;

    std::cout << "Current secret value after setting: " << ds.getSecretValue() << std::endl; // Expected: 42, Actual: 0 (Logical Error)

    // The question asks to demonstrate encapsulation. This line would cause a semantic error.
    // ds.secretValue = 100;
    // std::cout << "Attempted direct access (should fail for private): " << ds.secretValue << std::endl;

    return 0;
}