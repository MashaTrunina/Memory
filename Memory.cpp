#include <iostream>
#include <chrono>
#include <thread>
#include <cstring>

constexpr size_t PAGE_SIZE = 4 * 1024; // Размер страницы (4 КБ)

// Функция для доступа к памяти с указанным шагом и заполнением
void memoryAccess(size_t totalMemoryBytes, unsigned int delayPages, char fillValue) {
    for (size_t offset = 0; offset < totalMemoryBytes; offset += PAGE_SIZE) {
        char* memory = new char[PAGE_SIZE]; // Выделение памяти размером PAGE_SIZE

        // Заполнение выделенной памяти указанным значением
        std::memset(memory, fillValue, PAGE_SIZE);

        // Задержка через определенное количество страниц
        if (offset % (delayPages * PAGE_SIZE) == 0) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Задержка 100 миллисекунд
        }

        // Здесь может быть код для записи данных в память
        // Но в данном случае мы просто наполнили память указанным символом
        // Поскольку в этой версии кода требуется только запись, ничего дополнительно делать не нужно
    }
}

int main() {
    size_t totalMemoryMB;
    std::cout << "Enter total memory (MB): ";
    std::cin >> totalMemoryMB;

    unsigned int delayPages;
    std::cout << "Enter delay pages (each page is 4 KB): ";
    std::cin >> delayPages;

    char fillValue = 'A'; // Значение для заполнения памяти

    size_t totalMemoryBytes = totalMemoryMB * 1024 * 1024; // Перевод общего объема памяти из МБ в байты

    std::cout << "Writing data to memory..." << std::endl;
    memoryAccess(totalMemoryBytes, delayPages, fillValue);

    return 0;
}
