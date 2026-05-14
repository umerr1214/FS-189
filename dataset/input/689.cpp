#include <iostream>
#include <cstring>
#include <string>
using namespace std;

void replaceSubstring(char arr[], const char target[], const char replacement[]) {
    // Efficiency/Readability Issue: Converting C-strings to std::string and back
    // using `find` and `replace` in a loop.
    // While readable (C++ style), it involves multiple allocations/copies and O(N) operations repeatedly
    // (replace in string is O(N), so loop makes it O(N^2)).
    // And copying back to arr is potentially unsafe if it grew.
    
    string s = arr;
    string t = target;
    string r = replacement;
    
    size_t pos = 0;
    while ((pos = s.find(t, pos)) != string::npos) {
        s.replace(pos, t.length(), r);
        pos += r.length();
    }
    
    strcpy(arr, s.c_str()); // Unsafe copy if s became larger than arr's capacity
}

int main() {
    char arr[100] = "hello world";
    replaceSubstring(arr, "world", "universe");
    cout << "Result: " << arr << endl;
    return 0;
}
