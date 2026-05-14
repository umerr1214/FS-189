#include <iostream>
#include <cstring>
using namespace std;

bool isSubsequence(const char* s1, const char* s2) {
    int i = 0, j = 0;
    while (s1[i] != '\0' && s2[j] != '\0') {
        // Semantic Error: String literal comparison?
        // if (s1[i] == "a") // Error
        
        // Using assignment in condition.
        if (s1[i] = s2[j]) { // Assignment!
            // s1 is const char*, so this is compile error.
            // I need a semantic error that compiles.
            
            // Casting away const?
            // char* p1 = (char*)s1;
            // if (p1[i] = s2[j]) ...
            
            // Let's use pointer comparison again.
            // if (&s1[i] == &s2[j]) ...
            
            i++;
        }
        j++;
    }
    return s1[i] == '\0';
}

// Version that compiles with semantic error (by removing const or casting)
bool isSubsequence_Semantic(char* s1, char* s2) {
     int i = 0, j = 0;
    while (s1[i] != '\0' && s2[j] != '\0') {
        if (s1[i] = s2[j]) { // Semantic: Assignment, modifies s1, returns true if s2[j] != 0
            i++;
        }
        j++;
    }
    return s1[i] == '\0';
}

int main() {
    // Need mutable string for semantic test
    return 0;
}
