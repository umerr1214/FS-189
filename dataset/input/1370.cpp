#include <iostream>
#include <string>
#include <vector> // This include is unnecessary for the functionality, adding clutter.

// Base class Person
class Person {
public:
    std::string publicMemberName; // Renamed to emphasize public, but adds verbosity
protected:
    int protectedMemberAge;       // Renamed to emphasize protected, but adds verbosity
private:
    std::string privateMemberSocialSecurityNumber; // Renamed to emphasize private, but adds verbosity

public:
    // Constructor with multiple empty lines, reducing readability
    Person(std::string n, int a, std::string ssn) 
        : publicMemberName(n), protectedMemberAge(a), privateMemberSocialSecurityNumber(ssn) 
    {


    }

    // A public method to expose public name
    void printMyPublicName() const {
        std::cout << "  Person's Publicly Accessible Name is: " << publicMemberName << std::endl;
    }

    // A public method to indirectly expose protected age (redundant if derived class can access directly)
    int retrieveMyProtectedAge() const {
        return protectedMemberAge;
    }
};

// Derived class Student
class Student : public Person {
public:
    std::string studentIdentificationCode; // Renamed for more verbosity

    // Constructor calls base class constructor, with extra empty lines
    Student(std::string n, int a, std::string ssn, std::string id)
        : Person(n, a, ssn), studentIdentificationCode(id) 
    {


    }

    // Highly verbose method to demonstrate access, with redundant explanations
    void showAllStudentAndInheritedDetails() const {
        std::cout << "\n==================================================================" << std::endl;
        std::cout << "  VERBOSE DEMONSTRATION OF ACCESS SPECIFIERS FOR STUDENT OBJECT   " << std::endl;
        std::cout << "==================================================================" << std::endl;
        
        std::cout << "\n  [SECTION 1: STUDENT'S OWN PUBLIC MEMBER]" << std::endl;
        std::cout << "  - Student Identification Code (public, direct access): " << studentIdentificationCode << std::endl;
        std::cout << "  - This is a member declared directly within the Student class, and it is public." << std::endl;
        
        std::cout << "\n  [SECTION 2: INHERITED PUBLIC MEMBER ACCESS]" << std::endl;
        std::cout << "  - Member 'publicMemberName' (originally 'name') is PUBLIC in Person." << std::endl;
        std::cout << "  - Therefore, it is DIRECTLY ACCESSIBLE from Student (derived class)." << std::endl;
        std::cout << "  - Value: " << publicMemberName << std::endl;
        std::cout << "  - It would also be accessible from any external code." << std::endl;

        std::cout << "\n  [SECTION 3: INHERITED PROTECTED MEMBER ACCESS]" << std::endl;
        std::cout << "  - Member 'protectedMemberAge' (originally 'age') is PROTECTED in Person." << std::endl;
        std::cout << "  - Therefore, it is DIRECTLY ACCESSIBLE from Student (derived class)." << std::endl;
        std::cout << "  - Value (direct access): " << protectedMemberAge << std::endl;
        std::cout << "  - Value (via redundant internal method 'retrieveMyProtectedAge'): " << retrieveMyProtectedAge() << std::endl; // Redundant call
        std::cout << "  - Protected members are specifically designed for access within derived classes." << std::endl;
        std::cout << "  - They are NOT accessible from external code (like main function)." << std::endl;

        std::cout << "\n  [SECTION 4: INHERITED PRIVATE MEMBER ACCESS ATTEMPT]" << std::endl;
        std::cout << "  - Member 'privateMemberSocialSecurityNumber' (originally 'socialSecurityNumber') is PRIVATE in Person." << std::endl;
        std::cout << "  - It is NOT ACCESSIBLE from Student (derived class)." << std::endl;
        std::cout << "  - Attempting to access it directly (e.g., 'privateMemberSocialSecurityNumber') would cause a COMPILE-TIME ERROR." << std::endl;
        std::cout << "  - This enforces strong encapsulation, limiting access to the defining class only." << std::endl;
        // The following line would cause a compile error if uncommented:
        // std::cout << "  - Private SSN (inaccessible): " << privateMemberSocialSecurityNumber << std::endl;
        
        std::cout << "\n==================================================================" << std::endl;
    }
};

int main() {
    Student student_verbose_example("Eleanor Rigby", 25, "555-44-3333", "STUDENT-ID-ALPHA-007");
    student_verbose_example.showAllStudentAndInheritedDetails();

    std::cout << "\n--- External (main function) access examples ---" << std::endl;
    Person p("Gandalf Grey", 1000, "999-88-7777");
    p.printMyPublicName();
    // Accessing public member directly
    std::cout << "  Direct access to Person's publicMemberName: " << p.publicMemberName << std::endl;
    // Attempting to access protected or private members directly from main would fail.
    // std::cout << p.protectedMemberAge << std::endl; // Compile error
    // std::cout << p.privateMemberSocialSecurityNumber << std::endl; // Compile error

    return 0;
}