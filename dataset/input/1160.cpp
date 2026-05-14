#include <iostream>
#include <string>
#include <vector> // Included but not used for the main collection, contributing to readability issue.

class MediaItem {
public:
    std::string mediaTitle; // Slightly less clear naming

    MediaItem(const std::string& t) : mediaTitle(t) {}

    virtual void play() { // Missing 'override' keyword
        std::cout << "--- Generic Media Playback ---\n";
        std::cout << "Now playing: " << mediaTitle << "\n";
        std::cout << "------------------------------\n";
    }

    virtual ~MediaItem() {
        // Correct virtual destructor
    }
};

class AudioFile : public MediaItem {
public:
    AudioFile(const std::string& title) : MediaItem(title) {}

    void play() { // Missing 'override' keyword
        std::cout << "--- Audio Playback Initiated ---\n";
        std::cout << "Playing audio: " << mediaTitle << "\n";
        std::cout << "Enjoy your music!\n"; // Slightly verbose output
        std::cout << "--------------------------------\n";
    }
};

class VideoFile : public MediaItem {
public:
    std::string videoFilename;

    VideoFile(const std::string& title, const std::string& filename) : MediaItem(title), videoFilename(filename) {}

    void play() { // Missing 'override' keyword
        std::string displayString = "Playing video: "; // Unnecessary intermediate string
        displayString += videoFilename;
        displayString += " (Title: ";
        displayString += mediaTitle;
        displayString += ")";
        std::cout << "--- Video Playback Initiated ---\n";
        std::cout << displayString << "\n"; // Slightly less efficient string concatenation for simple case
        std::cout << "Full screen recommended!\n"; // Slightly verbose output
        std::cout << "--------------------------------\n";
    }
};

int main() {
    // Using a C-style array with manual size tracking
    MediaItem* media_arr[4]; // Fixed size, potentially less flexible than std::vector
    int media_count = 0; // Manual count tracking

    media_arr[media_count++] = new AudioFile("Epic Soundtrack");
    media_arr[media_count++] = new VideoFile("Tutorial Series Part 1", "cpp_tutorial_p1.mp4");
    media_arr[media_count++] = new AudioFile("Morning Chill Mix");
    media_arr[media_count++] = new VideoFile("Travel Vlog - Japan", "japan_vlog.mov");

    std::cout << "===== Demonstrating Polymorphism =====\n";
    for (int i = 0; i < media_count; ++i) { // Manual loop count
        media_arr[i]->play();
    }
    std::cout << "======================================\n";

    // Clean up memory
    for (int i = 0; i < media_count; ++i) {
        delete media_arr[i];
    }

    return 0;
}