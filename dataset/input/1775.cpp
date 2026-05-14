#include <iostream>
#include <string>

class Student {
public:
    int studentID;
    std::string name;
    std::string major;

    // Default constructor
    Student() : studentID(0), name("N/A"), major("Undecided") {}

    // Parameterized constructor with a logical error: name and major are swapped
    Student(int id, std::string n, std::string m)
        : studentID(id), name(m), major(n) {} // LOGICAL ERROR: 'name' is initialized with 'm' (major), 'major' with 'n' (name)

    void display() const {
        std::cout << "ID: " << studentID << ", Name: " << name << ", Major: " << major << std::endl;
    }
};

int main() {
    Student s1;
    std::cout << "Default Student: ";
    s1.display(); // Expected: ID: 0, Name: N/A, Major: Undecided

    Student s2(101, "Alice", "CS");
    std::cout << "Parameterized Student (Alice, CS): ";
    s2.display(); // Expected: ID: 101, Name: Alice, Major: CS -> Actual: ID: 101, Name: CS, Major: Alice

    Student s3(102, "Bob", "Physics");
    std::cout << "Another Parameterized Student (Bob, Physics): ";
    s3.display(); // Expected: ID: 102, Name: Bob, Major: Physics -> Actual: ID: 102, Name: Physics, Major: Bob

    return 0;
}