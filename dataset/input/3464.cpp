#include <iostream>
#include <string>

// Using namespace std globally for brevity (readability/maintainability concern)
using namespace std;

// Define the Student struct with non-descriptive member names
struct Student {
    string nm;  // Student name
    int idx;    // Student ID
    float scr;  // Student score
};

int main() {
    Student S; // Student variable with a short, non-descriptive name

    // Prompt for user input using excessive std::endl
    cout << "Enter student name: " << endl;
    cin >> S.nm; // Reads only one word for name

    cout << "Enter student ID: " << endl;
    cin >> S.idx;

    cout << "Enter student score: " << endl;
    cin >> S.scr;

    // Print student details using excessive std::endl
    cout << endl << "--- Student Details ---" << endl;
    cout << "Name: " << S.nm << endl;
    cout << "ID: " << S.idx << endl;
    cout << "Score: " << S.scr << endl;

    return 0;
}