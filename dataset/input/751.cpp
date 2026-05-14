#include <iostream>
#include <iomanip>
using namespace std;

const int MONTHS = 3;
const int DAYS = 30;

void analyzeWeather(char weather[][DAYS]) {
    int totalR = 0, totalC = 0, totalS = 0;
    int maxRain = -1;
    int rainyMonth = -1;
    
    for (int i = 0; i < MONTHS; i++) {
        int r = 0, c = 0, s = 0;
        for (int j = 0; j < DAYS; j++) {
            if (weather[i][j] == 'R') r++;
            else if (weather[i][j] == 'C') c++;
            else if (weather[i][j] == 'S') s++;
        }
        cout << "Month " << i << ": R=" << r << " C=" << c << " S=" << s << endl;
        totalR += r;
        totalC += c;
        totalS += s;
        
        if (r > maxRain) {
            maxRain = r;
            rainyMonth = i;
        }
    }
    
    cout << "Total: R=" << totalR << " C=" << totalC << " S=" << totalS << endl;
    cout << "Month with most rain: " << rainyMonth << endl
} // Syntax Error: Missing semicolon

int main() {
    char weather[MONTHS][DAYS];
    // Initialize with dummy data
    for(int i=0; i<MONTHS; i++)
        for(int j=0; j<DAYS; j++)
            weather[i][j] = 'S';
            
    weather[0][0] = 'R'; // Just to have some rain
    
    analyzeWeather(weather);
    return 0;
}
