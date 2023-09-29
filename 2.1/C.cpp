#include <deque>
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

void MakeTrain() {
    std::deque<int> train;
    std::string command;
    int W, N;
    while (std::cin >> command) {
        if (command == "+left") {
            std::cin >> W;
            train.push_front(W);
        } else if (command == "+right") {
            std::cin >> W;
            train.push_back(W);
        } else if (command == "-left") {
            std::cin >> N;
            for (int i = 0; i < N && !train.empty(); i++) train.pop_front();
        } else if (command == "-right") {
            std::cin >> N;
            for (int i = 0; i < N && !train.empty(); i++) train.pop_back();
        }
    }

    Print(train, " ");
}

int main(void) {
    MakeTrain();
    return 0;
}
