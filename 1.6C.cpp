#include <cstddef>
#include <iostream>
#include <vector>

int main(void) {
    size_t size = 0;
    std::cin >> size;

    std::vector<int> seats;
    seats.resize(size);

    for (size_t index = 0; index < size; index++) {
        size_t seat;
        std::cin >> seat;
        seats.at(seat - 1) = index;
    }

    for (size_t index = 0; index < size; index++) {
        std::cout << seats.at(index) + 1;
        if (index < size - 1) std::cout << ' ';
    }
    std::cout << std::endl;

    return 0;
}
