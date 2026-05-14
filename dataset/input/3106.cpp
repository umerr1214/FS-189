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

    // This line contains a syntax error: an extra '<' in the output stream operator.
    std::cout << "Demonstrating a syntax error." <<< std::endl;

    // The question asks to demonstrate that secretValue cannot be accessed directly.
    // This attempt would result in a semantic error if the program compiled.
    // ds.secretValue = 100;
    // std::cout << "Attempted direct access (should fail for private): " << ds.secretValue << std::endl;

    return 0;
}