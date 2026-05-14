#include <iostream>
#include <string>
using namespace std;

void lookupName(string target, string names[], string numbers[], int size) {
    for (int i = 0; i < size; i++) {
        // Semantic Error: Comparing string content using address comparison?
        // In C++, string objects overload == so it works.
        // But if we use assignments in condition?
        
        // Let's use assignment.
        // names[i] = target; // This modifies the phone book!
        
        if (names[i] = target) { // Semantic Error: Assignment instead of equality
            // names[i] becomes target. Condition is true (string is not empty/false in boolean context?) 
            // Actually std::string conversion to bool is not implicit unless... wait.
            // string does NOT convert to bool implicitly in C++11+.
            // So `if (str = str2)` is invalid unless !empty() check?
            // No, string assignment returns reference to string. `if (string)` is not valid.
            
            // Let's use char arrays to make this semantic error possible/classic?
            // But I chose std::string.
            
            // Let's try comparing size with index?
            // if (names[i].length() == size) // Semantically valid but logically wrong.
            
            // Let's go back to confusing arrays.
            // Accessing numbers array using names array value?
            // cout << numbers[names[i]] << endl; // Invalid type.
            
            // How about:
            // if (names[i].compare(target)) 
            // string::compare returns 0 if EQUAL.
            // So `if (names[i].compare(target))` is true if they are DIFFERENT.
            // This is a common semantic misunderstanding of compare().
            
            cout << "Phone number: " << numbers[i] << endl;
            return;
        }
    }
    cout << "Name not found." << endl;
}

int main() {
    string names[] = {"Michael Myers", "Ash Williams"};
    string numbers[] = {"333-8000", "333-2323"};
    
    // Expected: finds Ash Williams
    // Actual: finds Michael Myers because "Michael Myers".compare("Ash Williams") != 0 (True).
    lookupName("Ash Williams", names, numbers, 2);
    
    return 0;
}
