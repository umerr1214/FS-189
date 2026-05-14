#include <iostream>
#include <string>
#include <stdexcept> // For robust error handling with exceptions

// Correct Version: Demonstrates proper class design, member access rules,
// efficient practices, and basic robustness.
class Person {
public:
    std::string name; // Public member: Directly accessible from anywhere
protected:
    int age; // Protected member: Accessible within the class and derived classes
private:
    int id; // Private member: Accessible only within the class

public:
    // Constructor: Uses initializer list for efficiency and passes strings by const reference
    Person(const std::string& n, int a, int i) : name(n), age(a), id(i) {
        // Basic validation for age, demonstrating a robust approach
        if (age < 0 || age > 120) {
            throw std::out_of_range("Person age must be between 0 and 120.");
        }
    }

    // Public method to safely access the private 'id'
    int getId() const { return id; }

    // Public method to safely access the protected 'age'
    int getAge() const { return age; }

    // Public method to safely modify the protected 'age' with validation
    void setAge(int newAge) {
        if (newAge < 0 || newAge > 120) {
            throw std::out_of_range("New age must be between 0 and 120.");
        }
        age = newAge;
    }
};

class Student : public Person {
public:
    std::string studentMajor; // Public member specific to Student

    // Constructor: Calls base class constructor and initializes its own members
    // Passes strings by const reference for efficiency
    Student(const std::string& n, int a, int i, const std::string& major)
        : Person(n, a, i), studentMajor(major) {}

    // Method to demonstrate member accessibility from within Student class
    void demonstrateStudentAccess() {
        std::cout << "--- Inside Student method (demonstrateStudentAccess) ---\n";
        std::cout << "Accessible: Public Person::name = " << name << '\n'; // Direct access to public inherited member
        std::cout << "Accessible: Protected Person::age = " << age << '\n'; // Direct access to protected inherited member
        // std::cout << "Attempting to access private Person::id: (Compile Error)" << std::endl; // Private is not accessible
        std::cout << "Accessible: Student::studentMajor = " << studentMajor << '\n'; // Direct access to Student's public member
        std::cout << "Accessible: Person::getId() (public method) = " << getId() << '\n'; // Access via public method
        std::cout << "Accessible: Person::getAge() (public method) = " << getAge() << '\n'; // Access via public method

        // Example of modifying protected member from Student (using setter for validation)
        // setAge(23);
        // std::cout << "Modified protected Person::age to: " << age << '\n';
    }
};

// Function to demonstrate member accessibility from outside Student objects
void demonstrateOutsideAccess(const Student& s) {
    std::cout << "\n--- Outside Student object (demonstrateOutsideAccess function) ---\n";
    std::cout << "Accessible: Public Student::name (inherited from Person) = " << s.name << '\n'; // Direct access to public inherited member
    // std::cout << "Attempting to access protected Person::age: (Compile Error)" << std::endl; // Protected is not accessible from outside
    // std::cout << "Attempting to access private Person::id: (Compile Error)" << std::endl; // Private is not accessible from outside
    std::cout << "Accessible: Public Student::studentMajor = " << s.studentMajor << '\n'; // Direct access to Student's public member
    std::cout << "Accessible: Person::getId() (public method) = " << s.getId() << '\n'; // Access via public method
    std::cout << "Accessible: Person::getAge() (public method) = " << s.getAge() << '\n'; // Access via public method
}

int main() {
    try {
        Student alice("Alice Smith", 20, 1001, "Computer Science");
        alice.demonstrateStudentAccess();
        demonstrateOutsideAccess(alice);

        // Example demonstrating robustness with invalid age
        // Uncomment the following lines to test the exception handling:
        // std::cout << "\nAttempting to create a student with invalid age...\n";
        // Student invalidStudent("Bob", -5, 1002, "Mathematics");
        // invalidStudent.demonstrateStudentAccess();

    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << '\n';
        return 1; // Indicate an error occurred
    } catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred: " << e.what() << '\n';
        return 1;
    }

    return 0;
}