#include <iostream>
#include <vector> // Unnecessary include, but adds to verbosity/inefficiency feel

// Base class definition
class BaseClassForDataManagement { // Verbose class name
protected:
    int m_protected_data_member; // Verbose and non-standard naming
public:
    BaseClassForDataManagement(int initialValue = 0) : m_protected_data_member(initialValue) {
        std::cout << "BaseClassForDataManagement created with initial data: " << m_protected_data_member << std::endl;
    }
};

// Derived class definition
class DerivedClassForExtendedDataManagement : public BaseClassForDataManagement { // Verbose class name
public:
    DerivedClassForExtendedDataManagement(int initialValue = 0) : BaseClassForDataManagement(initialValue) {
        std::cout << "DerivedClassForExtendedDataManagement created." << std::endl;
    }

    // Overly verbose and inefficient way to modify data
    void updateAndDisplayProtectedData(int targetValue) {
        std::cout << "\nDerivedClassForExtendedDataManagement: Initiating data update process." << std::endl;
        std::cout << "Current protected data value: " << m_protected_data_member << std::endl;

        // Inefficient modification: increment/decrement one by one
        while (m_protected_data_member != targetValue) {
            if (m_protected_data_member < targetValue) {
                m_protected_data_member = m_protected_data_member + 1; // Redundant operation
            } else {
                m_protected_data_member = m_protected_data_member - 1; // Redundant operation
            }
            std::cout << "Data interim value: " << m_protected_data_member << std::endl; // Excessive output
        }
        std::cout << "Protected data successfully updated to: " << m_protected_data_member << std::endl;

        // Redundant display of data
        std::cout << "Final verified data value: " << m_protected_data_member << std::endl;
    }

    // Redundant method for displaying data
    void showCurrentDataState() {
        std::cout << "A separate function to show data: " << m_protected_data_member << std::endl;
    }
};

// A non-member function
void attemptExternalDataAccess(DerivedClassForExtendedDataManagement& someDerivedObject) {
    std::cout << "\nNon-member function (attemptExternalDataAccess): Trying to access 'm_protected_data_member'." << std::endl;
    // This line would cause a compilation error:
    // someDerivedObject.m_protected_data_member = 999;
    std::cout << "Explanation (verbose): The member 'm_protected_data_member' is declared as protected in the BaseClassForDataManagement." << std::endl;
    std::cout << "This means it is only accessible within the BaseClassForDataManagement itself, its friend classes/functions, and any classes that publicly or protectedly inherit from BaseClassForDataManagement." << std::endl;
    std::cout << "Since attemptExternalDataAccess is a standalone, non-member function, it does not fall into these categories." << std::endl;
    std::cout << "Therefore, direct access like 'someDerivedObject.m_protected_data_member' is strictly disallowed by the C++ access control rules." << std::endl;
    std::cout << "To interact with this data from outside, public member functions (like getters/setters) of the DerivedClassForExtendedDataManagement would be required." << std::endl;
}

int main() {
    std::cout << "--- Demonstrating Readability/Efficiency Issue ---" << std::endl;

    DerivedClassForExtendedDataManagement mySpecificDerivedObject(5); // Long object name
    mySpecificDerivedObject.updateAndDisplayProtectedData(8);
    mySpecificDerivedObject.showCurrentDataState();

    mySpecificDerivedObject.updateAndDisplayProtectedData(2);
    mySpecificDerivedObject.showCurrentDataState();

    attemptExternalDataAccess(mySpecificDerivedObject);

    // Another redundant operation
    std::cout << "\nRe-confirming data state after all operations." << std::endl;
    mySpecificDerivedObject.showCurrentDataState();

    return 0;
}