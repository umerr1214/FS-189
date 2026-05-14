#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    int grade;

public:
    Student(std::string n, int g) : name(n) {
        setGrade(g); // Use setGrade for initial validation
    }

    void setName(std::string n) {
        name = n;
    }

    void setGrade(int newGrade) {
        if (newGrade >= 0 && newGrade <= 100) {
            grade = newGrade;
        } else {
            // SYNTAX ERROR: Missing std:: before cout
            cout << "Error: Grade must be between 0 and 100. Keeping old value.\n";
        }
    }

    void displayStudent() const {
        std::cout << "Student: " << name << ", Grade: " << grade << "\n";
    }

    int getGrade() const {
        return grade;
    }
};

int main() {
    std::string name;
    int initialGrade, invalidGrade, validGrade;

    std::cin >> name >> initialGrade >> invalidGrade >> validGrade;

    Student s(name, initialGrade);
    s.displayStudent();

    s.setGrade(invalidGrade);
    s.displayStudent();

    s.setGrade(validGrade);
    s.displayStudent();

    return 0;
}