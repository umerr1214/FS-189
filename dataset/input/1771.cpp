#include <iostream>
#include <string>

class Student {
private:
    int studentID;
    std::string name;
    std::string major;

public:
    void setDetails(int id, std::string n, std::string m) {
        // Robustness Issue: No input validation.
        // This method allows invalid data such as negative student IDs or
        // empty names/majors to be stored without any checks.
        // This can lead to an inconsistent or misleading internal state.
        studentID = id;
        name = n;
        major = m;
    }

    void displayDetails() {
        std::cout << "Student ID: " << studentID
                  << ", Name: " << name
                  << ", Major: " << major << std::endl;
    }
};

int main() {
    Student student1;
    student1.setDetails(1001, "Alice Johnson", "Computer Science");
    student1.displayDetails(); // Valid input

    std::cout << "--- Testing Robustness Issue (Invalid Inputs) ---" << std::endl;

    Student student2;
    // Calling setDetails with a negative ID and empty strings.
    // A robust system would validate these inputs and potentially reject them or
    // provide a default/error state, rather than storing them directly.
    student2.setDetails(-500, "", "");
    student2.displayDetails(); // Displays the invalid data as is

    Student student3;
    // Another case with a zero ID and empty major, which might be logically invalid.
    student3.setDetails(0, "Invalid Student Name", "");
    student3.displayDetails(); // Displays the potentially invalid data

    return 0;
}