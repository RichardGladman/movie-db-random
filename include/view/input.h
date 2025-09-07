#ifndef INPUT_H
#define INPUT_H

#include <vector>
#pragma once

#include <string>

class Input
{
public:
    static std::string get_text(const std::string &prompt, const int min_len = 0, const std::string &default_value = "");
    static int get_integer(const std::string &prompt, const int default_value = 0);
    static char get_character(const std::string &prompt, const std::vector<char> values = {}, const bool to_ucase = false);
};

#endif