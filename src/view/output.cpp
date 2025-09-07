#include <view/output.h>

#include <iostream>
#include <ansicodes/ansicodes.h>

void Output::error_message(const std::string &message)
{
    std::cout << ANSICodes::RED << message << ANSICodes::RESET << std::endl;
}

void Output::success_message(const std::string &message)
{
    std::cout << ANSICodes::GREEN << message << ANSICodes::RESET << std::endl;
}

void Output::plain_text(const std::string &message, const bool new_line)
{
    std::cout << message;
    if (new_line) {
        std::cout << std::endl;
    }
}
