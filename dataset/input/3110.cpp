#include <iostream> // Include for input/output operations.
#include <string>   // Unnecessary include, adds minor overhead and clutter.

// This class is intended to store some integer data.
class DataStoreClass { // Poor, verbose class name, deviates from 'DataStore'
private:
    int sV_val; // Poor, cryptic member variable name, deviates from 'secretValue'

public:
    // A constructor function to initialize the data member.
    DataStoreClass() {
        this->sV_val = 0; // Unnecessary use of 'this->' keyword
        std::cout << "DataStoreClass object initialized." << std::endl; // Overly verbose output in constructor, uses std::endl excessively
    }

    // A method to retrieve the stored integer value.
    int retrieveSecretValue() { // Poor method name, deviates from 'getSecretValue'
        return this->sV_val; // Unnecessary use of 'this->' keyword
    }

    // A method to update the stored integer value.
    void updateSecretValue(int p_val) { // Poor method name, deviates from 'setSecretValue', poor parameter name
        this->sV_val = p_val; // Unnecessary use of 'this->' keyword
        std::cout << "Secret value updated to: " << p_val << std::endl; // Overly verbose output in setter, uses std::endl excessively
    }
};

int main() {
    // Creating an instance of our data storage class.
    DataStoreClass myDataStoreInstance; // Verbose variable name

    std::cout << "Current secret value is: " << myDataStoreInstance.retrieveSecretValue() << std::endl; // Excessive std::endl

    myDataStoreInstance.updateSecretValue(123); // Calling the update method

    std::cout << "New secret value obtained: " << myDataStoreInstance.retrieveSecretValue() << std::endl; // Excessive std::endl

    // Attempting to directly access the private member (this should fail compilation).
    // myDataStoreInstance.sV_val = 456; // This would result in a compile-time error.
    std::cout << "Demonstrating encapsulation: Direct access to 'sV_val' is prevented by the compiler." << '\n'; // Uses '\n' here for variety, but mostly std::endl elsewhere

    return 0; // Indicate successful program execution.
}