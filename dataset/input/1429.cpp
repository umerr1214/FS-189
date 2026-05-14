#include <iostream>

// Base class MediaItem with a non-virtual destructor, a robustness issue.
// If a derived object is deleted via a base class pointer, only the base
// class destructor will be called, leading to potential memory leaks or
// undefined behavior if derived classes have specific cleanup logic.
class MediaItem {
public:
    // Non-virtual destructor - THIS IS THE ROBUSTNESS ISSUE
    ~MediaItem() {
        std::cout << "MediaItem destructor called.\n";
    }

    // Virtual play method to allow polymorphism for playback
    virtual void play() {
        std::cout << "Playing a generic media item.\n";
    }
};

// Derived class AudioFile
class AudioFile : public MediaItem {
public:
    // Specific destructor for AudioFile
    ~AudioFile() {
        std::cout << "AudioFile destructor called.\n";
    }

    // Override play method for audio files
    void play() override {
        std::cout << "Playing an audio file.\n";
    }
};

// Derived class VideoFile
class VideoFile : public MediaItem {
public:
    // Specific destructor for VideoFile
    ~VideoFile() {
        std::cout << "VideoFile destructor called.\n";
    }

    // Override play method for video files
    void play() override {
        std::cout << "Playing a video file.\n";
    }
};

// Function containing the solution logic to be tested by the driver
void test_solution() {
    std::cout << "--- Demonstrating Robustness Issue (Missing Virtual Destructor) ---\n";

    // Dynamically allocate objects and store them in base class pointers
    MediaItem* item1 = new MediaItem();
    MediaItem* item2 = new AudioFile();
    MediaItem* item3 = new VideoFile();

    // Call play() method polymorphically
    item1->play();
    item2->play();
    item3->play();

    std::cout << "\n--- Deleting objects ---\n";
    // Deleting via base pointers.
    // For item2 and item3, only MediaItem's destructor will be called,
    // NOT AudioFile's or VideoFile's, leading to resource leaks if they
    // held specific resources.
    delete item1;
    delete item2; // Problematic delete for AudioFile
    delete item3; // Problematic delete for VideoFile

    std::cout << "--- End of demonstration ---\n";
}

int main() {
    test_solution(); // Execute the solution logic
    return 0;
}