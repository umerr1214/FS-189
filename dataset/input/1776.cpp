#include <iostream>
// #include <string> // SEMANTIC ERROR: The <string> header is missing, relying on transitive inclusion

class Student {
public:
    int studentID;
    std::string name; // std::string is used without explicit <string> header
    std::string major;

    // Default constructor
    Student() : studentID(0), name("N/A"), major("Undecided") {}

    // Parameterized constructor
    Student(int id, std::string n, std::string m)
        : studentID(id), name(n), major(m) {}

    void display() const {
        std::cout << "ID: " << studentID << ", Name: " << name << ", Major: " << major << std::endl;
    }
};

int main() {
    Student s1;
    std::cout << "Default Student: ";
    s1.display();

    Student s2(101, "Alice", "CS");
    std::cout << "Parameterized Student: ";
    s2.display();

    Student s3(102, "Bob", "Physics");
    std::cout << "Another Parameterized Student: ";
    s3.display();

    return 0;
}