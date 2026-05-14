#include <iostream>
#include <vector>
#include <string>

// Base class MediaItem
class MediaItem {
public:
    virtual void play() = 0;
    // Logical Error: Destructor is not virtual.
    // When deleting derived objects through base pointers, this leads to undefined behavior
    // and potential resource leaks as derived class destructors may not be called.
    ~MediaItem() { // Missing 'virtual' keyword
        std::cout << "MediaItem destructor called." << std::endl;
    }
};

// Derived class AudioFile
class AudioFile : public MediaItem {
private:
    std::string title;
public:
    AudioFile(const std::string& t) : title(t) {}
    void play() override {
        std::cout << "Playing audio: " << title << std::endl;
    }
    ~AudioFile() {
        std::cout << "AudioFile destructor called for '" << title << "'." << std::endl;
    }
};

// Derived class VideoFile
class VideoFile : public MediaItem {
private:
    std::string filename;
public:
    VideoFile(const std::string& f) : filename(f) {}
    void play() override {
        std::cout << "Playing video: " << filename << std::endl;
    }
    ~VideoFile() {
        std::cout << "VideoFile destructor called for '" << filename << "'." << std::endl;
    }
};

int main() {
    std::vector<MediaItem*> mediaLibrary;
    mediaLibrary.push_back(new AudioFile("My Favorite Song"));
    mediaLibrary.push_back(new VideoFile("Holiday Movie.mp4"));
    mediaLibrary.push_back(new AudioFile("Background Music"));

    std::cout << "--- Playing media ---" << std::endl;
    for (MediaItem* item : mediaLibrary) {
        item->play();
    }
    std::cout << "--- Finished playing ---" << std::endl;

    std::cout << "--- Cleaning up ---" << std::endl;
    for (MediaItem* item : mediaLibrary) {
        delete item; // This will only call MediaItem's destructor, not derived ones.
    }
    std::cout << "--- Cleanup finished ---" << std::endl;

    return 0;
}