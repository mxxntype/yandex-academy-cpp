#include <iostream>
#include <iterator>
#include <list>
#include <string>

enum Command { Down, Up, Cut, Paste, None };

void print_lines(const std::list<std::string>& file);
Command parse_command(const std::string& command_str);

int main(void) {
    std::list<std::string> file;

    // Read the file into a vector of strings until a blank line appears
    std::string line;
    while (std::getline(std::cin, line)) {
        if (line == "") break;
        file.push_back(line);
    }
    file.push_back("");

    // Read commands until EOF
    std::string command_str;
    std::string clipboard;
    auto cursor = file.begin();
    size_t cursor_n = 0;
    while (std::getline(std::cin, command_str)) {
        auto command = parse_command(command_str);
        switch (command) {
            case Down:
                if (cursor != std::next(file.end(), -1)) {
                    ++cursor_n;
                    std::advance(cursor, 1);
                }
                break;
            case Up:
                if (cursor != file.begin()) {
                    --cursor_n;
                    std::advance(cursor, -1);
                }
                break;
            case Cut:
                if (!cursor->empty()) {
                    clipboard = *cursor;
                    file.erase(cursor);
                    cursor = file.begin();
                    std::advance(cursor, cursor_n);
                }
                break;
            case Paste:
                if (!clipboard.empty()) {
                    file.insert(cursor, clipboard);
                    // std::advance(cursor, 1);
                    // ++cursor_n;
                }
                break;
            case None:
                break;
        }
    }

    print_lines(file);

    return 0;
}

void print_lines(const std::list<std::string>& file) {
    for (auto it = file.begin(); it != std::next(file.end(), -1); ++it) std::cout << *it << std::endl;
}

Command parse_command(const std::string& command_str) {
    Command result = None;
    if (command_str == "Down") result = Down;
    if (command_str == "Up") result = Up;
    if (command_str == "Ctrl+X") result = Cut;
    if (command_str == "Ctrl+V") result = Paste;
    return result;
}
