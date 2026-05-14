#include <iostream>
#include <vector>
#include <memory> // For the driver to show dynamic allocation

class MediaItem {
public:
    // Missing virtual destructor: This is the primary robustness issue.
    // If a derived object is deleted via a base class pointer,
    // only the base class destructor is guaranteed to be called,
    // leading to resource leaks if derived classes hold unique resources.
    MediaItem() = default;
    ~MediaItem() {
        std::cout << "MediaItem destructor called." << std::endl;
    }

    virtual void play() {
        std::cout << "Playing generic media item." << std::endl;
    }
};

class AudioFile : public MediaItem {
public:
    AudioFile() = default;
    ~AudioFile() {
        std::cout << "AudioFile destructor called." << std::endl;
    }

    // No 'override' keyword used, which is a minor robustness/maintainability issue.
    // If the base class signature changes, this might silently become a new function
    // instead of an override, breaking polymorphism.
    void play() {
        std::cout << "Playing audio file." << std::endl;
    }
};

class VideoFile : public MediaItem {
public:
    VideoFile() = default;
    ~VideoFile() {
        std::cout << "VideoFile destructor called." << std::endl;
    }

    // No 'override' keyword used.
    void play() {
        std::cout << "Playing video file." << std::endl;
    }
};

int main() {
    // Demonstrate the lack of virtual destructor in the base class.
    // When deleting via MediaItem*, only MediaItem's destructor is called.
    // AudioFile/VideoFile destructors are NOT called, leading to memory leaks
    // if they managed resources.
    std::cout << "--- Testing Robustness Issue (Missing Virtual Destructor) ---" << std::endl;

    MediaItem* item1 = new AudioFile();
    MediaItem* item2 = new VideoFile();

    item1->play();
    item2->play();

    std::cout << "Deleting item1 (AudioFile via MediaItem*)..." << std::endl;
    delete item1; // This will only call MediaItem's destructor
    std::cout << "Deleting item2 (VideoFile via MediaItem*)..." << std::endl;
    delete item2; // This will only call MediaItem's destructor

    std::cout << "--- End of test ---" << std::endl;

    // To show that derived destructors ARE called when objects are not deleted via base pointer
    std::cout << "\n--- Correct deletion (for comparison) ---" << std::endl;
    AudioFile af_direct; // Object created on stack
    VideoFile vf_direct; // Object created on stack
    af_direct.play();
    vf_direct.play();
    // Destructors called automatically when they go out of scope, in correct order
    std::cout << "--- Direct objects going out of scope ---" << std::endl;

    return 0;
}