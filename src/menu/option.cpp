//
// Created by richard on 25.08.2025 
//
#include "menu/option.h"
#include "view/output.h"
#include <functional>
#include <string>

Option::Option(const char choice, const std::string &text, std::function<void()> action) :
                m_choice {choice}, m_text {text}, m_action(action) {}

char Option::choice() const
{
    return m_choice;
}

std::function<void()> Option::action() const
{
    return m_action;
}

void Option::render() const
{
    std::string message;
    
    message.push_back(m_choice);
    message += ". " + m_text;
    Output::plain_text(message, true);
}

void Option::render(bool _) const
{
    std::string message;
    message.push_back(m_choice);
    message += ". " + m_text + ", ";

    Output::plain_text(message);
}