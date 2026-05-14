#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

void runLengthEncode(const char* input, char* output) {
    // Efficiency/Readability Issue: Building std::string by appending char by char
    // then copying back.
    // Heavy allocations for simple task.
    // Also, converting int to string using to_string is fine but repeated string additions are costly.
    
    if (input == nullptr) return;
    
    string s = "";
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        int count = 1;
        while (i < len - 1 && input[i] == input[i + 1]) {
            count++;
            i++;
        }
        s += input[i];
        s += to_string(count);
    }
    
    strcpy(output, s.c_str());
}

int main() {
    const char* str = "AAABBB";
    char result[100];
    runLengthEncode(str, result);
    cout << result << endl;
    return 0;
}
