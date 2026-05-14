#include <string>
#include <iostream>

// Bad practice: Global 'using namespace std;' pollutes the global namespace.
using namespace std;

class Student {
private:
    int _id; // Cryptic and non-descriptive member variable name
    string _n; // Cryptic and non-descriptive member variable name
    string _m; // Cryptic and non-descriptive member variable name

public:
    // Constructor: Passes strings by value, causing unnecessary copies.
    // Also uses assignment instead of an initializer list, which can be less efficient.
    Student(int p_id, string p_n, string p_m) {
        // Inefficient: copies p_id, p_n, p_m into temporary variables, then assigns them.
        _id = p_id;
        _n = p_n;
        _m = p_m;
    }

    // Getter: Cryptic name. Returns int by value, which is fine.
    int get_id() const {
        return _id;
    }

    // Getter: Cryptic name. Returns string by value, causing unnecessary copies.
    string get_name() const {
        // Inefficient: Creates a temporary string 'temp_name' which is then copied again when returned.
        string temp_name = _n;
        return temp_name;
    }

    // Getter: Cryptic name. Returns string by value, causing unnecessary copies.
    string get_major() const {
        return _m;
    }
};

int main() {
    // Create student objects using the constructor with pass-by-value strings
    Student s1(202, "Bob Johnson", "Physics");
    Student s2(203, "Charlie Brown", "Art History");

    // Print details for s1 using inefficient getters and std::endl
    cout << "Student ID: " << s1.get_id() << endl; // Using std::endl flushes buffer unnecessarily
    cout << "Name: " << s1.get_name() << endl;
    cout << "Major: " << s1.get_major() << endl;

    // Print details for s2
    cout << "\nStudent ID: " << s2.get_id() << endl;
    cout << "Name: " << s2.get_name() << endl;
    cout << "Major: " << s2.get_major() << endl;

    return 0;
}