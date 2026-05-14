#include <iostream>
#include <vector>
#include <string>

// Base class MediaItem
class MediaItem {
public:
    // Semantic Error: The 'play' function is not declared virtual.
    // This breaks polymorphism. When called through a base class pointer,
    // MediaItem::play() will always be invoked instead of the derived versions.
    void play() { // Not virtual, not pure virtual
        std::cout << "Generic MediaItem play (This indicates a problem if called polymorphically)." << std::endl;
    }
    virtual ~MediaItem() { // Destructor is virtual, to prevent logical error from previous case.
        std::cout << "MediaItem destructor called." << std::endl;
    }
};

// Derived class AudioFile
class AudioFile : public MediaItem {
private:
    std::string title;
public:
    AudioFile(const std::string& t) : title(t) {}
    // This 'play' function hides MediaItem::play, it does not override it.
    void play() { // No 'override' keyword used, as base function is not virtual.
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
    // This 'play' function hides MediaItem::play, it does not override it.
    void play() { // No 'override' keyword used, as base function is not virtual.
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
        item->play(); // This will call MediaItem::play() for all items, not the derived ones.
    }
    std::cout << "--- Finished playing ---" << std::endl;

    std::cout << "--- Cleaning up ---" << std::endl;
    for (MediaItem* item : mediaLibrary) {
        delete item;
    }
    std::cout << "--- Cleanup finished ---" << std::endl;

    return 0;
}