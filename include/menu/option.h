#ifndef OPTION_H
#define OPTION_H

#pragma once

#include <functional>
#include <string>

class Option
{
public:
    Option(const char choice, const std::string &text, std::function<void()> action);

    char choice() const;
    std::function<void()> action() const;

    void render() const;
    void render(bool _) const;

private:
    char m_choice;
    std::string m_text;
    std::function<void()> m_action;
};

#endif