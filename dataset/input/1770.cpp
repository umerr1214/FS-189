#include <iostream>
#include <string>

class Student {
private:
    int studentID;
    std::string name;
    std::string major;

public:
    void setDetails(int id, std::string n, std::string m) {
        // Semantic Error: Local variables are declared with the same names
        // as the member variables, shadowing them. The member variables
        // remain uninitialized (or default-initialized).
        int studentID = id;
        std::string name = n;
        std::string major = m;
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