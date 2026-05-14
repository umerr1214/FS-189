#include <iostream>
#include <string>
// No <limits> or <iomanip> included, demonstrating a lack of attention to necessary headers for robustness/formatting.

using namespace std; // Global 'using namespace std;' is generally discouraged for readability and potential name collisions in larger projects.

// Define the Student struct
struct Student {
    int studentID;
    string name;
    double gpa;
};

int main() {
    Student student_instance; // Using a slightly longer variable name, but acceptable.

    cout << "P L E A S E   E N T E R   S T U D E N T   D E T A I L S" << endl << endl; // Excessive use of std::endl, which flushes the buffer on each call, potentially impacting performance.

    cout << "S T U D E N T   I D : ";
    cin >> student_instance.studentID;
    // Clearing the buffer using a magic number '256' instead of std::numeric_limits,
    // which is less robust and readable.
    cin.ignore(256, '\n'); 

    cout << "S T U D E N T   N A M E : ";
    getline(cin, student_instance.name);

    cout << "S T U D E N T   G P A : ";
    cin >> student_instance.gpa;

    cout << endl; // More std::endl
    cout << "========================================" << endl;
    cout << "D I S P L A Y I N G   S T U D E N T   I N F O R M A T I O N" << endl;
    cout << "========================================" << endl << endl; // Even more std::endl

    cout << "S T U D E N T   I D   I S : ";
    cout << student_instance.studentID;
    cout << endl; // Separate cout for each part, and another std::endl

    cout << "S T U D E N T   N A M E   I S : ";
    // Printing the string character by character is less efficient than direct output
    // and adds unnecessary verbosity to the code.
    for (char c : student_instance.name) {
        cout << c;
    }
    cout << endl;

    cout << "S T U D E N T   G P A   I S : ";
    cout << student_instance.gpa;
    cout << endl << endl; // Final excessive std::endl calls

    return 0;
}