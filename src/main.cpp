#include <memory>
#include <string>

#include "controllers/moviecontroller.h"
#include "menu/menu.h"
#include "menu/option.h"
#include "util/filehandler.h"

std::unique_ptr<Menu> make_main_menu();
std::string db_filename();

std::string database_name {};

int main()
{
    database_name = db_filename();

    std::unique_ptr<Menu> main_menu = make_main_menu();
    char choice;

    do {
        main_menu->render();
        choice = main_menu->selection();
        
        if (choice != 'Q') {
            main_menu->invoke(choice);
        }
    } while (choice != 'Q');

    return 0;
}

std::unique_ptr<Menu> make_main_menu()
{
    std::unique_ptr<Menu> menu = std::make_unique<Menu>("Movie Database\n\nMain Menu", "Make your selection");

    menu->add_option(Option('A', "Add movie", []() {
        MovieController controller = MovieController();
        controller.add();
    }));
    menu->add_option(Option('E', "Edit Movie", []() {
        MovieController controller = MovieController();
        controller.edit();
    }));
    menu->add_option(Option('D', "Delete Movie", []() {
        MovieController controller;
        controller.remove();
    }));
    menu->add_option(Option('L', "List Movies", nullptr));
    menu->add_option(Option('Q', "Quit", nullptr));

    return menu;
}

std::string db_filename()
{
    const char *env_home = std::getenv("HOME");
    const std::string home = env_home != nullptr ? env_home : "/tmp";
    const std::string path = home + "/Documents/moviedb";
    const std::string filename = path + "/movies.dat";

    FileHandler::create_directories(path);
    FileHandler::create_data_file(filename);

    return filename;
}