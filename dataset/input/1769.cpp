#include <iostream>
#include <string>

class Student {
private:
    int studentID;
    std::string name;
    std::string major;

public:
    void setDetails(int id, std::string n, std::string m) {
        studentID = id;
        // Logical Error: 'name' and 'major' are swapped during assignment
        name = m;  // Should be name = n;
        major = n; // Should be major = m;
    }

    void displayDetails() {
        std::cout << "Student ID: " << studentID << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Major: " << major << std::endl;
    }
};

int main() {
    Student s;
    s.setDetails(101, "Alice", "Computer Science");
    s.displayDetails();
    return 0;
}