#include <deque>
#include <iostream>

int main(void) {
    size_t N;
    std::cin >> N;
    std::deque<std::string> order;

    for (size_t i = 0; i < N; i++) {
        std::string input;
        std::string end;
        std::cin >> input >> end;
        end == "bottom" ? order.push_back(input) : order.push_front(input);
    }

    size_t M;
    std::cin >> M;
    for (size_t i = 0; i < M; i++) {
        size_t id = 0;
        std::cin >> id;
        std::cout << order.at(id - 1) << std::endl;
    }

    return 0;
}
