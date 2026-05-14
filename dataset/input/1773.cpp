#include <iostream>
#include <string>

class Student {
private:
    int studentID;
    std::string name;
    std::string major;

public:
    // Correct Version:
    // Uses const references for string parameters to avoid unnecessary copies (efficiency).
    // Parameter names are clear and descriptive (readability).
    void setDetails(int id, const std::string& n, const std::string& m) {
        studentID = id;
        name = n;
        major = m;
    }

    // Correct Version:
    // Uses `'\n'` instead of `std::endl` for efficiency, avoiding unnecessary buffer flushes.
    void displayDetails() {
        std::cout << "Student ID: " << studentID
                  << ", Name: " << name
                  << ", Major: " << major << '\n';
    }
};

int main() {
    Student student1;
    student1.setDetails(1001, "Alice Johnson", "Computer Science");
    student1.displayDetails();

    Student student2;
    student2.setDetails(2002, "Bob Williams", "Electrical Engineering");
    student2.displayDetails();

    Student student3;
    student3.setDetails(3003, "Charlie Brown", "Physics");
    student3.displayDetails();

    return 0;
}