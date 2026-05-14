#include <iostream> // For std::cout
#include <cstdio>   // For printf, used inconsistently

// Inconsistent and non-standard naming for the base class
class BaseM_Item_Cls {
public:
  // Inconsistent method naming and casing
    virtual void Play_Content_Func() {
        printf("Playing some generic content.\n"); // Mixing C-style I/O with C++-style
    }
};

// Inconsistent naming for derived class
class Audio_F : public BaseM_Item_Cls {
public:
  // Inconsistent indentation
  void Play_Content_Func() override { // Using 'override' but general style is poor
    std::cout << "Playing an audio file now." << std::endl; // Mixing C++-style I/O
  }
};

// Another derived class with bad naming and inconsistent style
class Video_F_Cls : public BaseM_Item_Cls {
public:
    void Play_Content_Func() override { // Using 'override'
        // Using a helper function for a simple print, adding unnecessary complexity
        _printVideoMessage_Internal();
    }
private:
    void _printVideoMessage_Internal() { // Non-standard naming for private helper
        std::cout << "Now playing the video file." << std::endl;
    }
};

int main() {
  using namespace std; // Unnecessary 'using namespace std;' in a function scope

    cout << "--- Testing Readability / Efficiency Issues ---" << endl;

    BaseM_Item_Cls* media1 = new Audio_F();
    BaseM_Item_Cls* media2 = new Video_F_Cls();

    media1->Play_Content_Func();
    media2->Play_Content_Func();

    delete media1;
    delete media2;

    cout << "--- End of test ---" << endl;

    return 0;
}