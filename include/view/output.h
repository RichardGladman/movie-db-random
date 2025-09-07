#ifndef OUTPUT_H
#define OUTPUT_H

#pragma once

#include <string>

class Output
{
public:
    static void error_message(const std::string &message);
    static void success_message(const std::string &message);
    static void plain_text(const std::string &message, const bool new_line = false);
};

#endif