#include <iostream>

class DataStore {
private:
    int secretValue;

public:
    DataStore() : secretValue(0) {}

    int getSecretValue() {
        return secretValue;
    }

    void setSecretValue(int value) {
        secretValue = value;
    }
};

int main() {
    DataStore ds;

    std::cout << "Initial secret value: " << ds.getSecretValue() << std::endl;

    ds.setSecretValue(42);
    std::cout << "Set secret value to 42." << std::endl;

    std::cout << "Current secret value: " << ds.getSecretValue() << std::endl;

    // Semantic Error: Attempting to access a private member directly from outside the class.
    // This line specifically demonstrates that 'secretValue' cannot be accessed directly,
    // enforcing encapsulation as requested by the question.
    ds.secretValue = 100; // This will cause a compilation error (semantic error: cannot access private member)
    std::cout << "Attempted to set secretValue directly to 100." << std::endl;
    std::cout << "Value after direct access attempt: " << ds.secretValue << std::endl; // This will also cause an error

    return 0;
}