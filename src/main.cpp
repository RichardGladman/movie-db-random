#include <string>

#include "util/filehandler.h"

std::string db_filename();

std::string database_name {};

int main()
{
    database_name = db_filename();

    return 0;
}

std::string db_filename()
{
    const char *env_home = std::getenv("HOME");
    const std::string home = env_home != nullptr ? env_home : "/tmp";
    const std::string path = home + "/Documents/moviedb";
    const std::string filename = path + "movies.dat";

    FileHandler::create_directories(path);
    FileHandler::create_data_file(filename);

    return filename;
}