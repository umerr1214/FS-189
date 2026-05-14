#include <iostream>
#include <vector>
#include <memory>

class MediaItem {
public:
    // Logical Error: 'play' method is not virtual, preventing polymorphic behavior
    void play() {
        std::cout << "Playing generic media item." << std::endl;
    }
    virtual ~MediaItem() = default;
};

class AudioFile : public MediaItem {
public:
    void play() override { // This 'override' keyword is valid, but the method isn't truly overriding a virtual function
        std::cout << "Playing audio file." << std::endl;
    }
};

class VideoFile : public MediaItem {
public:
    void play() override { // Same here
        std::cout << "Playing video file." << std::endl;
    }
};

int main() {
    std::vector<std::unique_ptr<MediaItem>> mediaItems;
    mediaItems.push_back(std::make_unique<AudioFile>());
    mediaItems.push_back(std::make_unique<VideoFile>());

    for (const auto& item : mediaItems) {
        // Due to the logical error, this will call MediaItem::play()
        // instead of AudioFile::play() or VideoFile::play()
        item->play();
    }

    return 0;
}