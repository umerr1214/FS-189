#include <iostream>
#include <string>

class Student {
private:
    int studentID;
    std::string name;
    std::string major;

public:
    // Readability/Efficiency Issue:
    // 1. String parameters `n_val` and `m_val` are passed by value,
    //    causing unnecessary copies of potentially large strings.
    // 2. Parameter names (`i`, `n_val`, `m_val`) are less descriptive, impacting readability.
    void setDetails(int i, std::string n_val, std::string m_val) {
        studentID = i;
        name = n_val;
        major = m_val;
    }

    // Efficiency Issue:
    // `std::endl` is used, which not only inserts a newline character but also flushes
    // the output buffer. This can be less efficient than using `'\n'` if frequent flushing
    // is not required, especially in performance-critical applications.
    void displayDetails() {
        std::cout << "Student ID: " << studentID
                  << ", Name: " << name
                  << ", Major: " << major << std::endl;
    }
};

int main() {
    Student s1;
    s1.setDetails(101, "Alice Smith", "Computer Science");
    s1.displayDetails();

    Student s2;
    s2.setDetails(202, "Bob Junior", "Mechanical Engineering");
    s2.displayDetails();

    return 0;
}