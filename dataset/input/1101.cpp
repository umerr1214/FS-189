#include <iostream>
#include <string>

// Correct Version:
// - Encapsulation maintained with private attributes and public getters.
// - Efficient parameter passing using const references for strings in constructors.
// - Clear and concise naming conventions.
// - Correct constructor chaining.
// - Uses '\n' for efficient output.

class Person {
private:
    std::string name;
    int age;

public:
    // Parameterized constructor for Person, using const std::string& for efficiency
    Person(const std::string& pName, int pAge) : name(pName), age(pAge) {}

    // Getter methods for attributes
    std::string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    // Method to display Person's information
    void displayPersonInfo() const {
        std::cout << "Name: " << name << ", Age: " << age << '\n';
    }
};

class Student : public Person {
private:
    std::string studentId;

public:
    // Student constructor chaining to Person's constructor, using const std::string& for efficiency
    Student(const std::string& pName, int pAge, const std::string& sId)
        : Person(pName, pAge), studentId(sId) {}

    // Getter method for studentId
    std::string getStudentId() const {
        return studentId;
    }

    // Method to display Student's full information
    void displayStudentInfo() const {
        displayPersonInfo(); // Call base class display
        std::cout << "Student ID: " << studentId << '\n';
    }
};

int main() {
    // Test Case 1
    Student student1("Alice Wonderland", 21, "S2023-001");
    std::cout << "--- Student 1 Details ---\n";
    student1.displayStudentInfo();
    std::cout << '\n'; // Use '\n' for new line

    // Test Case 2
    Student student2("Bob The Builder", 19, "S2023-002");
    std::cout << "--- Student 2 Details ---\n";
    student2.displayStudentInfo();
    std::cout << '\n';

    // Test Case 3
    Student student3("Charlie Chaplin", 25, "S2023-003");
    std::cout << "--- Student 3 Details ---\n";
    student3.displayStudentInfo();

    return 0;
}