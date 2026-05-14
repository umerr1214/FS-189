#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

void capitalizeWords(char arr[]) {
    // Efficiency/Readability Issue: Using stringstream and vector for a simple in-place operation.
    // Allocates memory O(N) and creates copies.
    
    if (arr == nullptr) return;
    
    string s(arr);
    stringstream ss(s);
    string word;
    string result = "";
    
    while (ss >> word) {
        if (!word.empty()) {
            word[0] = toupper(word[0]);
            for (size_t i = 1; i < word.length(); i++) {
                word[i] = tolower(word[i]);
            }
            result += word + " ";
        }
    }
    
    // Note: this approach also modifies spaces (collapses multiple spaces to one), 
    // which might not be desired behavior for "capitalize words" which implies preserving structure.
    // And it adds a trailing space.
    if (!result.empty()) {
        result.pop_back(); // Remove trailing space
    }
    
    strcpy(arr, result.c_str());
}

int main() {
    char arr[100] = "hello   world";
    capitalizeWords(arr);
    // "Hello World" (spaces collapsed)
    cout << "Capitalized: " << arr << endl;
    return 0;
}
