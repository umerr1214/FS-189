#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

void upperCase(char array[]) {
    // Efficiency/Readability Issue: Splitting into words using stringstream, modifying, then joining.
    // Heavy allocations O(N) compared to in-place O(1).
    
    if (array == nullptr) return;
    
    string s(array);
    stringstream ss(s);
    string word;
    string result = "";
    
    while (ss >> word) {
        if (!word.empty()) {
            word[0] = toupper(word[0]);
            word[word.length() - 1] = toupper(word[word.length() - 1]);
            result += word + " ";
        }
    }
    
    // Note: collapses spaces
    if (!result.empty()) {
        result.pop_back();
    }
    
    strcpy(array, result.c_str());
}

int main() {
    char arr[100] = "hello world";
    cout << "Before: " << arr << endl;
    upperCase(arr);
    cout << "After: " << arr << endl;
    return 0;
}
