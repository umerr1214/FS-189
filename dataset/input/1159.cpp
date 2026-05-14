#include <iostream>
#include <string>
#include <vector>

// Base class without a virtual destructor
class MediaItem {
public:
    std::string title;

    MediaItem(const std::string& t) : title(t) {}

    // Virtual function to be overridden
    virtual void play() {
        std::cout << "Playing generic media: " << title << std::endl;
    }

    // Missing virtual destructor - leads to undefined behavior/memory leak
    // if derived classes have their own resources and are deleted via base pointer.
    // ~MediaItem() {} // This is a non-virtual destructor.
};

class AudioFile : public MediaItem {
public:
    AudioFile(const std::string& title) : MediaItem(title) {}

    void play() override {
        std::cout << "Playing audio: " << title << std::endl;
    }
};

class VideoFile : public MediaItem {
public:
    std::string filename; // Using filename for video as per example

    VideoFile(const std::string& title, const std::string& filename) : MediaItem(title), filename(filename) {}

    void play() override {
        std::cout << "Playing video: " << filename << " (Title: " << title << ")" << std::endl;
    }
    // Imagine this class had a resource it allocated, e.g., a file handle
    // ~VideoFile() { std::cout << "VideoFile destructor called." << std::endl; }
    // If MediaItem's destructor isn't virtual, this won't be called when deleting via MediaItem*
};

int main() {
    // Using a C-style array for simplicity, but std::vector is also common
    MediaItem* mediaCollection[3];
    int count = 0;

    // Allocate objects dynamically
    mediaCollection[count++] = new AudioFile("My Favorite Song");
    mediaCollection[count++] = new VideoFile("Holiday Memories", "vacation_2023.mp4");
    mediaCollection[count++] = new AudioFile("Podcast Episode 1");

    std::cout << "--- Playing Media Collection ---" << std::endl;
    for (int i = 0; i < count; ++i) {
        mediaCollection[i]->play();
    }
    std::cout << "--------------------------------" << std::endl;

    // ROBUSTNESS ISSUE:
    // 1. No virtual destructor in MediaItem: If derived classes had resources,
    //    their destructors would not be called when deleting via MediaItem* leading to leaks/UB.
    // 2. Memory leak: Dynamically allocated objects are NOT deleted.
    //    This code intentionally omits 'delete mediaCollection[i];'

    return 0;
}