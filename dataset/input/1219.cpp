#include <iostream>
#include <string>
#include <vector> // Included for potential future use, adding a bit of clutter

// Robustness Issue: Memory leak due to missing destructor for dynamically allocated 'id'.
// Also, lack of validation for 'age' allows setting invalid negative values from Student,
// leading to potential inconsistent object state.
class Person {
public:
    std::string name; // Public member
protected:
    int age; // Protected member
private:
    int* id; // Private member, dynamically allocated without proper memory management

public:
    // Constructor: Allocates memory for id but no corresponding destructor
    Person(std::string n, int a, int i) : name(n), age(a) {
        id = new int(i); // Memory allocated
        // No validation for 'age' here, allowing negative values
    }

    // MISSING: Destructor (~Person()) to delete 'id'. This will cause a memory leak.
    // MISSING: Copy constructor and copy assignment operator (Rule of Three/Five violation)
    // If objects are copied, it leads to shallow copies and potential double-free issues.

    // Public method to access private id
    int getPersonId() const {
        if (id == nullptr) { // Basic check, but doesn't prevent leak if not deleted
            return -1; // Indicate error
        }
        return *id;
    }

    // Public method to access protected age
    int getPersonAge() const { return age; }

    // A method to simulate a potential issue: direct modification without validation
    void setAgeDirectly(int newAge) {
        // No validation, allows any age, potentially leading to inconsistent state
        age = newAge;
    }
};

class Student : public Person {
public:
    std::string studentMajor; // Public member specific to Student

    // Constructor: Calls base class constructor
    Student(std::string n, int a, int i, std::string major)
        : Person(n, a, i), studentMajor(major) {}

    // Method to demonstrate member accessibility from within Student class
    void demonstrateStudentAccess() {
        std::cout << "--- Inside Student method (demonstrateStudentAccess) ---" << std::endl;
        std::cout << "Accessing public Person::name: " << name << std::endl; // Direct access
        std::cout << "Accessing protected Person::age: " << age << std::endl; // Direct access

        // Robustness issue: Student can directly modify protected 'age' without any validation
        age = -10; // Setting an invalid negative age
        std::cout << "Modified protected Person::age to (invalid): " << age << std::endl;

        // std::cout << "Attempting to access private Person::id: (Compile Error)" << std::endl;
        std::cout << "Accessing Student::studentMajor: " << studentMajor << std::endl; // Direct access
        std::cout << "Accessing Person::getPersonId() (public method): " << getPersonId() << std::endl;
        std::cout << "Accessing Person::getPersonAge() (public method): " << getPersonAge() << std::endl;
    }
};

// Function to demonstrate member accessibility from outside Student objects
void demonstrateOutsideAccess(const Student& s) {
    std::cout << "\n--- Outside Student object (demonstrateOutsideAccess function) ---" << std::endl;
    std::cout << "Accessing public Student::name (inherited from Person): " << s.name << std::endl; // Direct access
    // std::cout << "Attempting to access protected Person::age: (Compile Error)" << std::endl;
    // std::cout << "Attempting to access private Person::id: (Compile Error)" << std::endl;
    std::cout << "Accessing public Student::studentMajor: " << s.studentMajor << std::endl; // Direct access
    std::cout << "Accessing Person::getPersonId() (public method): " << s.getPersonId() << std::endl;
    std::cout << "Accessing Person::getPersonAge() (public method): " << s.getPersonAge() << std::endl;
}

int main() {
    Student alice("Alice Smith", 20, 1001, "Computer Science");
    alice.demonstrateStudentAccess(); // 'age' is set to -10 here

    demonstrateOutsideAccess(alice);

    // Further demonstrate the memory leak:
    // When 'alice' goes out of scope, the memory for 'id' allocated in Person's constructor is NOT freed.
    // This is a memory leak.
    // If a copy was made (e.g., `Student bob = alice;`), and Person had a destructor that `delete id;` but no copy ctor,
    // it would lead to a double-free when both `alice` and `bob` are destroyed.

    // A small vector for no real reason, just to add some minor "clutter" (not directly an error, but can reduce readability)
    std::vector<int> dummy_data(10, 0);

    return 0;
}