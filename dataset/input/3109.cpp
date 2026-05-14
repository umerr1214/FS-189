#include <iostream>

class DataStore {
private:
    int secretValue;

public:
    // Constructor to ensure secretValue is always initialized to a valid state.
    // For this demonstration, we initialize it to 0.
    DataStore() : secretValue(0) {}

    // Public method to access secretValue.
    // Marked 'const' as it does not modify the object's state.
    int getSecretValue() const {
        return secretValue;
    }

    // Public method to modify secretValue.
    void setSecretValue(int value) {
        // Robustness Issue: No input validation.
        // If 'secretValue' were expected to be, for example, non-negative,
        // allowing arbitrary values (like negative numbers) without any warning
        // or error handling makes the class less robust against incorrect usage.
        // This could lead to an inconsistent or undesirable state in a larger system.
        secretValue = value;
    }
};

int main() {
    DataStore ds;

    std::cout << "Initial secret value: " << ds.getSecretValue() << '\n'; // Should be 0

    ds.setSecretValue(50);
    std::cout << "Secret value after setting 50: " << ds.getSecretValue() << '\n';

    // Demonstrate Robustness Issue: Setting an "invalid" value (e.g., negative)
    // without any validation or error handling in setSecretValue.
    // The program will function, but the DataStore object might be in an unexpected state
    // if a non-negative value was implicitly expected.
    ds.setSecretValue(-10);
    std::cout << "Secret value after setting -10 (robustness issue): " << ds.getSecretValue() << '\n';

    // Demonstrate that secretValue cannot be accessed directly from outside the class.
    // The following line would cause a compile-time error.
    // ds.secretValue = 200; // Error: 'int DataStore::secretValue' is private
    std::cout << "Attempting direct access to secretValue (this line would cause a compile error): Error: 'int DataStore::secretValue' is private" << '\n';

    return 0;
}