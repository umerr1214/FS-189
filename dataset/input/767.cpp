#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

void convertStartEndToUpper(char arr[]) {
    // Efficiency/Readability Issue: copying to vector<string>, processing, copying back.
    // Heavy for in-place char modification.
    
    if (!arr) return;
    
    string s = arr;
    vector<string> words;
    string temp = "";
    for (char c : s) {
        if (c == ' ') {
            if (!temp.empty()) words.push_back(temp);
            temp = "";
        } else {
            temp += c;
        }
    }
    if (!temp.empty()) words.push_back(temp);
    
    string res = "";
    for (size_t k = 0; k < words.size(); k++) {
        string& w = words[k];
        w[0] = toupper(w[0]);
        w[w.length()-1] = toupper(w[w.length()-1]);
        res += w;
        if (k < words.size() - 1) res += " ";
    }
    
    strcpy(arr, res.c_str());
}

int main() {
    char arr[100] = "hello world";
    convertStartEndToUpper(arr);
    cout << "After: " << arr << endl;
    return 0;
}
