#include <iostream>
#include <string>
#include <stdexcept>

class Song {
public:
    std::string title;
    std::string artist;

    Song(const std::string& title = "", const std::string& artist = "")
        : title(title), artist(artist) {}

    bool operator==(const Song& other) const {
        return title == other.title && artist == other.artist;
    }
    bool operator!=(const Song& other) const {
        return !(*this == other);
    }

    friend std::ostream& operator<<(std::ostream& os, const Song& song) {
        os << "\"" << song.title << "\" by " << song.artist;
        return os;
    }
};

class Playlist {
private:
    Song* s_arr; // Less descriptive name for readability issue
    int cnt;     // Less descriptive name for readability issue
    int cap;     // Less descriptive name for readability issue

    // Helper to resize array - always creates a new array of exact size
    void inefficientResize(int newCapacity) {
        if (newCapacity < 0) newCapacity = 0; // Handle negative capacity
        Song* newArr = new Song[newCapacity];
        for (int i = 0; i < cnt && i < newCapacity; ++i) {
            newArr[i] = s_arr[i];
        }
        delete[] s_arr;
        s_arr = newArr;
        cap = newCapacity;
        if (cnt > cap) cnt = cap; // Truncate if new capacity is smaller
    }

public:
    Playlist() : s_arr(nullptr), cnt(0), cap(0) {}

    // Destructor
    ~Playlist() {
        delete[] s_arr;
    }

    // Copy Constructor (correctly implemented to avoid robustness issue)
    Playlist(const Playlist& other) : s_arr(nullptr), cnt(0), cap(0) {
        if (other.cap > 0) {
            s_arr = new Song[other.cap];
            for (int i = 0; i < other.cnt; ++i) {
                s_arr[i] = other.s_arr[i];
            }
            cnt = other.cnt;
            cap = other.cap;
        }
    }

    // Copy Assignment Operator (correctly implemented to avoid robustness issue)
    Playlist& operator=(const Playlist& other) {
        if (this != &other) { // Self-assignment check
            delete[] s_arr; // Free old memory

            s_arr = nullptr;
            cnt = 0;
            cap = 0;

            if (other.cap > 0) {
                s_arr = new Song[other.cap];
                for (int i = 0; i < other.cnt; ++i) {
                    s_arr[i] = other.s_arr[i];
                }
                cnt = other.cnt;
                cap = other.cap;
            }
        }
        return *this;
    }

    // Inefficient addSong: always reallocates for exact size + 1
    void addSong(const Song& song) {
        inefficientResize(cnt + 1); // Always resize to exactly size + 1
        s_arr[cnt++] = song;
    }

    // Inefficient removeSong: always reallocates for exact size - 1
    void removeSong(const Song& song) {
        int indexToRemove = -1;
        for (int i = 0; i < cnt; ++i) {
            if (s_arr[i] == song) {
                indexToRemove = i;
                break;
            }
        }

        if (indexToRemove != -1) {
            // Create a new array and copy elements, skipping the one to remove
            Song* newArr = nullptr;
            int newCap = cnt - 1;
            if (newCap > 0) {
                newArr = new Song[newCap];
                for (int i = 0; i < indexToRemove; ++i) {
                    newArr[i] = s_arr[i];
                }
                for (int i = indexToRemove; i < cnt - 1; ++i) {
                    newArr[i] = s_arr[i + 1];
                }
            }
            delete[] s_arr;
            s_arr = newArr;
            cnt--;
            cap = newCap; // Capacity is always exactly the size
        }
    }

    void printPlaylist() const {
        std::cout << "Playlist:\n";
        if (cnt == 0) {
            std::cout << "(empty)\n";
            return;
        }
        for (int i = 0; i < cnt; ++i) {
            std::cout << s_arr[i] << "\n";
        }
    }
};

int main() {
    Playlist myPlaylist;
    std::string command, title, artist;

    while (std::cin >> command) {
        if (command == "add") {
            std::cin.ignore();
            std::getline(std::cin, title, ';');
            std::getline(std::cin, artist);
            myPlaylist.addSong(Song(title, artist));
        } else if (command == "remove") {
            std::cin.ignore();
            std::getline(std::cin, title, ';');
            std::getline(std::cin, artist);
            myPlaylist.removeSong(Song(title, artist));
        } else if (command == "print") {
            myPlaylist.printPlaylist();
        } else if (command == "copy_test") {
            Playlist copiedPlaylist = myPlaylist;
            std::cout << "Copied Playlist:\n";
            copiedPlaylist.printPlaylist();
        }
    }

    return 0;
}