#include <cstddef>
#include <iostream>
#include <string>

int main(void) {
    std::string input;
    std::getline(std::cin, input);

    size_t whitespace_pos = input.find(' ');
    while (whitespace_pos != std::string::npos) {
        input.erase(whitespace_pos, 1);
        whitespace_pos = input.find(' ');
    }

    std::string reversed_input;
    for (size_t i = input.length(); i > 0; i--) reversed_input.push_back(input.at(i - 1));

    std::cout << (input == reversed_input ? "YES" : "NO") << std::endl;

    return 0;
}
