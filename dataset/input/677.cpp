#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;

void reverseWords(char arr[]) {
    // Efficiency/Readability Issue: Allocating extra memory (vector of strings)
    // and copying data back and forth instead of doing it in-place.
    // In-place is O(1) space, this is O(N) space.
    
    if (arr == nullptr) return;
    
    string s(arr);
    stringstream ss(s);
    string word;
    vector<string> words;
    
    while (ss >> word) {
        words.push_back(word);
    }
    
    reverse(words.begin(), words.end());
    
    string result = "";
    for (size_t i = 0; i < words.size(); i++) {
        result += words[i];
        if (i < words.size() - 1) {
            result += " ";
        }
    }
    
    strcpy(arr, result.c_str());
}

int main() {
    char arr[100] = "Hello World";
    reverseWords(arr);
    cout << "Reversed: " << arr << endl;
    return 0;
}
