#include <iostream>
#include <string>

template <typename Container>
void Print(const Container& container, const std::string& separator) {
    for (auto it = container.begin(); it != container.end(); ++it) {
        if (it != container.begin()) std::cout << separator;
        std::cout << *it;
    }
    std::cout << '\n';
}

#include <vector>

int main(void) {
    std::vector<int> data = {1, 2, 3, 4};
    Print(data, ", ");
    return 0;
}
