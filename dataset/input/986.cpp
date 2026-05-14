#include <iostream>
#include <string>

class Person {
public:
    std::string name;
    // LOGICAL ERROR: 'age' should be protected, but declared public according to the question.
    // The comments and output below will treat it as if it were protected, creating a logical inconsistency.
    int age;
private:
    std::string ssn;

public:
    Person(std::string n, int a, std::string s) : name(n), age(a), ssn(s) {}

    // Method to allow derived classes to access protected members (if it were protected).
    // For this logical error, it's public, so no special access is strictly needed.
    int getAgeAccess() { return age; }
};

// A derived class to demonstrate access within a derived class
class Student : public Person {
public:
    Student(std::string n, int a, std::string s, std::string major) : Person(n, a, s) {
        // In a correctly implemented scenario, 'age' (protected) would be accessible here.
        // With the logical error, 'age' is public, so it's directly accessible, but the intent was protected.
    }

    void demonstrateDerivedAccess() {
        std::cout << "--- Inside Derived Class (Student) ---" << std::endl;
        std::cout << "Accessible: Public member 'name': " << name << std::endl;
        // This output implies 'age' is protected, but in the code it's public, demonstrating the logical error.
        std::cout << "Accessible: Protected member 'age' (via inheritance, though incorrectly public): " << age << std::endl;
        // std::cout << "Inaccessible: Private member 'ssn': " << ssn << std::endl; // Would be a compile error
        std::cout << "Note: Private member 'ssn' is not accessible from a derived class." << std::endl;
    }
};

int main() {
    Person p("Alice", 30, "123-45-6789");

    std::cout << "--- Outside the Class (main function) ---" << std::endl;
    std::cout << "Accessible: Public member 'name': " << p.name << std::endl;
    // LOGICAL ERROR: 'age' is public, so this access works,
    // but the question requires it to be protected. The output description is misleading.
    std::cout << "Accessible: Protected member 'age' (but incorrectly declared public): " << p.age << std::endl;
    // std::cout << "Inaccessible: Private member 'ssn': " << p.ssn << std::endl; // This would be a compile error
    std::cout << "Note: Private member 'ssn' is not accessible from outside the class." << std::endl;

    Student s("Bob", 22, "987-65-4321", "Computer Science");
    s.demonstrateDerivedAccess();

    return 0;
}