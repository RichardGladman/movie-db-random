//
// Created by richard on 25.08.2025 
//
#include <iostream>
#include "view/input.h"
#include "view/output.h"
#include <ansicodes/ansicodes.h>
#include <cctype>
#include <limits>
#include <stdexcept>
#include <string>

std::string Input::get_text(const std::string &prompt, const int min_len, const std::string &default_value)
{
    std::string in {};

    do {
        Output::plain_text(prompt + ": ");
        std::getline(std::cin, in);

        if (min_len > 0 && in.length() < min_len) {
            Output::error_message("Error: input must be at least " + std::to_string(min_len) + "characters long");
        }
    } while (min_len > 0 && in.length() < min_len);

    return in.length() > 0 ? in : default_value;
}

int Input::get_integer(const std::string &prompt, const int default_value)
{
    int number {};

    Output::plain_text(prompt + ": ");
    std::cin >> number;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cin.clear();
    
    return number;
}

char Input::get_character(const std::string &prompt, const std::vector<char> values, const bool to_ucase)
{
    char ch {};
    bool valid = false;

    do {
        Output::plain_text(prompt, false);
        std::cin >> ch;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cin.clear();


        if (to_ucase) {
            ch = toupper(ch);
        }

        if (values.size() > 0) {
            for (const char &value: values) {
                if (ch == value) {
                    valid = true;
                    break;
                }
            }
            if (!valid) {
                Output::error_message("Invalid option. Please try again.");
            }
        } else {
            valid = true;
        }

    } while (!valid);


    return ch;
}
