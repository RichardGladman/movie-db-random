//
// Created by richard on 08.09.2025 
//
#include "util/text.h"

std::string Text::spaces(int length, int taken)
{
    std::string s {};

    for (int i=0; i<length-taken; ++i) {
        s += " ";
    }

    return s;
}

std::string Text::header_line()
{
    std::string line;

    for (int i=0; i<80; ++i) {
        line += "-";
    }

    return line;
}