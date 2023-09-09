#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

int main(void) {
    std::vector<std::string> lines;

    std::string line;
    while (std::getline(std::cin, line)) lines.push_back(line);

    std::sort(lines.begin(), lines.end(), std::greater<std::string>());

    for (size_t i = 0; i < lines.size(); i++) std::cout << lines.at(i) << std::endl;

    return 0;
}
