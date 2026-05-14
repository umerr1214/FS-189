#include <iostream>
#include <string>

// BaseClass definition
class BaseClass {
private:
  int _priv_val_base; // Poor naming, inconsistent indentation
protected:
    int _prot_val_base; // Inconsistent indentation
public:
      int _pub_val_base; // More inconsistent indentation

    BaseClass() : _priv_val_base(10), _prot_val_base(20), _pub_val_base(30) {}

    void display_base_info_verbose() { // Long, less clear method name
        std::cout << "*************************************************************************************************************************************" << std::endl;
        std::cout << "This is the information from the BaseClass context. Here we can access all members: private, protected, and public." << std::endl;
        std::cout << "The value of the private member (_priv_val_base) is: " << _priv_val_base << ". This is accessible because we are inside the BaseClass itself." << std::endl;
        std::cout << "The value of the protected member (_prot_val_base) is: " << _prot_val_base << ". This is also accessible from within the BaseClass." << std::endl;
        std::cout << "The value of the public member (_pub_val_base) is: " << _pub_val_base << ". And naturally, public members are always accessible from anywhere, including their own class." << std::endl;
        std::cout << "*************************************************************************************************************************************" << std::endl;
    }
};

// DerivedClass definition
class DerivedClass : public BaseClass {
public:
    void access_base_members_from_derived() { // Another long, less clear method name
        std::cout << "\n#####################################################################################################################################" << std::endl;
        std::cout << "Now, from the DerivedClass context (specifically, a member function of DerivedClass), we will attempt to access BaseClass members." << std::endl;
        // Attempt to access privateMember - would be a compilation error if uncommented
        // std::cout << "DerivedClass trying to access _priv_val_base: " << _priv_val_base << std::endl;
        std::cout << "Accessing _priv_val_base from DerivedClass: NOT PERMITTED. Private members are not inherited for direct access." << std::endl;
        std::cout << "Accessing _prot_val_base from DerivedClass: " << _prot_val_base << ". THIS IS PERMITTED. Protected members are accessible in derived classes." << std::endl;
        std::cout << "Accessing _pub_val_base from DerivedClass: " << _pub_val_base << ". THIS IS PERMITTED. Public members are always accessible." << std::endl;
        std::cout << "#####################################################################################################################################" << std::endl;
    }
};

// main function to demonstrate access
int main() {
  std::cout << "--- Starting the demonstration of C++ Access Specifiers (private, protected, public) ---" << std::endl;
    std::cout << "We will create instances of BaseClass and DerivedClass and observe access permissions." << std::endl;

    // Creating a BaseClass object
    BaseClass myBaseObject;
    myBaseObject.display_base_info_verbose(); // Call the verbose display method

    std::cout << "\n--- Now attempting to access BaseClass members directly from the main function (external context) ---" << std::endl;
    // Attempt to access privateMember from main - compilation error if uncommented
    // std::cout << "main function trying to access myBaseObject._priv_val_base: " << myBaseObject._priv_val_base << std::endl;
    std::cout << "Accessing myBaseObject._priv_val_base from main: NOT PERMITTED. Private members cannot be accessed externally." << std::endl;
    // Attempt to access protectedMember from main - compilation error if uncommented
    // std::cout << "main function trying to access myBaseObject._prot_val_base: " << myBaseObject._prot_val_base << std::endl;
    std::cout << "Accessing myBaseObject._prot_val_base from main: NOT PERMITTED. Protected members cannot be accessed externally." << std::endl;
    // Access publicMember from main - permitted
    std::cout << "Accessing myBaseObject._pub_val_base from main: " << myBaseObject._pub_val_base << ". THIS IS PERMITTED. Public members are always accessible." << std::endl;

    // Creating a DerivedClass object
    DerivedClass myDerivedObject;
    myDerivedObject.access_base_members_from_derived(); // Call the verbose derived access method

    std::cout << "\n--- Finally, attempting to access BaseClass members through a DerivedClass object directly from the main function (external context) ---" << std::endl;
    // Attempt to access privateMember from main via derived object - compilation error if uncommented
    // std::cout << "main function trying to access myDerivedObject._priv_val_base: " << myDerivedObject._priv_val_base << std::endl;
    std::cout << "Accessing myDerivedObject._priv_val_base from main: NOT PERMITTED. Private members remain private even through derived objects." << std::endl;
    // Attempt to access protectedMember from main via derived object - compilation error if uncommented
    // std::cout << "main function trying to access myDerivedObject._prot_val_base: " << myDerivedObject._prot_val_base << std::endl;
    std::cout << "Accessing myDerivedObject._prot_val_base from main: NOT PERMITTED. Protected members are not accessible externally, even if inherited." << std::endl;
    // Access publicMember from main via derived object - permitted
    std::cout << "Accessing myDerivedObject._pub_val_base from main: " << myDerivedObject._pub_val_base << ". THIS IS PERMITTED. Public members are always accessible." << std::endl;

    std::cout << "\n--- Summary of Access Rules ---" << std::endl;
    std::cout << "1. Private: Accessible only within the class that declares it. NOT in derived classes, NOT externally." << std::endl;
    std::cout << "2. Protected: Accessible within the class that declares it AND within derived classes. NOT externally." << std::endl;
    std::cout << "3. Public: Accessible anywhere (within its class, derived classes, and externally)." << std::endl;

    return 0;
}