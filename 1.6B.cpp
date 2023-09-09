#include <cstddef>
#include <iostream>
#include <string>

std::string soundex_code(const std::string &str);

int main(void) {
    std::string word;
    std::cin >> word;

    std::cout << soundex_code(word) << std::endl;

    return 0;
}

std::string soundex_code(const std::string &initial_str) {
    std::string soundex_code;
    soundex_code.push_back(initial_str.front());

    std::string excluded_chars = "aehiouwy";
    for (size_t i = 0; i < initial_str.length(); i++) {
        char c = initial_str.at(i);
        if (excluded_chars.find(c) == std::string::npos) {
            std::string code_1_chars = "bfpv";
            std::string code_2_chars = "cgjkqsxz";
            std::string code_3_chars = "dt";
            std::string code_4_chars = "l";
            std::string code_5_chars = "mn";
            std::string code_6_chars = "r";

            if (code_1_chars.find(c) != std::string::npos && soundex_code.back() != '1')
                soundex_code.push_back('1');
            if (code_2_chars.find(c) != std::string::npos && soundex_code.back() != '2')
                soundex_code.push_back('2');
            if (code_3_chars.find(c) != std::string::npos && soundex_code.back() != '3')
                soundex_code.push_back('3');
            if (code_4_chars.find(c) != std::string::npos && soundex_code.back() != '4')
                soundex_code.push_back('4');
            if (code_5_chars.find(c) != std::string::npos && soundex_code.back() != '5')
                soundex_code.push_back('5');
            if (code_6_chars.find(c) != std::string::npos && soundex_code.back() != '6')
                soundex_code.push_back('6');
        }
    }

    while (soundex_code.length() < 4) soundex_code.push_back('0');
    while (soundex_code.length() > 4) soundex_code.pop_back();

    return soundex_code;
}
