//
// Created by richard on 25.08.2025 
//
#include "menu/menu.h"
#include "menu/option.h"
#include "view/input.h"
#include "view/output.h"
#include <functional>

Menu::Menu(const std::string &header, const std::string &prompt) :
            m_header {header}, m_prompt {prompt}, m_options {} {}

std::string Menu::header() const
{
    return m_header;
}

std::string Menu::prompt() const
{
    return m_prompt;
}

std::vector<Option> Menu::options() const
{
    return m_options;
}

void Menu::add_option(const Option &option)
{
    m_options.push_back(option);
}

void Menu::render() const
{
    Output::plain_text("\n" + m_header + "\n");

    for (const Option &option: m_options) {
        option.render();
    }
}

void Menu::render(bool _) const
{
    Output::plain_text(m_header + "\n\n");

    for (const Option &option: m_options) {
        option.render(false);
    }
}

char Menu::selection() const
{
    std::vector<char> valid_values {};

    for (const Option &option: m_options) {
        valid_values.push_back(option.choice());
    }

    return Input::get_character(m_prompt + ": ", valid_values, true);
}

void Menu::invoke(char choice) const
{
    for (const Option &option: m_options) {
        std::function<void()> func = option.action();
        if (option.choice() == choice && func != nullptr) {
            func();
            return;
        }
    }
}