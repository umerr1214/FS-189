#include <iostream> // Required for input/output operations (std::cout).

// The DataStore class encapsulates an integer secretValue.
class DataStore {
private:
    int secretValue; // Private member to store the integer value, enforcing encapsulation.

public:
    // Constructor to initialize secretValue, ensuring a valid initial state.
    // Initializes secretValue to 0 by default.
    DataStore() : secretValue(0) {}

    // Public method to access (get) the secretValue.
    // Marked 'const' because this method does not modify the object's state,
    // which is good practice for accessor methods.
    int getSecretValue() const {
        return secretValue;
    }

    // Public method to modify (set) the secretValue.
    // Takes an integer 'value' to update the private member.
    void setSecretValue(int value) {
        secretValue = value;
    }
};

int main() {
    // Create an instance of the DataStore class.
    DataStore ds;

    // Demonstrate accessing the initial secret value using the public getter.
    std::cout << "Initial secret value: " << ds.getSecretValue() << '\n';

    // Modify the secret value using the public setter.
    ds.setSecretValue(42);
    // Verify the updated secret value using the public getter.
    std::cout << "Secret value after setting to 42: " << ds.getSecretValue() << '\n';

    // Demonstrate encapsulation enforcement:
    // Attempting to directly access or modify 'secretValue' from outside the class
    // will result in a compile-time error because it is a private member.
    // ds.secretValue = 100; // This line would cause a compile error.

    std::cout << "Attempting direct access to secretValue (this line would cause a compile error): Error: 'int DataStore::secretValue' is private" << '\n';

    return 0; // Indicate successful program execution.
}