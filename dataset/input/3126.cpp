#include <iostream>
#include <string>

class Student {
public:
    std::string name;
    int id;
    double grade;

    // Default constructor: Correctly initializes members to default values
    Student() : name(""), id(0), grade(0.0) {}

    // Parameterized constructor: Semantic error due to type mismatch in parameters.
    // It accepts 'id' as a double and 'grade' as an int, but the member variables
    // are 'int id' and 'double grade'. This leads to implicit conversions and
    // potential data loss (truncation of 'id_val' to 'this->id') or misrepresentation
    // (grade_val as an int for a double member).
    Student(std::string n, double id_val, int grade_val)
        : name(n), id(id_val), grade(grade_val) {
        // 'id_val' (double) is implicitly converted to 'id' (int), truncating any decimal part.
        // 'grade_val' (int) is implicitly converted to 'grade' (double), potentially losing precision
        // if the intent was to store a fractional grade directly.
    }

    void display() const {
        std::cout << "Name: " << name << ", ID: " << id << ", Grade: " << grade << std::endl;
    }
};

int main() {
    // Test default constructor
    Student s1;
    s1.display(); // Expected: Name: , ID: 0, Grade: 0.0

    // Test parameterized constructor with semantic type mismatch
    // Input: name="Alice", id_val=101.5 (double), grade_val=95 (int)
    Student s2("Alice", 101.5, 95);
    s2.display(); // Expected: Name: Alice, ID: 101, Grade: 95.0 (id truncated, grade converted)

    // Input: name="Bob", id_val=202.9 (double), grade_val=88 (int)
    Student s3("Bob", 202.9, 88);
    s3.display(); // Expected: Name: Bob, ID: 202, Grade: 88.0 (id truncated, grade converted)

    return 0;
}