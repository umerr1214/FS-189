#include <iostream>
#include <vector>
#include <memory>

class MediaItem {
public:
    virtual void play() {
        std::cout << "Playing generic media item." << std::endl;
    }
    virtual ~MediaItem() = default;
};

class AudioFile : public MediaItem {
public:
    void play() override {
        std::cout << "Playing audio file." << std::endl;
    }
};

class VideoFile : public MediaItem {
public:
    void play() override {
        std::cout << "Playing video file." << std::endl;
    }
} // Missing semicolon here

int main() {
    std::vector<std::unique_ptr<MediaItem>> mediaItems;
    mediaItems.push_back(std::make_unique<AudioFile>());
    mediaItems.push_back(std::make_unique<VideoFile>());

    for (const auto& item : mediaItems) {
        item->play();
    }

    return 0;
}