#include <iostream>

// Base class
class MediaItem {
public:
    void play() { // SEMANTIC ERROR: Missing 'virtual' keyword. This prevents polymorphic behavior.
        std::cout << "Playing generic media item." << std::endl;
    }
};

// Derived class 1
class AudioFile : public MediaItem {
public:
    // This is an overload, not an override, because MediaItem::play() is not virtual
    void play() {
        std::cout << "Playing audio file." << std::endl;
    }
};

// Derived class 2
class VideoFile : public MediaItem {
public:
    // This is an overload, not an override, because MediaItem::play() is not virtual
    void play() {
        std::cout << "Playing video file." << std::endl;
    }
};

int main() {
    // Demonstrate the semantic error (incorrect method dispatch for base pointers)
    MediaItem* item1 = new AudioFile();
    MediaItem* item2 = new VideoFile();
    
    AudioFile directAudio;
    VideoFile directVideo;

    std::cout << "--- Direct calls to derived objects ---" << std::endl;
    directAudio.play(); // Calls AudioFile::play()
    directVideo.play(); // Calls VideoFile::play()

    std::cout << "--- Calls via base class pointers ---" << std::endl;
    // Due to missing 'virtual', this will call MediaItem::play() instead of the derived versions
    item1->play(); // Expected: "Playing audio file." Actual: "Playing generic media item."
    item2->play(); // Expected: "Playing video file." Actual: "Playing generic media item."

    // Object slicing example (also affected by lack of virtual, but behavior is expected for value copy)
    std::cout << "--- Object slicing (assignment to base by value) ---" << std::endl;
    MediaItem slicedItem = AudioFile();
    slicedItem.play(); // Always calls MediaItem::play() as 'slicedItem' is a MediaItem object

    delete item1;
    delete item2;

    return 0;
}