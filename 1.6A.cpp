#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>

bool check_password(const std::string &password);

bool has_lowercase(const std::string &str);
bool has_uppercase(const std::string &str);
bool has_digits(const std::string &str);
bool has_symbol(const std::string &str);

int main(void) {
    std::string password;
    std::cin >> password;

    std::cout << (check_password(password) ? "YES" : "NO") << std::endl;

    return 0;
}

bool check_password(const std::string &password) {
    size_t len = password.length();
    bool correct = (len >= 8 && len <= 14);

    size_t different_types = 0;
    if (correct) {
        different_types += has_lowercase(password);
        different_types += has_uppercase(password);
        different_types += has_digits(password);
        different_types += has_symbol(password);
    }

    return (correct && different_types >= 3);
}

bool has_lowercase(const std::string &str) {
    return std::find_if(str.begin(), str.end(), [](unsigned char c) { return ::islower(c); }) != str.end();
}

bool has_uppercase(const std::string &str) {
    return std::find_if(str.begin(), str.end(), [](unsigned char c) { return ::isupper(c); }) != str.end();
}

bool has_digits(const std::string &str) {
    return std::find_if(str.begin(), str.end(), [](unsigned char c) { return ::isdigit(c); }) != str.end();
}

bool has_symbol(const std::string &str) {
    return std::find_if(str.begin(), str.end(), [](unsigned char c) { return ::ispunct(c); }) != str.end();
}
