#include <iostream>
#include <chrono>
#include <thread>

constexpr size_t PAGE_SIZE = 4 * 1024; 

void memoryAccess(size_t totalMemoryBytes, unsigned int delayPages, char fillValue, bool write) {
    for (size_t offset = 0; offset < totalMemoryBytes; offset += PAGE_SIZE) {
        char* memory = new char[PAGE_SIZE];

        if (write) {
            for (size_t i = 0; i < PAGE_SIZE; ++i) {
                memory[i] = fillValue;
            }
        }
        else {
            volatile char readValue;
            for (size_t i = 0; i < PAGE_SIZE; ++i) {
                readValue = memory[i];
            }
        }

        if (offset % (delayPages * PAGE_SIZE) == 0) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }

    }
}

int main() {
    size_t totalMemoryMB;
    std::cout << "Enter total memory (MB): ";
    std::cin >> totalMemoryMB;

    unsigned int delayPages;
    std::cout << "Enter delay pages (each page is 4 KB): ";
    std::cin >> delayPages;

    char fillValue = 'A';

    char accessType;
    std::cout << "Enter access type (r for read or w for write): ";
    std::cin >> accessType;

    int write = (accessType == 'w');

    size_t totalMemoryBytes = totalMemoryMB * 1024 * 1024;

    std::cout << (write ? "Writing" : "Reading") << " data to/from memory..." << std::endl;
    memoryAccess(totalMemoryBytes, delayPages, fillValue, write);

    return 0;
}
