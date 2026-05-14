#include <iostream>
#include <string>

class Person {
public:
    std::string name;
protected:
    std::string address;
private:
    std::string phone;

public:
    Person(std::string n, std::string addr, std::string ph) : name(n), address(addr), phone(ph) {}

    void displayPublicInfo() const {
        std::cout << "Person Name (public): " << name << std::endl;
    }
} // SYNTAX ERROR: Missing semicolon after class definition

class Student : public Person {
public:
    Student(std::string n, std::string addr, std::string ph) : Person(n, addr, ph) {}

    void displayStudentInfo() {
        std::cout << "--- Student Access Attempt ---" << std::endl;
        std::cout << "Student Name (public): " << name << " (Accessible)" << std::endl;
        std::cout << "Student Address (protected): " << address << " (Accessible)" << std::endl;
        // This line would cause a semantic error if the syntax error was fixed.
        // std::cout << "Student Phone (private): " << phone << " (Inaccessible)" << std::endl;
        std::cout << "Student Phone (private): Access attempt omitted (would be Inaccessible)" << std::endl;
    }
};

void demonstrateNonMemberAccess(Person& p) {
    std::cout << "\n--- Non-Member Function Access Attempt ---" << std::endl;
    std::cout << "Non-member Name (public): " << p.name << " (Accessible)" << std::endl;
    // These lines would cause semantic errors if the syntax error was fixed.
    // std::cout << "Non-member Address (protected): " << p.address << " (Inaccessible)" << std::endl;
    // std::cout << "Non-member Phone (private): " << p.phone << " (Inaccessible)" << std::endl;
    std::cout << "Non-member Address (protected): Access attempt omitted (would be Inaccessible)" << std::endl;
    std::cout << "Non-member Phone (private): Access attempt omitted (would be Inaccessible)" << std::endl;
}

int main() {
    Student s("Alice Smith", "123 Main St", "555-1234");
    s.displayStudentInfo();
    demonstrateNonMemberAccess(s);
    return 0;
}