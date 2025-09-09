#ifndef TEXT_H
#define TEXT_H

#pragma once

#include <string>

class Text
{
public:
    static std::string spaces(int length, int taken);
    static std::string header_line();
};

#endif